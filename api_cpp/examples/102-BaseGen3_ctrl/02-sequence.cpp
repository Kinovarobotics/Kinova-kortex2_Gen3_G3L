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


void createAngularAction(k_api::Base::Action* action)
{
    std::cout << "Creating angular action" << std::endl;
    action->set_name("Example angular action");
    action->set_application_data("");    

    auto reachJointAngles = action->mutable_reach_joint_angles();
    auto jointAngles = reachJointAngles->mutable_joint_angles();

    std::vector<float> angles = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};   
    for(size_t i = 0 ; i < angles.size(); ++i)
    {
        auto jointAngle = jointAngles->add_joint_angles();
        jointAngle->set_joint_identifier(i);
        jointAngle->set_value(angles.at(i));
    }
}


void createCartesianAction(k_api::Base::Action* action)
{
    std::cout << "Creating cartesian action" << std::endl;
    action->set_name("cartesian movement");
    action->set_application_data("");

    auto constrainPose = action->mutable_reach_pose();
    auto pose = constrainPose->mutable_target_pose();
    pose->set_x(0.8);           // x (meters)
    pose->set_y(0.0);           // y (meters)
    pose->set_z(0.36);          // z (meters)
    pose->set_theta_x(10.0);    // theta x (degrees)
    pose->set_theta_y(90.0);    // theta y (degrees)
    pose->set_theta_z(10.0);    // theta z (degrees)

}


void createSequence(k_api::Base::BaseClient* pBase)
{
 
    std::cout << "Creating Sequence" << std::endl;
    auto sequence = k_api::Base::Sequence();
    sequence.set_name("Example sequence");
    
    std::cout << "Appending Actions to Sequence" << std::endl;
    auto task_1 = sequence.add_tasks();
    task_1->set_group_identifier(0);
    createAngularAction(task_1->mutable_action());
    
    auto task_2 = sequence.add_tasks();
    task_2->set_group_identifier(1); // sequence elements with same group_id are played at the same time
    createCartesianAction(task_2->mutable_action());

    // create the sequence and play it
    std::cout << "Create sequence on device and execute it" << std::endl;
    auto sequenceHandle = pBase->CreateSequence(sequence);
    pBase->PlaySequence(sequenceHandle);

    std::cout << "Waiting 30 seconds to finish movement..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(30000)); // (milliseconds)

    std::cout << "Sleep complete" << std::endl;
}


int main(int argc, char **argv)
{
    k_api::TransportClientUdp* pTransport = new k_api::TransportClientUdp();
    pTransport->connect(IP_ADDRESS, PORT);

    auto router_callback =  [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); };
    k_api::RouterClient* pRouter = new Kinova::Api::RouterClient(pTransport, router_callback);

    // create session
    auto createSessionInfo = k_api::Session::CreateSessionInfo();
    createSessionInfo.set_username("admin");
    createSessionInfo.set_password("admin");
    createSessionInfo.set_session_inactivity_timeout(60000);   // (milliseconds)
    createSessionInfo.set_connection_inactivity_timeout(2000); // (milliseconds)

    std::cout << "Creating Session for communication" << std::endl;
    k_api::SessionManager* pSessionMng = new k_api::SessionManager(pRouter);
    pSessionMng->CreateSession(createSessionInfo);
    std::cout << "Session Created" << std::endl;

    auto pBase = new k_api::Base::BaseClient(pRouter);

    // example core
    createSequence(pBase);

    pSessionMng->CloseSession();
    pTransport->disconnect();
    delete pSessionMng;
    delete pRouter;
    delete pTransport;
    delete pBase;

};