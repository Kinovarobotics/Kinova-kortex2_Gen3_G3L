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

import sys
import os

from kortex_api.RouterClient import RouterClientSendOptions

from kortex_api.autogen.client_stubs.DeviceConfigClientRpc import DeviceConfigClient
from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient

from kortex_api.autogen.messages import DeviceConfig_pb2, Session_pb2, Base_pb2

def example_call_rpc_using_options(base):

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
    # using router's default options
    
    try:
        all_speed_hard_limits = base.GetAllJointsSpeedHardLimitation()
    except Exception as e:
        print(e)
    
    for speed_limit in all_speed_hard_limits.joints_limitations:
        print("============================================")
        print("Joint: {0}".format(speed_limit.joint_identifier))
        print("Type of limitation: {0}".format(Base_pb2.LimitationType.Name(speed_limit.type)))
        print("Value: {0}".format(speed_limit.value))
        print("============================================")

def main():
    # Import the utilities helper module
    sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
    import utilities

    # Parse arguments
    args = utilities.parseConnectionArguments()
    
    # Create connection to the device and get the router
    with utilities.DeviceConnection.createTcpConnection(args) as router:

        # Create required services
        base = BaseClient(router)

        # Example core
        example_call_rpc_using_options(base)

if __name__ == "__main__":
    main()