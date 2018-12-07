#! /usr/bin/env python3

###
# KINOVA (R) KORTEX (TM)
#
# Copyright (c) 2018 Kinova inc. All rights reserved.
#
# This software may be modified and distributed under the
# terms of the BSD 3-Clause license.
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

    wifi_configuration = Base_pb2.WifiConfiguration()
    wifi_configuration.ssid.identifier = "MyWifi_SSID"
    wifi_configuration.security_key = "MyWifi_Password"
    wifi_configuration.connect_automatically = True

    # The RouterClientSendOptions exist to modify the default behavior
    # of the router. The router default value are 
    #     andForget = False
    #     delay_ms = 0
    #     timeout_ms = 10000

    # The RouterClientSendOptions is optional and need to be pass with the keyword
    # options
    router_options = RouterClientSendOptions()
    router_options.timeout_ms = 1000 # 1 sec

    # The same function call without the options=router_options is valid and will do the same
    # using the router default value
    base_service.AddWifiConfiguration(wifi_configuration, options=router_options)  


if __name__ == "__main__":

    DEVICE_IP = "192.168.1.10"
    DEVICE_PORT = 10000

    transport = UDPTransport()
    transport.connect(DEVICE_IP, DEVICE_PORT)
    router = RouterClient(transport, lambda kException: print("Error during connection"))

    session_info = Session_pb2.CreateSessionInfo()
    session_info.username = 'admin'
    session_info.password = 'admin'
    session_info.session_inactivity_timeout = 600000 # 10 minutes
    session_info.connection_inactivity_timeout = 2000 # 2 second

    session_manager = SessionManager(router)
    session_manager.CreateSession(session_info)

    base_service = BaseClient(router)

    # example core
    example_call_rpc_using_options(base_service)