<!--
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2019 Kinova inc. All rights reserved.
*
* This software may be modified and distributed
* under the terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
-->

<h1>Servoing Mode</h1>

<h2>Table of Contents</h2>

<!-- TOC -->

- [Overview](#overview)
- [Setting servoing mode](#setting-servoing-mode)
	- [High level servoing mode](#high-level-servoing-mode)
	- [Low level servoing mode](#low-level-servoing-mode)

<!-- /TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
There are multiple servoing modes on the robot. A servoing mode allows commands to be transmitted to the robot devices during operation. Depending on the servoing mode chosen, the details for API control will be different.
 
<a id="markdown-set-servoing-mode" name="set-servoing-mode"></a>
## Setting servoing mode
The RPC to set the servoing mode is in the Base service

```cpp
// API initialisation
k_api::Base::BaseClient* pBase = new k_api::Base::BaseClient(pRouter);

// Sets the base in low level servoing
auto servoingMode = k_api::Base::ServoingModeInformation();
servoingMode.set_servoing_mode(k_api::Base::ServoingMode::LOW_LEVEL_SERVOING); //Enum type
pBase->SetServoingMode(servoingMode);
```

<a id="markdown-high-level" name="high-level"></a>
### High level servoing mode
High-level servoing is the default servoing mode for the robot on bootup.

In high-level servoing, users connect to the base through the API, sending command inputs. The base routes commands to the actuators, and manages a 1 kHz control loop.

High-level servoing is the recommended servoing mode for non-advanced users, because you have access to cartesian movement and doesn't have to manage a 1kHz control loop. 
 
<a id="markdown-low-level" name="low-level"></a>
### Low level servoing mode
In low-level servoing, the API client connects to the base and sends commands through the base for routing. Take note that this mode **does not support cartesian command**

The base ensures device routing and internal communications with the actuators at 1 kHz, but the high-level functionality for the base control loop (cartesian movement, robot kinematics, trajectory management, etc.) are no longer available.

Low-level servoing allows clients to control each actuator individually by sending little position increments at a 1 kHz frequency (bypassing the kinematic control library).

```cpp
#define IP_ADDRESS "192.168.1.10"
#define PORT 10000              // network adapter port
#define PORT_RT 10001

// BaseClient connection
k_api::TransportClientUdp* pTransport = new k_api::TransportClientUdp();

auto errorCallback = [](k_api::KError err) { std::cout << "_________ callback error _________" << err.toString(); };
k_api::RouterClient* pRouter = new k_api::RouterClient(pTransport, errorCallback);

pTransport->connect(IP_ADDRESS, PORT);

k_api::Base::BaseClient* pBase = new k_api::Base::BaseClient(pRouter);
k_api::SessionManager* pSessionMng = new k_api::SessionManager(pRouter);

auto createSessionInfo = k_api::Session::CreateSessionInfo();
createSessionInfo.set_username("admin");
createSessionInfo.set_password("admin");
createSessionInfo.set_session_inactivity_timeout(60000);      // (milliseconds)
createSessionInfo.set_connection_inactivity_timeout(2000);    // (milliseconds)


// BaseCyclic connection (required in low-level servoing)
k_api::TransportClientUdp* pTransportRT = new k_api::TransportClientUdp();

auto errorCallbackRT = [](k_api::KError err) { std::cout << "_________ callback error (RT) _________" << err.toString(); };
k_api::RouterClient* pRouterRT = new k_api::RouterClient(pTransportRT, errorCallbackRT);

pTransportRT->connect(IP_ADDRESS, PORT_RT); // cyclic data have their own port

k_api::BaseCyclic::BaseCyclicClient* pBaseCyclicRT = new k_api::BaseCyclic::BaseCyclicClient(pRouterRT);
k_api::SessionManager* pSessionMngRT = new k_api::SessionManager(pRouterRT);

auto createSessionInfoRT = k_api::Session::CreateSessionInfo();
createSessionInfoRT.set_username("admin");
createSessionInfoRT.set_password("admin");
createSessionInfoRT.set_session_inactivity_timeout(60000);    // (milliseconds)
createSessionInfoRT.set_connection_inactivity_timeout(2000);  // (milliseconds)


// A session is required in both services
std::cout << "Creating session for communication" << std::endl;
pSessionMng->CreateSession(createSessionInfo);
pSessionMngRT->CreateSession(createSessionInfoRT);
std::cout << "Session created" << std::endl;

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
	// sets the base to low-level servoing
	auto servoingMode = k_api::Base::ServoingModeInformation();
	servoingMode.set_servoing_mode(k_api::Base::ServoingMode::LOW_LEVEL_SERVOING);
	pBase->SetServoingMode(servoingMode);
	BaseFeedback = pBaseCyclicRT->RefreshFeedback();

	// initializes each actuator and sets to their current position
	for(int i = 0; i < 7; i++)
	{
	    ActuatorCommands.push_back(k_api::BaseCyclic::ActuatorCommand());
	    ActuatorFeedbacks.push_back(k_api::BaseCyclic::ActuatorFeedback());

	    Commands.push_back(BaseFeedback.actuators(i).position());

	    ActuatorCommands[i].set_flags(1);
	    ActuatorCommands[i].set_position(BaseFeedback.actuators(i).position());
	    BaseCommand.add_actuators()->set_position(BaseFeedback.actuators(i).position());
	}

	// callback function used in Refresh_callback
	auto lambda_fct_callback = [](const Kinova::Api::Error &err, const k_api::BaseCyclic::Feedback data)
	{
	    // we are printing the data just for the example purpose
	    // normally if we want a real-time loop avoid this
	    std::string serializedData;
	    google::protobuf::util::MessageToJsonString(data, &serializedData);
	    std::cout << serializedData << std::endl;
	};

	// real-time loop
	while(timerCount < (time_duration * 1000))
	{
	    now = GetTickUs();

	    if(now - last > 1000)
	    {
	    
		for(int i = 0; i < ACTUATOR_COUNT; i++)
		{
		    // move only the last actuator to prevent collision
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
```
