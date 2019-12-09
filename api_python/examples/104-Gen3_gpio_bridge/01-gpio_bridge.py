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
# 104-Gen3_gpio_bridge/gpio_bridge.py
#
# Usage example for the GPIO Expansion IO on the Gen3 Interconnect module.
#
# PHYSICAL SETUP:
# =========
# For this example to work, you will have to :
#    - Connect the GPIO_IO1 and GPIO_IO2 Interconnect pins to two input digital pins on your micro-controller
#    - Connect the GPIO_IO3 and GPIO_IO4 Interconnect pins to two output digital pins on your micro-controller
#    - Modify the Arduino code so the ROBOT_PIN_X variables correspond to your pin numbers
#    - Power on the micro-controller and upload the arduino_gpio_example_firmware.ino
#
# We used a MSP432 Launchpad (http://www.ti.com/tool/MSP-EXP432P401R) and made the connections:
#    - GPIO_IO1 -------------- Pin 23
#    - GPIO_IO2 -------------- Pin 24
#    - GPIO_IO3 -------------- Pin 29
#    - GPIO_IO4 -------------- Pin 30
#
# You can also use any Arduino board and this example will work as long as you specify the right pin numbers in the Arduino code. 
#
# DESCRIPTION OF CURRENT EXAMPLE:
# ===============================
# In this example, the GPIO bridge class encapsulates all necessary Kortex API
# objects and implements the functions to setup the GPIO, write to two pins and read back from two other pins.
# The Arduino reads from GPIO_IO1 and writes to pin GPIO_IO3 and reads from GPIO_IO2 and writes to pin GPIO_IO4.
# Essentially, what is written on pin GPIO_IO1 is read back on pin GPIO_IO3 and the same applies for pins GPIO_IO2
# and GPIO_IO4. 
# 
# The Init function creates the Kortex API objects and connects to the arm.
#
# The InitGpioInputsAndOutputs function uses the appropriate RPCs to activate the bridge as well as setup the pins
# either as output (GPIO_IDENTIFIER_1 and GPIO_IDENTIFIER_2) or as input pullup (GPIO_IDENTIFIER_3 and GPIO_IDENTIFIER_4).
# 
# The SetOutputPinValue function writes a logical value to a designated output pin.
#
# The ReadInputPinValue function reads a logical value from a designated input pin.
#
# The ExampleSetAndReadValues function :
#   - Writes to pins GPIO_IO1 and GPIO_IO2
#   - Reads and prints the values read from GPIO_IO3 and GPIO_IO4
###

import sys
import os
import time

from kortex_api.autogen.client_stubs.DeviceManagerClientRpc import DeviceManagerClient
from kortex_api.autogen.client_stubs.InterconnectConfigClientRpc import InterconnectConfigClient

from kortex_api.autogen.messages import Common_pb2
from kortex_api.autogen.messages import InterconnectConfig_pb2

class GpioBridge:
    '''
    Implements methods for establishing and operating GPIO bridge through
    the base
    '''
    GpioEnum = (
        InterconnectConfig_pb2.GPIO_IDENTIFIER_1,
        InterconnectConfig_pb2.GPIO_IDENTIFIER_2,
        InterconnectConfig_pb2.GPIO_IDENTIFIER_3,
        InterconnectConfig_pb2.GPIO_IDENTIFIER_4
    )

    def __init__(self, router):
        
        self.router = router

        self.device_manager = DeviceManagerClient(self.router)
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

    def InitGpioInputsAndOutputs(self):
        gpio_config                  = InterconnectConfig_pb2.GPIOConfiguration()

        # Pins 1 and 2 as output
        gpio_config.mode             = InterconnectConfig_pb2.GPIO_MODE_OUTPUT_PUSH_PULL
        gpio_config.pull             = InterconnectConfig_pb2.GPIO_PULL_NONE
        gpio_config.default_value    = InterconnectConfig_pb2.GPIO_VALUE_LOW
        gpio_config.identifier       = InterconnectConfig_pb2.GPIO_IDENTIFIER_1
        print ("Setting pin #1 as output...")
        self.interconnect_config.SetGPIOConfiguration(gpio_config, deviceId=self.interconnect_device_id)
        time.sleep(1)
        gpio_config.identifier       = InterconnectConfig_pb2.GPIO_IDENTIFIER_2
        print ("Setting pin #2 as output...")        
        self.interconnect_config.SetGPIOConfiguration(gpio_config, deviceId=self.interconnect_device_id)
        time.sleep(1)

        # Pins 3 and 4 as input pullup
        gpio_config.mode             = InterconnectConfig_pb2.GPIO_MODE_INPUT_FLOATING
        gpio_config.pull             = InterconnectConfig_pb2.GPIO_PULL_UP
        gpio_config.identifier       = InterconnectConfig_pb2.GPIO_IDENTIFIER_3
        print ("Setting pin #3 as input pullup...")
        self.interconnect_config.SetGPIOConfiguration(gpio_config, deviceId=self.interconnect_device_id)
        time.sleep(1)
        gpio_config.identifier       = InterconnectConfig_pb2.GPIO_IDENTIFIER_4
        print ("Setting pin #4 as input pullup...")
        self.interconnect_config.SetGPIOConfiguration(gpio_config, deviceId=self.interconnect_device_id)
        time.sleep(1)

    def SetOutputPinValue(self, identifier, value):
        gpio_state = InterconnectConfig_pb2.GPIOState()
        gpio_state.identifier = identifier
        gpio_state.value = value
        print ("GPIO pin {} will be put at value {}".format(InterconnectConfig_pb2.GPIOIdentifier.Name(identifier), InterconnectConfig_pb2.GPIOValue.Name(value)))
        self.interconnect_config.SetGPIOState(gpio_state,deviceId=self.interconnect_device_id)
        
    def ReadInputPinValue(self, identifier):
        gpio_identification = InterconnectConfig_pb2.GPIOIdentification()
        gpio_identification.identifier = identifier
        state = self.interconnect_config.GetGPIOState(gpio_identification,deviceId=self.interconnect_device_id)
        if (state.value == InterconnectConfig_pb2.GPIO_VALUE_HIGH):
            return 1
        elif (state.value == InterconnectConfig_pb2.GPIO_VALUE_LOW):
            return 0
        else:
            print ("Error : the value read is unspecified")
            return -1

    def ExampleSetAndReadValues(self):
        # We sleep a bit between the reads and the writes
        # Technically the InterconnectConfig service runs at 25ms but we sleep 100ms to make sure we let enough time
        sleep_time_sec = 0.1

        # The Arduino reads pin 1 and sets pin 3 the same
        # The Arduino reads pin 2 and sets pin 4 the same
        self.SetOutputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_1, InterconnectConfig_pb2.GPIO_VALUE_HIGH)
        self.SetOutputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_2, InterconnectConfig_pb2.GPIO_VALUE_LOW)
        time.sleep(sleep_time_sec)
        pin3_in = self.ReadInputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_3) # should be HIGH
        pin4_in = self.ReadInputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_4) # should be LOW
        print ("Value read for pin #3 is : {}".format(pin3_in))
        print ("Value read for pin #4 is : {}".format(pin4_in))

        self.SetOutputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_1, InterconnectConfig_pb2.GPIO_VALUE_LOW)
        self.SetOutputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_2, InterconnectConfig_pb2.GPIO_VALUE_HIGH)
        time.sleep(sleep_time_sec)
        pin3_in = self.ReadInputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_3) # should be LOW
        pin4_in = self.ReadInputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_4) # should be HIGH
        print ("Value read for pin #3 is : {}".format(pin3_in))
        print ("Value read for pin #4 is : {}".format(pin4_in))

        self.SetOutputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_1, InterconnectConfig_pb2.GPIO_VALUE_HIGH)
        self.SetOutputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_2, InterconnectConfig_pb2.GPIO_VALUE_HIGH)
        time.sleep(sleep_time_sec)
        pin3_in = self.ReadInputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_3) # should be HIGH
        pin4_in = self.ReadInputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_4) # should be HIGH
        print ("Value read for pin #3 is : {}".format(pin3_in))
        print ("Value read for pin #4 is : {}".format(pin4_in))

        self.SetOutputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_1, InterconnectConfig_pb2.GPIO_VALUE_LOW)
        self.SetOutputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_2, InterconnectConfig_pb2.GPIO_VALUE_LOW)
        time.sleep(sleep_time_sec)
        pin3_in = self.ReadInputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_3) # should be LOW
        pin4_in = self.ReadInputPinValue(InterconnectConfig_pb2.GPIO_IDENTIFIER_4) # should be LOW
        print ("Value read for pin #3 is : {}".format(pin3_in))
        print ("Value read for pin #4 is : {}".format(pin4_in))

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
        # configure and use interconnect's expansion GPIO
        bridge = GpioBridge(router)

        # Configure all interconnect's GPIO as push pull outputs
        bridge.InitGpioInputsAndOutputs()
        print ("GPIO bridge object initialized")

        # Example core
        bridge.ExampleSetAndReadValues()        

if __name__ == "__main__":
    main()
