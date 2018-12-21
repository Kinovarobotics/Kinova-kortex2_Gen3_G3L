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

from jaco3_armbase.autogen.client_stubs.DeviceConfigClientRpc import DeviceConfigClient
from jaco3_armbase.autogen.client_stubs.BaseClientRpc import BaseClient

from jaco3_armbase.autogen.messages import DeviceConfig_pb2, Session_pb2, Base_pb2

def example_call_rpc_using_options(base_service):

    # The RouterClientSendOptions exist to modify the default behavior
    # of the router. The router default value are 
    #     andForget = False     (not implemented yet)
    #     delay_ms = 0          (not implemented yet)
    #     timeout_ms = 10000

    # The RouterClientSendOptions is optional and needs to be passed with the keyword
    # options
    router_options = RouterClientSendOptions()
    router_options.timeout_ms = 5000 # 5 seconds

    # The same function call without the options=router_options is valid and will do the same
    # using the router default value
    wifi_list = base_service.GetAvailableWifi(options=router_options)
    for wifi in wifi_list.wifi_information_list:
        print("============================================")
        print("SSID: {0}".format(wifi.ssid.identifier))
        print("Wi-Fi security type: {0}".format(wifi.security_type))
        print("Wi-Fi encryption type: {0}".format(wifi.encryption_type))
        print("Signal strength: {0}".format(wifi.signal_strength))
        print("============================================")


if __name__ == "__main__":

    DEVICE_IP = "192.168.1.10"
    DEVICE_PORT = 10000

    transport = UDPTransport()
    transport.connect(DEVICE_IP, DEVICE_PORT)
    router = RouterClient(transport, lambda kException: print("Error during connection"))

    session_info = Session_pb2.CreateSessionInfo()
    session_info.username = 'admin'
    session_info.password = 'admin'
    session_info.session_inactivity_timeout = 60000   # (milliseconds)
    session_info.connection_inactivity_timeout = 2000 # (milliseconds)

    session_manager = SessionManager(router)
    session_manager.CreateSession(session_info)

    base_service = BaseClient(router)

    # example core
    example_call_rpc_using_options(base_service)

    session_manager.CloseSession()