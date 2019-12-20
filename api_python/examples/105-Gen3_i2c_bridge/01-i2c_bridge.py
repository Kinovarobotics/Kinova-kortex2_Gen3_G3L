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
# 105-Gen3_i2c_bridge/i2c_bridge.py
#
# Usage example for the I2C Expansion IO on the Gen3 Interconnect module.
#
# PHYSICAL SETUP:
# =========
#
# We used a I2C IO Extender PCA9505 for this example (https://www.nxp.com/docs/en/data-sheet/PCA9505_9506.pdf) and made the connections:
#    - SDA -------------- Pin 1
#    - SCL -------------- Pin 2
#    - DC --------------- Pins 18, 46, 86
#    - GND -------------- Pins 6, 11, 23, 27, 28, 29, 34, 39, 51
#
# DESCRIPTION OF CURRENT EXAMPLE:
# ===============================
# In this example, the I2C bridge class encapsulates all necessary Kortex API
# objects and implements the functions to setup the I2C, write to the bus and read from the bus.
# Upon a read request, the IO Extender supplies the input values read from the bank 0 pins (IO0_X pins from page 5 of the datasheet)
# The IO Extender can take configuration commands from write requests and the register values are supplied in the data sheet.
# 
# For this example, we first read the values of IO0_X pins, then invert the polarity on half of the pins and read them again.
# 
# The Init function creates the Kortex API objects and connects to the arm.
#
# The Configure function uses the appropriate RPC to activate the bridge with the desired settings.
# 
# The WriteValue function writes a request to the bus.
#
# The ReadValue function initiates a read request to the bus.
#
# The main function :
#   - Initializes the I2CBridge object
#   - Creates and sends a read request to read from the bank 0 pins on the IO Extender
#   - Creates and sends a write request to invert the polarity of half the bank 0 pins on the IO Extender
#   - Creates and sends a read request to read from the bank 0 pins on the IO Extender (which will not give the same output as the first request)
###

import sys
import os
import time

from kortex_api.autogen.client_stubs.DeviceManagerClientRpc import DeviceManagerClient
from kortex_api.autogen.client_stubs.InterconnectConfigClientRpc import InterconnectConfigClient

from kortex_api.autogen.messages import Common_pb2
from kortex_api.autogen.messages import InterconnectConfig_pb2

from kortex_api.Exceptions import KServerException

class I2CBridge:
    def __init__(self, router):
        '''
        Implements methods for establishing and operating I2C bridge through
        the base
        '''
        self.router = router
        
        # Create device manager client. Device manager is used get a list of devices present in the arm. In this example
        # we use device manager to determine the device ID associated with the interconnect.
        self.device_manager =  DeviceManagerClient(self.router)

        # Create interconnect configuration client. This client is used to perform I2C bus configuration and I2C bus actions.
        self.interconnect_config = InterconnectConfigClient(self.router)

        self.interconnect_device_id = self.GetDeviceIdFromDevType(Common_pb2.INTERCONNECT, 0)
        if (self.interconnect_device_id is None):
            print ("Could not find the Interconnect in the device list, exiting...")
            sys.exit(0)

    """
    GetDeviceIdFromDevType(devType, devIndex)

    Get device ID according to a given device type (Actuator or interconnect). 
    
    Inputs:
        devType :   Device type

    Index argument correspond to the position of the device (i.e.: 0 being the first,1 the second, etc.)
    """
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

    """
    WriteValue(device_address, data, timeout_ms)

    Writes a data array to I2C bus to a given device.

    inputs:
        device_address:  device's I2C address.
        data:            list containing data to write to device
        timeout_ms:      write operation timeout in milliseconds
    """
    def WriteValue(self, device_address, data, timeout_ms):
        i2c_write_parameter = InterconnectConfig_pb2.I2CWriteParameter()
        i2c_write_parameter.device = InterconnectConfig_pb2.I2C_DEVICE_EXPANSION
        i2c_write_parameter.device_address = device_address
        bytesData = bytes(data)
        i2c_write_parameter.data.data = bytesData
        i2c_write_parameter.data.size = len(bytesData)
        i2c_write_parameter.timeout = timeout_ms
        return self.interconnect_config.I2CWrite(i2c_write_parameter, deviceId=self.interconnect_device_id)

    """
    ReadValue(device_address, bytes_to_read, timeout_ms)

    Reads a data array from I2C bus from a given device.

    inputs:
        device_address:  device's I2C address.
        bytes_to_read:   number of bytes to read from device
        timeout_ms:      read operation timeout in milliseconds
    """

    def ReadValue(self, device_address, bytes_to_read, timeout_ms):

        # Create the I2C read request
        i2c_read_request = InterconnectConfig_pb2.I2CReadParameter()
        i2c_read_request.device = InterconnectConfig_pb2.I2C_DEVICE_EXPANSION
        i2c_read_request.device_address = device_address
        i2c_read_request.size = bytes_to_read
        i2c_read_request.timeout = timeout_ms

        # Read the data and print it
        read_result = self.interconnect_config.I2CRead(i2c_read_request, deviceId=self.interconnect_device_id)
        data = read_result.data
        print ("We were supposed to read {} bytes and we read {} bytes.".format(bytes_to_read, read_result.size))
        print ("The data is : {0:b}".format(ord(data)))

    """
    Configure(is_enabled, mode, addressing)

    Configure expansion bus I2C bus on interconnect.

    Inputs:
        is_enabled:    Enables i2cbus on interconnect's expansion bus if true, disable it otherwise.
        mode:       I2C mode in which the bus is set ( InterconnectConfig_pb2.I2C_MODE_STANDARD,  
                    InterconnectConfig_pb2.I2C_MODE_FAST or  InterconnectConfig_pb2.I2C_MODE_FAST_PLUS)
        addressing: Addressing size used on I2C bus (I2C_DEVICE_ADDRESSING_7_BITS or 
                    I2C_DEVICE_ADDRESSING_10_BITS).
    """
    def Configure(self, is_enabled, mode, addressing):

        # Create the configuration
        I2CConfiguration = InterconnectConfig_pb2.I2CConfiguration()
        I2CConfiguration.device = InterconnectConfig_pb2.I2C_DEVICE_EXPANSION
        I2CConfiguration.enabled = is_enabled
        I2CConfiguration.mode = mode
        I2CConfiguration.addressing = addressing

        # Set the configuration
        self.interconnect_config.SetI2CConfiguration(I2CConfiguration, deviceId=self.interconnect_device_id)

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

        # Create the gpio bridge object. It implements kortex methods used
        # configure and use interconnect's expansion I2C
        bridge = I2CBridge(router)

        # This has to match the device's slave address (see data sheet)
        slave_address = 0x20

        # Configure I2C bridge
        bridge.Configure(True, InterconnectConfig_pb2.I2C_MODE_FAST, InterconnectConfig_pb2.I2C_DEVICE_ADDRESSING_7_BITS)
        time.sleep(1)
        print ("I2C bridge object initialized")

        # Read the state of the pins in bank 0
        print ("Reading byte array from interconnect I2C bus...")
        try:
            bytes_to_read = 1
            bridge.ReadValue(slave_address, bytes_to_read, 100)
            time.sleep(0.5)
        except Exception as ex:
            print ("Error : {}".format(ex))
                
        # Send byte array to inverse polarity on half the pins
        print ("Sending byte array to interconnect I2C bus...")
        try:
            # By looking at the data sheet, we see that to write to the polarity register, 
            # we have to send command register 0x10 as the first byte, then our data byte
            buf = bytes([0x10, 0xAA])
            bridge.WriteValue(slave_address, buf, 100)
            time.sleep(0.5)
        except Exception as ex:
            print ("Error : {}".format(ex))

        # Read the state of the pins in bank 0
        # Half of them should be inverted now
        print ("Reading byte array from interconnect I2C bus...")
        try:
            bytes_to_read = 1
            bridge.ReadValue(slave_address, bytes_to_read, 100)
            time.sleep(0.5)
        except Exception as ex:
            print ("Error : {}".format(ex)) 

if __name__ == "__main__":
    main()