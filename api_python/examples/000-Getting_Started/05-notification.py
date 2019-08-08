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
import time

from kortex_api.autogen.client_stubs.DeviceConfigClientRpc import DeviceConfigClient
from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient

from kortex_api.autogen.messages import DeviceConfig_pb2, Session_pb2, Base_pb2

from kortex_api.Exceptions.KException import KException
from google.protobuf import json_format

def example_notification(base):

    def notification_callback(data):
        print("****************************")
        print("* Callback function called *")
        print(json_format.MessageToJson(data))
        print("****************************")

    # Subscribe to ConfigurationChange notifications
    print("Subscribing to ConfigurationChange notifications")
    try:
        notif_handle = base.OnNotificationConfigurationChangeTopic(notification_callback, Base_pb2.NotificationOptions())
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
        user_profile_handle = base.CreateUserProfile(full_user_profile)
    except KException:
        print("User profile creation failed")

    # Following the creation of the user profile, we should receive the ConfigurationChange notification (notification_callback() should be called)
    print("User {0} created".format(full_user_profile.user_profile.username))

    # Give time for the notification to arrive
    time.sleep(3)

    print("Now unsubscribing from ConfigurationChange notifications")
    base.Unsubscribe(notif_handle)

    try:
        print("Deleting previously created user profile ({0})".format(full_user_profile.user_profile.username))
        base.DeleteUserProfile(user_profile_handle) # Should not have received notification about this modification

    except KException:
        print("User profile deletion failed")
    
    # Sleep to confirm that ConfigurationChange notification is not raised anymore after the unsubscribe
    time.sleep(3)


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
        example_notification(base)

if __name__ == "__main__":
    main()
