#! /usr/bin/env python3

###
# KINOVA (R) KORTEX (TM)
#
# Copyright (c) 2021 Kinova inc. All rights reserved.
#
# This software may be modified and distributed
# under the under the terms of the BSD 3-Clause license.
#
# Refer to the LICENSE file for details.
#
###

from pymodbus.constants import Endian
from pymodbus.payload import BinaryPayloadDecoder
from pymodbus.payload import BinaryPayloadBuilder
from pymodbus.client.sync import ModbusTcpClient

from math import isclose

# Default modbus port.
PORT = 502

# IP address of the robot that holds the modbus slave.
IP_ADDRESS = '192.168.1.10'

# Holding registers address to set a Cartesian command.
X_COMMAND_ADDRESS = 204
Y_COMMAND_ADDRESS = 206
Z_COMMAND_ADDRESS = 208
THETA_X_COMMAND_ADDRESS = 210
THETA_Y_COMMAND_ADDRESS = 212
THETA_Z_COMMAND_ADDRESS = 214

ACTION_CONTROL_ADDRESS = 200
MOVE_TYPE_ADDRESS = 202
MOVE_TYPE_CARTESIAN = 2

# Holding registers address to read the TCP(Tool Center Position) position.
TCP_X_ADDRESS = 104
TCP_Y_ADDRESS = 106
TCP_Z_ADDRESS = 108
TCP_THETA_X_ADDRESS = 110
TCP_THETA_Y_ADDRESS = 112
TCP_THETA_Z_ADDRESS = 114

# Input register address for every joint's position.
JOINT_1_ADDRESS = 34
JOINT_2_ADDRESS = 36
JOINT_3_ADDRESS = 38
JOINT_4_ADDRESS = 40
JOINT_5_ADDRESS = 42
JOINT_6_ADDRESS = 44

# Holding registers address to use the Action system.
NO_ACTION = 0
ACTION_START = 1
ACTION_STOP = 2

# Input register address to read the robot's current.
ARM_CURRENT_ADDRESS = 6

# Input register address to read the robot's voltage.
ARM_VOLTAGE_ADDRESS = 8


def read_two_input_registers_to_one_float(client: ModbusTcpClient, address: int):
    output = client.read_input_registers(address, 2)
    registers = output.registers

    decoder = BinaryPayloadDecoder.fromRegisters(registers,
                                                 byteorder=Endian.Big,
                                                 wordorder=Endian.Little)
    return decoder.decode_32bit_float()


def write_uint16_to_one_register(client: ModbusTcpClient,
                                 number: float or int,
                                 address: int):
    builder = BinaryPayloadBuilder(byteorder=Endian.Big,
                                   wordorder=Endian.Little)
    builder.add_16bit_uint(number)
    registers = builder.to_registers()
    client.write_registers(address, registers)


def write_float_to_two_registers(client: ModbusTcpClient,
                                 number: int or float,
                                 address: int):
    builder = BinaryPayloadBuilder(byteorder=Endian.Big,
                                   wordorder=Endian.Little)
    builder.add_32bit_float(number)
    registers = builder.to_registers()
    client.write_registers(address, registers)


def example_read_current_voltage():
    '''
    This function initiate a modbus connection with the robot and read the current and the voltage.
    '''

    # Set-up
    # instantiate modbus client connection
    client = ModbusTcpClient(IP_ADDRESS, PORT)
    assert client.connect(), "Unable to connect to the slave"

    modbus_current = read_two_input_registers_to_one_float(
        client, ARM_CURRENT_ADDRESS)
    modbus_voltage = read_two_input_registers_to_one_float(
        client, ARM_VOLTAGE_ADDRESS)

    print('Robot current: {} A'.format(modbus_current))
    print('Robot voltage: {} V'.format(modbus_voltage))

    client.close()


def example_read_joints_position():
    '''
    This function initiate a modbus connection with the robot and read the position of every joint.
    '''

    # Set-up
    # instantiate modbus client connection
    client = ModbusTcpClient(IP_ADDRESS, PORT)
    assert client.connect(), "Unable to connect to the slave"

    joint1_position = read_two_input_registers_to_one_float(client, JOINT_1_ADDRESS)
    joint2_position = read_two_input_registers_to_one_float(client, JOINT_2_ADDRESS)
    joint3_position = read_two_input_registers_to_one_float(client, JOINT_3_ADDRESS)
    joint4_position = read_two_input_registers_to_one_float(client, JOINT_4_ADDRESS)
    joint5_position = read_two_input_registers_to_one_float(client, JOINT_5_ADDRESS)
    joint6_position = read_two_input_registers_to_one_float(client, JOINT_6_ADDRESS)

    print('Joint 1 position: {:.2f} degrees'.format(joint1_position))
    print('Joint 2 position: {:.2f} degrees'.format(joint2_position))
    print('Joint 3 position: {:.2f} degrees'.format(joint3_position))
    print('Joint 4 position: {:.2f} degrees'.format(joint4_position))
    print('Joint 5 position: {:.2f} degrees'.format(joint5_position))
    print('Joint 6 position: {:.2f} degrees'.format(joint6_position))

    client.close()


def example_read_TCP():
    '''
    This function initiate a modbus connection with the robot and read the TCP(Tool Center Point) position.
    '''

    # Set-up
    # instantiate modbus client connection
    client = ModbusTcpClient(IP_ADDRESS, PORT)
    assert client.connect(), "Unable to connect to the slave"

    tcp_x = read_two_input_registers_to_one_float(client, TCP_X_ADDRESS)
    tcp_y = read_two_input_registers_to_one_float(client, TCP_Y_ADDRESS)
    tcp_z = read_two_input_registers_to_one_float(client, TCP_Z_ADDRESS)

    tcp_theta_x = read_two_input_registers_to_one_float(client, TCP_THETA_X_ADDRESS)
    tcp_theta_y = read_two_input_registers_to_one_float(client, TCP_THETA_Y_ADDRESS)
    tcp_theta_z = read_two_input_registers_to_one_float(client, TCP_THETA_Z_ADDRESS)

    print('TCP x: {:.2f}m'.format(tcp_x))
    print('TCP y: {:.2f}m'.format(tcp_y))
    print('TCP z: {:.2f}m'.format(tcp_z))
    print('TCP theta x: {:.2f} degrees'.format(tcp_theta_x))
    print('TCP theta y: {:.2f} degrees'.format(tcp_theta_y))
    print('TCP theta z: {:.2f} degrees'.format(tcp_theta_z))

    client.close()


def example_move():
    '''
    This function initiate a modbus connection with the robot and reach 2 Cartesian positions.
    '''

    # Set-up
    # instantiate modbus client connection
    client = ModbusTcpClient(IP_ADDRESS, PORT)
    assert client.connect(), "Unable to connect to the slave"

    tcp_x = read_two_input_registers_to_one_float(client, TCP_X_ADDRESS)
    tcp_y = read_two_input_registers_to_one_float(client, TCP_Y_ADDRESS)
    tcp_z = read_two_input_registers_to_one_float(client, TCP_Z_ADDRESS)

    tcp_theta_x = read_two_input_registers_to_one_float(client, TCP_THETA_X_ADDRESS)
    tcp_theta_y = read_two_input_registers_to_one_float(client, TCP_THETA_Y_ADDRESS)
    tcp_theta_z = read_two_input_registers_to_one_float(client, TCP_THETA_Z_ADDRESS)

    # First position we want to reach.
    TARGET_1_X = tcp_x
    TARGET_1_Y = tcp_y
    TARGET_1_Z = tcp_z + 0.2
    TARGET_1_THETA_X = tcp_theta_x
    TARGET_1_THETA_Y = tcp_theta_y
    TARGET_1_THETA_Z = tcp_theta_z

    # Second position we want to reach.
    TARGET_2_X = tcp_x
    TARGET_2_Y = tcp_y
    TARGET_2_Z = tcp_z
    TARGET_2_THETA_X = tcp_theta_x
    TARGET_2_THETA_Y = tcp_theta_y
    TARGET_2_THETA_Z = tcp_theta_z

    TRANSLATION_TOLERENCE = 0.02
    ORIENTATION_TOLERENCE = 1

    # Initialize the control register.
    write_uint16_to_one_register(client, NO_ACTION, ACTION_CONTROL_ADDRESS)

    # Set the type of action to Cartesian.
    write_uint16_to_one_register(client, MOVE_TYPE_CARTESIAN, MOVE_TYPE_ADDRESS)

    # Send the Cartesian coordinates of the first position.
    write_float_to_two_registers(client, TARGET_1_X, X_COMMAND_ADDRESS)
    write_float_to_two_registers(client, TARGET_1_Y, Y_COMMAND_ADDRESS)
    write_float_to_two_registers(client, TARGET_1_Z, Z_COMMAND_ADDRESS)
    write_float_to_two_registers(client, TARGET_1_THETA_X, THETA_X_COMMAND_ADDRESS)
    write_float_to_two_registers(client, TARGET_1_THETA_Y, THETA_Y_COMMAND_ADDRESS)
    write_float_to_two_registers(client, TARGET_1_THETA_Z, THETA_Z_COMMAND_ADDRESS)

    # Start the action
    print('Sending the first position')
    write_uint16_to_one_register(client, ACTION_START, ACTION_CONTROL_ADDRESS)

    target_reached = False

    # While the target has not been reached we monitor the position
    while(not target_reached):
        tcp_x = read_two_input_registers_to_one_float(client, TCP_X_ADDRESS)
        tcp_y = read_two_input_registers_to_one_float(client, TCP_Y_ADDRESS)
        tcp_z = read_two_input_registers_to_one_float(client, TCP_Z_ADDRESS)

        tcp_theta_x = read_two_input_registers_to_one_float(client, TCP_THETA_X_ADDRESS)
        tcp_theta_y = read_two_input_registers_to_one_float(client, TCP_THETA_Y_ADDRESS)
        tcp_theta_z = read_two_input_registers_to_one_float(client, TCP_THETA_Z_ADDRESS)

        # If we have reached our target we stop the monitoring
        if (isclose(tcp_x, TARGET_1_X, abs_tol = TRANSLATION_TOLERENCE) and isclose(tcp_y, TARGET_1_Y, abs_tol = TRANSLATION_TOLERENCE) and 
            isclose(tcp_z, TARGET_1_Z, abs_tol = TRANSLATION_TOLERENCE) and isclose(tcp_theta_x, TARGET_1_THETA_X, abs_tol = ORIENTATION_TOLERENCE) and 
            isclose(tcp_theta_y, TARGET_1_THETA_Y, abs_tol = ORIENTATION_TOLERENCE) and isclose(tcp_theta_z, TARGET_1_THETA_Z, abs_tol = ORIENTATION_TOLERENCE)):
            target_reached = True
            
            # Stop the action
            write_uint16_to_one_register(client, ACTION_STOP, ACTION_CONTROL_ADDRESS)
            print('First position reached')

    target_reached = False

    # Send the Cartesian coordinates of the second position. The type of action has already been set
    # above for the first position so we don't need to set it again.
    write_float_to_two_registers(client, TARGET_2_X, X_COMMAND_ADDRESS)
    write_float_to_two_registers(client, TARGET_2_Y, Y_COMMAND_ADDRESS)
    write_float_to_two_registers(client, TARGET_2_Z, Z_COMMAND_ADDRESS)
    write_float_to_two_registers(client, TARGET_2_THETA_X, THETA_X_COMMAND_ADDRESS)
    write_float_to_two_registers(client, TARGET_2_THETA_Y, THETA_Y_COMMAND_ADDRESS)
    write_float_to_two_registers(client, TARGET_2_THETA_Z, THETA_Z_COMMAND_ADDRESS)

    print('Sending the second position')
    write_uint16_to_one_register(client, ACTION_START, ACTION_CONTROL_ADDRESS)

    # While the target has not been reached we monitor the position
    while(not target_reached):
        tcp_x = read_two_input_registers_to_one_float(client, TCP_X_ADDRESS)
        tcp_y = read_two_input_registers_to_one_float(client, TCP_Y_ADDRESS)
        tcp_z = read_two_input_registers_to_one_float(client, TCP_Z_ADDRESS)

        tcp_theta_x = read_two_input_registers_to_one_float(client, TCP_THETA_X_ADDRESS)
        tcp_theta_y = read_two_input_registers_to_one_float(client, TCP_THETA_Y_ADDRESS)
        tcp_theta_z = read_two_input_registers_to_one_float(client, TCP_THETA_Z_ADDRESS)

        # If we have reached our target
        if (isclose(tcp_x, TARGET_2_X, abs_tol = TRANSLATION_TOLERENCE) and isclose(tcp_y, TARGET_2_Y, abs_tol = TRANSLATION_TOLERENCE) and 
            isclose(tcp_z, TARGET_2_Z, abs_tol = TRANSLATION_TOLERENCE) and isclose(tcp_theta_x, TARGET_2_THETA_X, abs_tol = ORIENTATION_TOLERENCE) and 
            isclose(tcp_theta_y, TARGET_2_THETA_Y, abs_tol = ORIENTATION_TOLERENCE) and isclose(tcp_theta_z, TARGET_2_THETA_Z, abs_tol = ORIENTATION_TOLERENCE)):
            target_reached = True
            
            # Stop the action
            write_uint16_to_one_register(client, ACTION_STOP, ACTION_CONTROL_ADDRESS)
            print('Second position reached')


    client.close()


def main():

    # Call example
    example_read_current_voltage()
    example_read_joints_position()
    example_read_TCP()
    example_move()


if __name__ == "__main__":
    main()
