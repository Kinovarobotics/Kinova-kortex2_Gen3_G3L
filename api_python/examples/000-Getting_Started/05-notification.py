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

import time

from kortex_api.UDPTransport import UDPTransport
from kortex_api.RouterClient import RouterClient, RouterClientSendOptions
from kortex_api.SessionManager import SessionManager

from kortex_api.autogen.client_stubs.DeviceConfigClientRpc import DeviceConfigClient
from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient

from kortex_api.autogen.messages import DeviceConfig_pb2, Session_pb2, Base_pb2

from kortex_api.Exceptions.KException import KException
from google.protobuf import json_format

def example_notification(base_service):

    def notification_callback(data):
        print("****************************")
        print("* Callback function called *")
        print(json_format.MessageToJson(data))
        print("****************************")

    # Subscribe to ConfigurationChange notifications
    print("Subscribing to ConfigurationChange notifications")
    try:
        notif_handle = base_service.OnNotificationConfigurationChangeTopic(notification_callback, Base_pb2.NotificationOptions())
    except KException as k_ex:
        print("Error occured: {}".format(k_ex))
    except Exception:
        print("Error occured")

    # ... miscellaneous tasks
    time.sleep(3)

    # Create a user profile to trigger a notification
    full_user_profile = Base_pb2.FullUserProfile()
    full_user_profile.user_profile.username = 'jcash'
    full_user_profile.user_profile.firstname = 'Johnny'
    full_user_profile.user_profile.lastname = 'Cash'
    full_user_profile.user_profile.application_data = "Custom Application Stuff"
    full_user_profile.password = "pwd"

    user_profile_handle = Base_pb2.UserProfileHandle()
    try:
        print("Creating user profile to trigger notification")
        user_profile_handle = base_service.CreateUserProfile(full_user_profile)
    except KException:
        print("User profile creation failed")

    # ... following the creation of the user profile we should receive the ConfigurationChange notification (notification_callback() should be called)
    print("User {0} created".format(full_user_profile.user_profile.username))

    # ... miscellaneous tasks and to give time for the notification to work.
    time.sleep(3)

    print("Now unsubscribe from ConfigurationChange notifications")
    base_service.Unsubscribe(notif_handle)

    try:
        print("Deleting previously created user profile ({0})".format(full_user_profile.user_profile.username))
        base_service.DeleteUserProfile(user_profile_handle) # Should not have received notification about this modification

    except KException:
        print("User profile deletion failed")
    
    # ... here sleep to confirm that ConfigurationChange notification is not raised anymore after the unsubscribe
    time.sleep(3)


if __name__ == "__main__":

    DEVICE_IP = "192.168.1.10"
    DEVICE_PORT = 10000

    # Setup API
    errorCallback = lambda kException: print("_________ callback error _________ {}".format(kException))
    transport = UDPTransport()
    router = RouterClient(transport, errorCallback)
    transport.connect(DEVICE_IP, DEVICE_PORT)

    # Create session
    session_info = Session_pb2.CreateSessionInfo()
    session_info.username = 'admin'
    session_info.password = 'admin'
    session_info.session_inactivity_timeout = 60000   # (milliseconds)
    session_info.connection_inactivity_timeout = 2000 # (milliseconds)

    session_manager = SessionManager(router)
    session_manager.CreateSession(session_info)

    # Create required services
    base_service = BaseClient(router)

    # Example core
    example_notification(base_service)

    # Close API session
    session_manager.CloseSession()

    # Deactivate the router and cleanly disconnect from the transport object
    router.SetActivationStatus(False)
    transport.disconnect()
