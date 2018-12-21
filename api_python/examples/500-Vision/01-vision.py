#! /usr/bin/env python3

###
# KINOVA (R) KORTEX (TM)
#
# Copyright (c) 2018 Kinova inc. All rights reserved.
#
# This software may be modified and distributed
# under the terms of the BSD 3-Clause license.
#
# Refer to the LICENSE file for details.
#
###

from jaco3_armbase.UDPTransport import UDPTransport
from jaco3_armbase.RouterClient import RouterClient, RouterClientSendOptions
from jaco3_armbase.SessionManager import SessionManager

from jaco3_armbase.autogen.client_stubs.VisionConfigClientRpc import VisionConfigClient
from jaco3_armbase.autogen.client_stubs.DeviceConfigClientRpc import DeviceConfigClient
from jaco3_armbase.autogen.client_stubs.DeviceManagerClientRpc import DeviceManagerClient

from jaco3_armbase.autogen.messages import DeviceConfig_pb2, Session_pb2, DeviceManager_pb2, VisionConfig_pb2


def example_vision_config(device_manager_service, vision_config_service):

    # getting all device routing information (from DeviceManagerClient service)
    allDevicesInfo = device_manager_service.ReadAllDevices()

    vision_handles = [ hd for hd in allDevicesInfo.device_handle if hd.device_type == DeviceConfig_pb2.VISION ]
    if len(vision_handles) == 0:
        print("error: there is no vision device register in the devices infos")
    elif len(vision_handles) > 1:
        print("error: there are more than one vision device register in the devices infos")
    else:
        handle = vision_handles[0]

    sensor_id = VisionConfig_pb2.SensorIdentifier()
    sensor_id.sensor = VisionConfig_pb2.SENSOR_COLOR

    intrinsic_value = vision_config_service.GetIntrinsicParameters(sensor_id, handle.device_identifier)

    print("Width: {0}".format(intrinsic_value.width))
    print("Height: {0}".format(intrinsic_value.height))
    print("Principal point x: {0}".format(intrinsic_value.principal_point_x))
    print("Principal point y: {0}".format(intrinsic_value.principal_point_y))
    print("Focal length x: {0}".format(intrinsic_value.focal_length_x))
    print("Focal length y: {0}".format(intrinsic_value.focal_length_y))


if __name__ == "__main__":

    DEVICE_IP = "192.168.1.10"
    DEVICE_PORT = 10000

    transport = UDPTransport()
    transport.connect(DEVICE_IP, DEVICE_PORT)
    router = RouterClient(transport, lambda kException: print("Error during connection"))

    session_info = Session_pb2.CreateSessionInfo()
    session_info.username = 'admin'
    session_info.password = 'admin'
    session_info.session_inactivity_timeout = 60000  # (milliseconds)
    session_info.connection_inactivity_timeout = 2000 # (milliseconds)

    session_manager = SessionManager(router)
    session_manager.CreateSession(session_info)

    device_manager_service = DeviceManagerClient(router)
    vision_config_service = VisionConfigClient(router)

    # example core
    example_vision_config(device_manager_service, vision_config_service)

