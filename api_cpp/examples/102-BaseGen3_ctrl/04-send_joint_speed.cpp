/*
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2018 Kinova inc. All rights reserved.
*
* This software may be modified and distributed
* under the terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
*/


#include <BaseClientRpc.h>

#include <SessionManager.h>
#include <RouterClient.h>
#include <TransportClientUdp.h>
#include <DeviceManagerClientRpc.h>
#include <DeviceConfigClientRpc.h>
#include <Common.pb.h>

namespace k_api = Kinova::Api;

#define IP_ADDRESS "192.168.1.10"
#define PORT 10000


void example_single_joint(k_api::Base::BaseClient* pBase, uint32_t last_act_id)
{
    auto jointSpeed = k_api::Base::JointSpeed();
    last_act_id -= 1;  // Need to exclude base id
    jointSpeed.set_joint_identifier(last_act_id);
    jointSpeed.set_value(2.0f); // Speed in degrees/second
    jointSpeed.set_duration(0); // Unlimited time to execute
    pBase->SendSelectedJointSpeedCommand(jointSpeed);

    // Let time for joint speed command to be executed
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    jointSpeed.set_value(0.0f);
    pBase->SendSelectedJointSpeedCommand(jointSpeed);
}


int main(int argc, char **argv)
{
    // Setup API
    auto errorCallback =  [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); };
    auto pTransport = new k_api::TransportClientUdp();
    auto pRouter = new k_api::RouterClient(pTransport, errorCallback);
    pTransport->connect(IP_ADDRESS, PORT);

    // Create session
    auto createSessionInfo = k_api::Session::CreateSessionInfo();
    createSessionInfo.set_username("admin");
    createSessionInfo.set_password("admin");
    createSessionInfo.set_session_inactivity_timeout(60000);   // (milliseconds)
    createSessionInfo.set_connection_inactivity_timeout(2000); // (milliseconds)

    std::cout << "\nCreating session for communication" << std::endl;
    auto pSessionMng = new k_api::SessionManager(pRouter);
    pSessionMng->CreateSession(createSessionInfo);
    std::cout << "Session created" << std::endl;

    // Create required services
    auto pBase = new k_api::Base::BaseClient(pRouter);
    auto pDeviceManager = new k_api::DeviceManager::DeviceManagerClient(pRouter);

    // Find the last actuator
    auto subDeviceInfo = pDeviceManager->ReadAllDevices();
    uint32_t last_act = 0;
    uint32_t last_act_id = 0;

    for ( auto dev : subDeviceInfo.device_handle() )
    {
        if ( dev.device_type() == k_api::Common::BIG_ACTUATOR ||
            dev.device_type() == k_api::Common::SMALL_ACTUATOR)
        {
            if ( dev.order() > last_act )
            {
                last_act = dev.order();
                last_act_id = dev.device_identifier();
            }
        }
    }

    // Move arm to ready position
    std::cout << "\nMoving the arm to a safe position before executing example" << std::endl;
    auto action_type = k_api::Base::RequestedActionType();
    action_type.set_action_type(k_api::Base::REACH_JOINT_ANGLES);
    auto action_list = pBase->ReadAllActions(action_type);
    auto action_handle = k_api::Base::ActionHandle();
    action_handle.set_identifier(0); 
    for( auto action : action_list.action_list())
    {
        if(action.name() == "Home")
        {
            action_handle = action.handle();
        }
    }

    if(action_handle.identifier() == 0)
    {
        std::cout << "\nCan't reach safe position. Exiting" << std::endl;       
    }
    else
    {
        pBase->ExecuteActionFromReference(action_handle);
        std::this_thread::sleep_for(std::chrono::seconds(20)); // Leave time to action to finish
    }
    
    // Example core
    std::cout << "Calling single_joint" << std::endl;
    example_single_joint(pBase, last_act_id);

    // Close API session
    pSessionMng->CloseSession();

    // Deactivate the router and cleanly disconnect from the transport object
    pRouter->SetActivationStatus(false);
    pTransport->disconnect();

    // Destroy the API
    delete pBase;
    delete pSessionMng;
    delete pRouter;
    delete pTransport;
};