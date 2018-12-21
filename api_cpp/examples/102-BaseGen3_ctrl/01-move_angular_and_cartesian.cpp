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

namespace k_api = Kinova::Api;

#define IP_ADDRESS "192.168.1.10"
#define PORT 10000


void angularMovement(k_api::Base::BaseClient* base)
{
    std::cout << "Starting angular movement ..." << std::endl;

    auto action = k_api::Base::Action();
    action.set_name("Example angular movement");
    action.set_application_data("");

    auto reachJointAngles = action.mutable_reach_joint_angles();
    auto jointAngles = reachJointAngles->mutable_joint_angles();
    
    std::vector<float> angles = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}; // arm straight up
    for(size_t i = 0 ; i < angles.size(); ++i)
    {
        auto jointAngle = jointAngles->add_joint_angles();
        jointAngle->set_joint_identifier(i);
        jointAngle->set_value(angles.at(i));
    }

    std::cout << "Executing action" << std::endl;
    base->ExecuteAction(action);

    std::cout << "Waiting 10 seconds to finish movement" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    std::cout << "Angular movement finish" << std::endl;
}


void cartesiantMovement(k_api::Base::BaseClient* base)
{
    std::cout << "Starting Cartesian movement ..." << std::endl;
    
    auto action = k_api::Base::Action();
    action.set_name("Example cartesian movement");
    action.set_application_data("");

    auto constrainPose = action.mutable_reach_pose();
    auto pose = constrainPose->mutable_target_pose();
    pose->set_x(0.8);           // x (meters)
    pose->set_y(0.0);           // y (meters)
    pose->set_z(0.36);          // z (meters)
    pose->set_theta_x(10.0);    // theta x (degrees)
    pose->set_theta_y(90.0);    // theta y (degrees)
    pose->set_theta_z(10.0);    // theta z (degrees)

    std::cout << "Executing action" << std::endl;
    base->ExecuteAction(action);

    std::cout << "Waiting 20 seconds to finish movement ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20000)); 

    std::cout << "Cartesian movement ended" << std::endl;
}


int main(int argc, char **argv)
{
    k_api::TransportClientUdp* pTransport = new k_api::TransportClientUdp();
    pTransport->connect(IP_ADDRESS, PORT);

    k_api::RouterClient* pRouter = new k_api::RouterClient(pTransport, [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); });

    // create session
    auto createSessionInfo = k_api::Session::CreateSessionInfo();
    createSessionInfo.set_username("admin");
    createSessionInfo.set_password("admin");
    createSessionInfo.set_session_inactivity_timeout(60000);   // (milliseconds)
    createSessionInfo.set_connection_inactivity_timeout(2000); // (milliseconds)

    std::cout << "Creating session for communication" << std::endl;
    k_api::SessionManager* pSessionMng = new k_api::SessionManager(pRouter);
    pSessionMng->CreateSession(createSessionInfo);
    std::cout << "Session Created" << std::endl;

    std::cout << "Waiting 7.5 seconds before trying to take control of the robot" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(7500)); 

    k_api::Base::BaseClient* pBase = new k_api::Base::BaseClient(pRouter);
    
    angularMovement(pBase);
    cartesiantMovement(pBase);

    pSessionMng->CloseSession();
    pTransport->disconnect();
    delete pBase;
    delete pSessionMng;
    delete pRouter;
    delete pTransport;
    
};