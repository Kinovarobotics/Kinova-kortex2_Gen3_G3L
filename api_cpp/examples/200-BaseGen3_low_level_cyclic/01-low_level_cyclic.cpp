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


#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include <KDetailedException.h>

#include <BaseClientRpc.h>
#include <BaseCyclicClientRpc.h>
#include <SessionClientRpc.h>
#include <SessionManager.h>

#include <RouterClient.h>
#include <TransportClientUdp.h>

#include <google/protobuf/util/json_util.h>

#if defined(_MSC_VER)
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <time.h>

namespace k_api = Kinova::Api;


#define IP_ADDRESS "192.168.1.10"

#define PORT 10000              // network adapter port
#define PORT_RT 10001
#define ACTUATOR_COUNT 7        // actuator count
#define DURATION 30             // network timeout (seconds)

float velocity = 20.0f;         // default velocity of the actuator (degrees per seconds)
float time_duration = DURATION; // default duration of the actuator (seconds)

int64_t GetTickUs()
{
#if defined(_MSC_VER)
    LARGE_INTEGER start, frequency;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    return (start.QuadPart * 1000000)/frequency.QuadPart;
#else
    struct timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    return (start.tv_sec * 1000000LLU) + (start.tv_nsec / 1000);
#endif
}

bool example_cyclic_armbase()
{
    // Low-level cyclic needs its own transport and router
    // for this example all the cyclic-related objects have the RT suffix

    bool returnStatus = true;

    k_api::TransportClientUdp* pTransport = new k_api::TransportClientUdp();
    k_api::TransportClientUdp* pTransportRT = new k_api::TransportClientUdp();

    auto errorCallback = [](k_api::KError err) { std::cout << "_________ callback error _________" << err.toString(); };
    auto errorCallbackRT = [](k_api::KError err) { std::cout << "_________ callback error (RT) _________" << err.toString(); };
    
    k_api::RouterClient* pRouter = new k_api::RouterClient(pTransport, errorCallback);
    k_api::RouterClient* pRouterRT = new k_api::RouterClient(pTransportRT, errorCallbackRT);
    
    pTransport->connect(IP_ADDRESS, PORT);
    pTransportRT->connect(IP_ADDRESS, PORT_RT); // cyclic data have their own port

    k_api::Base::BaseClient* pBase = new k_api::Base::BaseClient(pRouter);
    k_api::BaseCyclic::BaseCyclicClient* pBaseCyclicRT = new k_api::BaseCyclic::BaseCyclicClient(pRouterRT);

    k_api::SessionManager* pSessionMng = new k_api::SessionManager(pRouter);
    k_api::SessionManager* pSessionMngRT = new k_api::SessionManager(pRouterRT);

    auto createSessionInfo = k_api::Session::CreateSessionInfo();
    createSessionInfo.set_username("admin");
    createSessionInfo.set_password("admin");
    createSessionInfo.set_session_inactivity_timeout(60000);      // (milliseconds)
    createSessionInfo.set_connection_inactivity_timeout(2000);    // (milliseconds)

    auto createSessionInfoRT = k_api::Session::CreateSessionInfo();
    createSessionInfoRT.set_username("admin");
    createSessionInfoRT.set_password("admin");
    createSessionInfoRT.set_session_inactivity_timeout(60000);    // (milliseconds)
    createSessionInfoRT.set_connection_inactivity_timeout(2000);  // (milliseconds)

    std::cout << "\nCreating session for communication" << std::endl;
    pSessionMng->CreateSession(createSessionInfo);
    pSessionMngRT->CreateSession(createSessionInfoRT);
    std::cout << "Session created" << std::endl;

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
    

    k_api::BaseCyclic::Feedback BaseFeedback;
    k_api::BaseCyclic::Command  BaseCommand;

    std::vector<k_api::BaseCyclic::ActuatorCommand> ActuatorCommands;
    std::vector<k_api::BaseCyclic::ActuatorFeedback> ActuatorFeedbacks;
    std::vector<float> Commands;

    int timerCount = 0;
    int64_t now = 0;
    int64_t last = 0;

    int timeout = 0;

    std::cout << "duration: " << time_duration << std::endl;
    std::cout << "velocity: " << velocity << std::endl;

    try
    {
        // Set the base in low-level servoing mode
        auto servoingMode = k_api::Base::ServoingModeInformation();
        servoingMode.set_servoing_mode(k_api::Base::ServoingMode::LOW_LEVEL_SERVOING);
        pBase->SetServoingMode(servoingMode);
        BaseFeedback = pBaseCyclicRT->RefreshFeedback();

        // Initialize each actuator to their current position
        for(int i = 0; i < 7; i++)
        {
            ActuatorCommands.push_back(k_api::BaseCyclic::ActuatorCommand());
            ActuatorFeedbacks.push_back(k_api::BaseCyclic::ActuatorFeedback());

            Commands.push_back(BaseFeedback.actuators(i).position());

            ActuatorCommands[i].set_flags(1);
            ActuatorCommands[i].set_position(BaseFeedback.actuators(i).position());
            BaseCommand.add_actuators()->set_position(BaseFeedback.actuators(i).position());
        }

        // Define the callback function used in Refresh_callback
        auto lambda_fct_callback = [](const Kinova::Api::Error &err, const k_api::BaseCyclic::Feedback data)
        {
            // We are printing the data just for the example purpose,
            // avoid this in a real-time loop
            std::string serializedData;
            google::protobuf::util::MessageToJsonString(data, &serializedData);
            std::cout << serializedData << std::endl;
        };

        // Real-time loop
        while(timerCount < (time_duration * 1000))
        {
            now = GetTickUs();

            if(now - last > 1000)
            {
            
                for(int i = 0; i < ACTUATOR_COUNT; i++)
                {
                    // Move only the last actuator to prevent collision
        		    if(i == 6)
        		    {
                        Commands[i] += (0.001f * velocity);
                       	ActuatorCommands[i].set_position(Commands[i]);
                    	BaseCommand.mutable_actuators(i)->set_position(fmod(Commands[i], 360.0f));
        		    }
                }
                
                try
                {
                    pBaseCyclicRT->Refresh_callback(BaseCommand, lambda_fct_callback, 0);
                }
                catch(...)
                {
                    timeout++;
                }
                
                timerCount++;
                last = GetTickUs();
            }
        }

	    servoingMode.set_servoing_mode(k_api::Base::ServoingMode::SINGLE_LEVEL_SERVOING);
        pBase->SetServoingMode(servoingMode);
    }
    catch (k_api::KDetailedException& ex)
    {
        std::cout << "API error: " << ex.what() << std::endl;
        returnStatus = false;
    }
    catch (std::runtime_error& ex2)
    {
        std::cout << "Error: " << ex2.what() << std::endl;
        returnStatus = false;
    }

    // Just wait a while to let the response come
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    // Close both API sessions
    pSessionMng->CloseSession();
    pSessionMngRT->CloseSession();

    // Deactivate both routers and cleanly disconnect from the transport objects
    pRouter->SetActivationStatus(false);
    pRouterRT->SetActivationStatus(false);
    pTransport->disconnect();
    pTransportRT->disconnect();

    // Destroy both API
    delete pBase;
    delete pSessionMng;
    delete pRouter;
    delete pTransport;

    delete pBaseCyclicRT;
    delete pSessionMngRT;
    delete pRouterRT;
    delete pTransportRT;

    return returnStatus;
}

int main(int argc, char **argv)
{
    auto isOk = example_cyclic_armbase();

    if (!isOk)
        printf("There has been an unexpected error in example_cyclic_armbase() function.");
}
