/*
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2018 Kinova inc. All rights reserved.
*
* This software may be modified and distributed under the
* terms of the BSD 3-Clause license.
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

#define PORT 10000
#define PORT_RT 10001
#define ACTUATOR_COUNT 7
#define DURATION 30  //(seconds)

float velocity = 20.0f; // Default velocity of the actuator (degrees per seconds)
float time_duration = DURATION; // Default duration of the actuator (seconds)

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
    // Low level cyclic needs it's own transport and router
    // For this example all the cyclic related object will have the RT suffix

    bool returnStatus = true;

    k_api::TransportClientUdp* pTransport = new k_api::TransportClientUdp();
    k_api::TransportClientUdp* pTransportRT = new k_api::TransportClientUdp();

    pTransport->connect(IP_ADDRESS, PORT);
    pTransportRT->connect(IP_ADDRESS, PORT_RT); // Cyclic data have it's own port

    auto errorCallback = [](k_api::KError err) { std::cout << "_________ callback error _________" << err.toString(); };
    auto errorCallbackRT = [](k_api::KError err) { std::cout << "_________ callback error (RT) _________" << err.toString(); };
    
    k_api::RouterClient* pRouterClient = new k_api::RouterClient(pTransport, errorCallback);
    k_api::RouterClient* pRouterClientRT = new k_api::RouterClient(pTransportRT, errorCallbackRT);
    
    k_api::Base::BaseClient* pBase = new k_api::Base::BaseClient(pRouterClient);
    k_api::BaseCyclic::BaseCyclicClient* pBaseCyclicRT = new k_api::BaseCyclic::BaseCyclicClient(pRouterClientRT);

    k_api::SessionManager* pSessionMng = new k_api::SessionManager(pRouterClient);
    k_api::SessionManager* pSessionMngRT = new k_api::SessionManager(pRouterClientRT);

    auto createSessionInfo = k_api::Session::CreateSessionInfo();
    createSessionInfo.set_username("admin");
    createSessionInfo.set_password("admin");
    createSessionInfo.set_session_inactivity_timeout(60000);
    createSessionInfo.set_connection_inactivity_timeout(2000);

    auto createSessionInfoRT = k_api::Session::CreateSessionInfo();
    createSessionInfoRT.set_username("admin");
    createSessionInfoRT.set_password("admin");
    createSessionInfoRT.set_session_inactivity_timeout(60000);
    createSessionInfoRT.set_connection_inactivity_timeout(2000);

    std::cout << "Creating Session for communication" << std::endl;
    pSessionMng->CreateSession(createSessionInfo);
    pSessionMngRT->CreateSession(createSessionInfoRT);

    std::cout << "Session Created" << std::endl;

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
        // Need to set the base in low level servoing
        auto servoingMode = k_api::Base::ServoingModeInformation();
        servoingMode.set_servoing_mode(k_api::Base::ServoingMode::LOW_LEVEL_SERVOING);
        pBase->SetServoingMode(servoingMode);
        BaseFeedback = pBaseCyclicRT->RefreshFeedback();

        // Initializing each actuator and set them their current position
        for(int i = 0; i < 7; i++)
        {
            ActuatorCommands.push_back(k_api::BaseCyclic::ActuatorCommand());
            ActuatorFeedbacks.push_back(k_api::BaseCyclic::ActuatorFeedback());

            Commands.push_back(BaseFeedback.actuators(i).position());

            ActuatorCommands[i].set_flags(1);
            ActuatorCommands[i].set_position(BaseFeedback.actuators(i).position());
            BaseCommand.add_actuators()->set_position(BaseFeedback.actuators(i).position());
        }

        // Callback function used in Refresh_callback
        auto lambda_fct_callback = [](const Kinova::Api::Error &err, const k_api::BaseCyclic::Feedback data)
        {
            // we are printing the data just for the example purpose
            // normally if we want a real-time loop avoid this
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
                    // Only move the last actuator to prevent collision
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

    // just wait a while to let the response income
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    pSessionMng->CloseSession();
    pSessionMngRT->CloseSession();

    pTransport->disconnect();
    pTransportRT->disconnect();

    delete pBase;
    delete pSessionMng;
    delete pRouterClient;
    delete pTransport;

    delete pBaseCyclicRT;
    delete pSessionMngRT;
    delete pRouterClientRT;
    delete pTransportRT;

    return returnStatus;
}

int main(int argc, char **argv)
{
    auto isOk = example_cyclic_armbase();

    if (!isOk)
        printf("There has been an unexpected error in example_cyclic_armbase() function.");
}
