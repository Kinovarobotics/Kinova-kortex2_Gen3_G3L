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

from kortex_api.autogen.messages import DeviceConfig_pb2, Session_pb2, Base_pb2, Common_pb2

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
        requested_action_type = Base_pb2.RequestedActionType()
        # requested_action_type.action_type = Base_pb2.REACH_JOINT_ANGLES
        all_actions = base.ReadAllActions(requested_action_type, options=router_options)
    except Exception as e:
        print(e)
    else:
        print ("List of all actions in the arm:")
        for action in all_actions.action_list:
            print("============================================")
            print("Action name: {0}".format(action.name))
            print("Action identifier: {0}".format(action.handle.identifier))
            print("Action type: {0}".format(Base_pb2.ActionType.Name(action.handle.action_type)))
            print("Action permissions: ")
            if (action.handle.permission & Common_pb2.NO_PERMISSION): print("\t- {0}".format(Common_pb2.Permission.Name(Common_pb2.NO_PERMISSION)))
            if (action.handle.permission & Common_pb2.READ_PERMISSION): print("\t- {0}".format(Common_pb2.Permission.Name(Common_pb2.READ_PERMISSION)))
            if (action.handle.permission & Common_pb2.UPDATE_PERMISSION): print("\t- {0}".format(Common_pb2.Permission.Name(Common_pb2.UPDATE_PERMISSION)))
            if (action.handle.permission & Common_pb2.DELETE_PERMISSION): print("\t- {0}".format(Common_pb2.Permission.Name(Common_pb2.DELETE_PERMISSION)))
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