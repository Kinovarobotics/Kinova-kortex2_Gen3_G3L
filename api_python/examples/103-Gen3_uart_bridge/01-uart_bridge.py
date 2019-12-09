#! /usr/bin/env python3

###
# KINOVA (R) KORTEX (TM)
#
# Copyright (c) 2019 Kinova inc. All rights reserved.
#
# This software may be modified and distributed under the
# terms of the BSD 3-Clause license.
#
# Refer to the LICENSE file for details.
#
###

###
# 103-Gen3_uart_bridge/uart_bridge.py
#
# Usage example for the UART Expansion IO on the Gen3 Interconnect module.
#
# PHYSICAL SETUP:
# =========
# For this example to work, you will have to connect the RX and TX pins on the interconnect 
# IO Expansion pinout, so that the TX is transmitted right into the RX.
#
# DESCRIPTION OF CURRENT EXAMPLE:
# ===============================
# In this example, the UART bridge class encapsulates all necessary Kortex API
# objects and implements the functions to setup the UART, write to the bus and read back from it.
# 
# The Init function creates the Kortex API objects, connects to the arm and also calls InitSocket, 
# which correctly configures the socket (depending if you are on Windows or Linux).
#
# The Run function :
#   - Tells the Interconnect (m_interconnect_config object) to enable the UART bridge (this is where you supply the UART parameters)
#   - Tells the Base (m_base) to enable the UART bridge
#   - Opens the TCP socket to the base and writes the test string to the UART bridge
#   - Waits 10 seconds and prints every character it receives
#   - Tells the Base (m_base) to disable the UART bridge
#   - Tells the Interconenct (m_interconnect_config_object) to disable the UART bridge
###

import sys
import time
import os
import socket
import select

from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient
from kortex_api.autogen.client_stubs.DeviceManagerClientRpc import DeviceManagerClient
from kortex_api.autogen.client_stubs.InterconnectConfigClientRpc import InterconnectConfigClient

from kortex_api.autogen.messages import Base_pb2
from kortex_api.autogen.messages import Common_pb2
from kortex_api.autogen.messages import InterconnectConfig_pb2

class UARTBridge:

    def __init__(self, router, ip_address):

        self.router = router
        self.base_ip_address = ip_address

        # Create services
        self.base = BaseClient(self.router)
        self.device_manager =  DeviceManagerClient(self.router)
        self.interconnect_config = InterconnectConfigClient(self.router)

        self.interconnect_device_id = self.GetDeviceIdFromDevType(Common_pb2.INTERCONNECT, 0)
        if (self.interconnect_device_id is None):
            print ("Could not find the Interconnect in the device list, exiting...")
            sys.exit(0)

    def GetDeviceIdFromDevType(self, device_type, device_index = 0):
        devices = self.device_manager.ReadAllDevices()

        current_index = 0
        for device in devices.device_handle:
            if device.device_type == device_type:
                if current_index == device_index:
                    print ("Found the Interconnect on device identifier {}".format(device.device_identifier))
                    return device.device_identifier
                current_index += 1
        return None

    def Configure(self, port_id, enabled, speed, word_length, stop_bits, parity):
        '''
        Enable and configure UART on interconnect. This will open a TCP port on the interconnect. This
        port allows bridging TCP socket to UART.
        '''
        uart_config              = Common_pb2.UARTConfiguration()
        uart_config.port_id      = port_id 
        uart_config.enabled      = enabled # Setting enabled to true opens the TCP port dedicated to UART bridging. Setting this
                                           # field to false disables designated uart and closes the TCP port.
        uart_config.speed        = speed 
        uart_config.word_length  = word_length
        uart_config.stop_bits    = stop_bits
        uart_config.parity       = parity

        self.interconnect_config.SetUARTConfiguration(uart_config, deviceId=self.interconnect_device_id)

    def EnableBridge(self, bridge_type, target = 0, output = 0):
        
        # Create bridge configuration
        bridge_config = Base_pb2.BridgeConfig()
        bridge_config.device_identifier = self.interconnect_device_id
        bridge_config.bridgetype = bridge_type

        # If either target or ouput port has valid port value, add port config to bridge configuration
        if target or output:
            bridge_config.port_config.target_port = 0
            bridge_config.port_config.out_port = 0
            if target:
                bridge_config.port_config.target_port = target
            if output:
                bridge_config.port_config.out_port = output

        # Send the configuration and return the result
        bridge_result = self.base.EnableBridge(bridge_config)
        return bridge_result

    def DisableBridge(self, bridge_id):
        return self.base.DisableBridge(bridge_id)

    def ExampleSendDataAndReadItBack(self):

        # Enable port bridging on base.
        bridge_result = self.EnableBridge(Base_pb2.BRIDGE_TYPE_UART)
        bridge_id = bridge_result.bridge_id
        if bridge_result.status != Base_pb2.BRIDGE_STATUS_OK:
            print("Error creating bridge on base, exiting...")
            return

        # Get created bridge's configuration.
        bridge_config       = self.base.GetBridgeConfig(bridge_id)
        base_port           = bridge_config.port_config.out_port
        interconnect_port   = bridge_config.port_config.target_port
        print("UARTBridge ID # %i created between Interconnect (dev# %i)'s port #%i and external port #%i"%(bridge_id.bridge_id, self.interconnect_device_id, interconnect_port, base_port))

        # Open a socket to base's forwarded port.
        client_socket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect((self.base_ip_address, base_port))
        client_socket.setblocking(0)

        print ("UART bridge object initialized")

        # Send data to be written on UART using TCP connection.
        client_socket.send(b"This data is being written on Interconnect's expansion port UART\n")

        # Wait for data to be received from UART
        print("Waiting 10 seconds for data from uart...")
        sys.stdout.write("Received data : ")
        sys.stdout.flush()
        startTime = time.time()
        while time.time() - startTime < 10:
            readready, _, _  = select.select([client_socket], [], [], 1)
            if readready:
                data = client_socket.recv(1)
                if len(data):
                    sys.stdout.write(data.decode("utf-8"))
                    sys.stdout.flush()

        # Disconnect client socket.
        client_socket.close()

        # Disable bridge on base.
        self.DisableBridge(bridge_id)

def main():

    # Import the utilities helper module
    import argparse
    sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
    import utilities

    # Parse arguments
    parser = argparse.ArgumentParser()
    args = utilities.parseConnectionArguments(parser)

    # Create connection to the device and get the router
    with utilities.DeviceConnection.createTcpConnection(args) as router:

        # Create the bridge object. UARTBridge object implements kortex methods used
        # to create a TCP port bridge (port forwarding) between a port opened
        # on external adapter and the port opened on the interconnect.
        bridge = UARTBridge(router, args.ip)

        # Configure the expansion IO
        bridge.Configure(InterconnectConfig_pb2.UART_PORT_EXPANSION, True, Common_pb2.UART_SPEED_115200, Common_pb2.UART_WORD_LENGTH_8, Common_pb2.UART_STOP_BITS_1, Common_pb2.UART_PARITY_NONE)
        time.sleep(1)

        # Example core        
        bridge.ExampleSendDataAndReadItBack()

        # Disable bridge on interconnect
        bridge.Configure(InterconnectConfig_pb2.UART_PORT_EXPANSION, False, Common_pb2.UART_SPEED_115200, Common_pb2.UART_WORD_LENGTH_8, Common_pb2.UART_STOP_BITS_1, Common_pb2.UART_PARITY_NONE)
        
"""
This example will configure uart and activate uart to TCP socket bridge  on the arm's interconnect. It will also activate
TCP port bridge (port forwarding) to allow accessing the opened TCP port on the interconnect from outside the arm.
Once uart bridge is configured, it will send a string to write on UART port and then will wait for 10 seconds for data to
be entered on the same serial port. Whenever a character is received from UART it is written on stdout.
"""
if __name__ == "__main__":
    main()
