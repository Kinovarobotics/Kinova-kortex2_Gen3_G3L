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

from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient
from kortex_api.autogen.messages import Base_pb2


def example_manipulation_protobuf_basic():
    
    # In Google Protocol Buffer, there are many scalar value types you can declare. 
    # All have a corresponding type in Python. 
    # Here's the list:
    
    # Proto type : Python type
    # double : float
    # float : float
    # int32 : int
    # int64 : int
    # uint32 : int/long
    # uint64 : int/long
    # sint32 : int
    # sint64 : int/long
    # fixed32 : int/long
    # fixed64 : int/long
    # sfixed32 : int
    # sfixed64 : int/long
    # bool : bool
    # string : str
    # bytes : str

    # These types can be used just like regular Python variables.
    # For more information about scalar value types visits:
    # https://developers.google.com/protocol-buffers/docs/proto3#scalar

    # You can regroup many of these scalar value in a message. The message is a structure used in Google Protocol Buffer
    # to ensure all object information is in scope. Scalar values don't exist on their own
    # if they are not contained in a message.

    # Here's a quick example using the Kinova API UserProfile message:
    # message UserProfile {
    #     Kinova.Api.Common.UserProfileHandle handle = 1; // User handle (no need to set it with CreateUserProfile()
    #     string username = 2;                            // username, which is used to connect to robot (or via Web App login)
    #     string firstname = 3;                           // user first name
    #     string lastname = 4;                            // user last name
    #     string application_data = 5;                    // other application data (used by Web App)
    # }

    user_profile = Base_pb2.UserProfile()
    # Each scalar value in a message has a set_<field> function to set the value
    # and a getter which is simply the variable name
    user_profile.username = "jcash" # We can directly affect data to a variable attribute
    user_profile.firstname = "Johnny"
    user_profile.lastname = "Cash"
    # Handle and application_data are ignored on purpose

def example_manipulation_protobuf_object():

    # Messages are the main element in Google Protocol Buffer in the same way classes are to Python. You need a message 
    # to make a workable object. A message can contain many kind of elements. We have already
    # covered the scalar value and in this section we are going to cover the message.
    #

    # A message can make a reference to another message to make more comprehensive element.

    # For this example we'll use the FullUserProfile and UserProfile messages.
    # message FullUserProfile {
    #     UserProfile user_profile = 1; //User Profile, which includes username.
    #     string password = 2; //User's password
    # }
    # message UserProfile {
    #     Kinova.Api.Common.UserProfileHandle handle = 1; // User handle (no need to be set)
    #     string username = 2;                            // username, which is used to connect to robot (or via Web App login)
    #     string firstname = 3;                           // user first name
    #     string lastname = 4;                            // user last name
    #     string application_data = 5;                    // other application data (used by Web App)
    # }

    # https://developers.google.com/protocol-buffers/docs/proto3#simple

    full_user_profile = Base_pb2.FullUserProfile()
    # Now we'll add data to the scalar
    full_user_profile.password = "MyPassword"

    # Now I want to work with the user profile attribute which is a message itself. 
    # Since user profile is a message you can use the '.' to access 
    # these attributes.
    full_user_profile.user_profile.username = "jcash"
    full_user_profile.user_profile.firstname = "Johnny"
    full_user_profile.user_profile.lastname = "Cash"

    # Another basic element is the enum. Enum is directly available from 
    # the message - no need to use the enum 'message'.
    # Here's an example:
    # enum LimitationType {
    #     UNSPECIFIED_LIMITATION = 0;  // unspecified limitation
    #     FORCE_LIMITATION = 1;        // force limitation
    #     ACCELERATION_LIMITATION = 2; // acceleration limitation
    #     VELOCITY_LIMITATION = 3;     // velocity limitation
    # }

    # message CartesianLimitation { 
    #     LimitationType type = 1;     // limitation type
    # }

    # https://developers.google.com/protocol-buffers/docs/proto3#enum

    cartesianLimitation = Base_pb2.CartesianLimitation
    cartesianLimitation.type = Base_pb2.FORCE_LIMITATION


def example_manipulation_protobuf_list():

    # In Google Protocol Buffer, 'repeated' is used to designate a list of indeterminate length. Once affected to a Python
    # variable they can be used in the same way as a standard list.

    # Note that a repeated message field doesn't have an append() function, it has an
    # add() function that create the new message object.

    # For this example we will use the following two messages
    # message Sequence {
    #     SequenceHandle handle = 1
    #     string name = 2
    #     string application_data = 3
    #     repeated SequenceTask tasks = 4
    # }

    # message SequenceTask {
    #     uint32 group_identifier = 1;
    #     Action action = 2; 
    #     string application_data = 3;
    # }

    # For a clearer example the attribute action in SequenceTask message will be kept to default value

    # Here's two ways to add to a repeated message field


    # Create the parent message
    sequence = Base_pb2.Sequence()
    sequence.name = "Sequence"

    # The 'extend' way
    sequence_task_1 = Base_pb2.SequenceTask()
    sequence_task_1.group_identifier = 10
    action = sequence_task_1.action
    action = Base_pb2.Action()               # Using Action default constructor
    sequence.tasks.extend([sequence_task_1]) # Extend expect an iterable

    # Created for the add() function unique to repeated message field
    sequence_task_2 = sequence.tasks.add()
    sequence_task_2.group_identifier = 20
    action = sequence_task_2.action
    action = Base_pb2.Action()               # Using Action default constructor

    # Since sequence.task is a list we can use all the Python features to
    # loop, iterate, interogate and print elements in that list.
    for i in range(len(sequence.tasks)):
        print("Sequence ID with index : {0}".format(sequence.tasks[i].group_identifier))


    # Lists have the iterator property of a Python list, so you can directly iterate
    # throught element without creating a iterator as in the previous example
    for task in sequence.tasks:
        print("Sequence ID with object iterator : {0}".format(task.group_identifier))


def example_manipulation_protobuf_helpers():

    # Google offers some helpers with Google Protocol Buffer,
    # some of which are covered in this section.

    # All the module google.protobuf documentation is available here:
    # https://developers.google.com/protocol-buffers/docs/reference/python/

    # First, the function include with message instance. We will cover the next function
    #     Clear
    #     MergeFrom
    #     CopyFrom

    # The Clear function is straightforward - it clears all the message attributes.

    # MergeFrom and CopyFrom have the same purpose: to duplicate data into another object.
    # The difference between them is that CopyFrom will do a Clear before a MergeFrom.
    
    # For its part MergeFrom will merge data if the new field is not empty.
    # In the case of repeated, the content received in a parameter will be appended.

    # For this example, we'll used the SSID message
    # message Ssid {
    #     string identifier = 1;
    # }


    # First we'll create four of them, each with a unique string
    ssid_1 = Base_pb2.Ssid()
    ssid_1.identifier = ""

    ssid_2 = Base_pb2.Ssid()
    ssid_2.identifier = "123"

    ssid_3 = Base_pb2.Ssid()
    ssid_3.identifier = "@#$"

    # Now merge ssid_1 into ssid_2 and print the identifier of ssid_2
    ssid_2.MergeFrom(ssid_1)
    print("Content ssid_2: {0}".format(ssid_2.identifier))
    # output : Content ssid_2: 123

    # Now copy ssid_1 into ssid_3 and print the identifier of ssid_3
    ssid_3.CopyFrom(ssid_1)
    print("Content ssid_3: {0}".format(ssid_3.identifier))
    # output : Content ssid_3:

    # For more functions consult the Class Message documentation
    # https://developers.google.com/protocol-buffers/docs/reference/python/google.protobuf.message.Message-class

    # From the Google Protocol Buffer library you can use the json_format module.
    # One useful function is the MessageToJson.
    # This function serializes the Google Protocol Buffer message to a JSON object. It is helpful when you want to print a large object into 
    # a human-readable format.

    # Here's an example with the following two messages
	#
    # message Sequence {
    #     SequenceHandle handle = 1
    #     string name = 2
    #     string application_data = 3
    #     repeated SequenceTask tasks = 4
    # }

    # message SequenceTask {
    #     uint32 group_identifier = 1;
    #     Action action = 2; 
    #     string application_data = 3;
    # }

    # populate the message
    sequence = Base_pb2.Sequence()
    sequence.name = "A Name"

    for i in range(5):
        sequence_task = sequence.tasks.add()
        sequence_task.group_identifier = 10 * (i + 1) # Some further function doesn't print if value = 0
        action = sequence_task.action
        action = Base_pb2.Action()                    # Using Action default constructor


    # need to import the module
    from google.protobuf import json_format
    
    # now get the JSON object
    json_object = json_format.MessageToJson(sequence)
    
    # now print it
    print("Json object:")
    print(json_object)
    # output:
    # Json object
    # {
    #   "name": "A Name",
    #   "tasks": [
    #     {
    #       "groupIdentifier": 10
    #     },
    #     {
    #       "groupIdentifier": 20
    #     },
    #     {
    #       "groupIdentifier": 30
    #     },
    #     {
    #       "groupIdentifier": 40
    #     },
    #     {
    #       "groupIdentifier": 50
    #     }
    #   ]
    # }


    # From the Google Protocol Buffer library you can used the text_format module.
    # A useful function is the MessageToString. It has the same purpose as 
    # MessageToJson - convert the message to a human readable format.

    # For the example we'll reuse the sequence object created in the previous example 

    # First import the module
    from google.protobuf import text_format

    # Now print
    print("Text format:")
    print(text_format.MessageToString(sequence))
    # output:
    # Text format
    # name: "A Name"
    # tasks {
    #   group_identifier: 10
    # }
    # tasks {
    #   group_identifier: 20
    # }
    # tasks {
    #   group_identifier: 30
    # }
    # tasks {
    #   group_identifier: 40
    # }
    # tasks {
    #   group_identifier: 50
    # }


if __name__ == "__main__":
    # Example core
    # Basic manipulation
    example_manipulation_protobuf_basic()
    
    # Manipulating messages with nested messages
    example_manipulation_protobuf_object()

    # Manipulation messages containing lists
    example_manipulation_protobuf_list()

    # Using the google::protobuf helper functions
    example_manipulation_protobuf_helpers()