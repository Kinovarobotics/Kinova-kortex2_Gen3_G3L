/*
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2021 Kinova inc. All rights reserved.
*
* This software may be modified and distributed
* under the terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
*/

#include <BaseClientRpc.h>
#include <BaseCyclicClientRpc.h>
#include <SessionManager.h>

#include <RouterClient.h>
#include <TransportClientTcp.h>
#include <vector>
#include <array>

#include "utilities.h"

#define PORT 10000

namespace k_api = Kinova::Api;

// Maximum allowed waiting time during actions
constexpr auto TIMEOUT_DURATION = std::chrono::seconds{100};

// Create an event listener that will set the promise action event to the exit value
// Will set promise to either END or ABORT
// Use finish_promise_cart.get_future.get() to wait and get the value
std::function<void(k_api::Base::ActionNotification)> 
    create_event_listener_by_promise(std::promise<k_api::Base::ActionEvent>& finish_promise_cart)
{
    return [&finish_promise_cart] (k_api::Base::ActionNotification notification)
    {
        const auto action_event = notification.action_event();
        switch(action_event)
        {
        case k_api::Base::ActionEvent::ACTION_END:
        case k_api::Base::ActionEvent::ACTION_ABORT:
            finish_promise_cart.set_value(action_event);
            break;
        default:
            break;
        }
    };
}

// Create an event listener that will set the sent reference to the exit value
// Will set to either END or ABORT
// Read the value of returnAction until it is set
std::function<void(k_api::Base::ActionNotification)>
    create_event_listener_by_ref(k_api::Base::ActionEvent& returnAction)
{
    return [&returnAction](k_api::Base::ActionNotification notification)
    {
        const auto action_event = notification.action_event();
        switch(action_event)
        {
        case k_api::Base::ActionEvent::ACTION_END:
        case k_api::Base::ActionEvent::ACTION_ABORT:
            returnAction = action_event;
            break;
        default:
            break;
        }
    };
}

bool example_trajectory(k_api::Base::BaseClient* base)
{
    bool success = false;

    auto product = base->GetProductConfiguration();
    bool gen3LiteModelCompatible = false;
    if(   product.model() == k_api::ProductConfiguration::MODEL_ID_L53 
       || product.model() == k_api::ProductConfiguration::MODEL_ID_L31)
    {
        if(product.model() == k_api::ProductConfiguration::MODEL_ID_L31)
        {
            gen3LiteModelCompatible = true; // Detected a Gen3 Lite
        }        
    }
    else
    {
        std::cout << "Product is not compatible to run this example please contact support with KIN number bellow" << std::endl;
        std::cout << "Product KIN is : " << product.kin() << std::endl;
        return success;
    }
    
    // Make sure the arm is in Single Level Servoing before executing an Action
    auto servoingMode = k_api::Base::ServoingModeInformation();
    servoingMode.set_servoing_mode(k_api::Base::ServoingMode::SINGLE_LEVEL_SERVOING);
    base->SetServoingMode(servoingMode);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Create the trajectory 
    k_api::Base::WaypointList wpts = k_api::Base::WaypointList();

    // Binded to degrees of movement and each degrees correspond to one degree of liberty
    auto actuators = base->GetActuatorCount();
    uint32_t degreesOfFreedom = actuators.count();

    // Move arm with waypoints list    
    const int kmaxDegreesOfFreedom = 7;
    auto jointPoses  = std::vector<std::array<float,kmaxDegreesOfFreedom>>();
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Note : To customize this example for your needs an array of array is used containing the information needed :
    // all  values correspond to a joint/motor
    // If you have 6DoF the array will contain 6 positions expressed in degrees in float format.
    // If you have 7DoF the array will contain 7 positions expressed in degrees in float format.
    // You may overwrite the jointPose array for the proper arm
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    if(gen3LiteModelCompatible == true) // Gen3 Lite
    {
        jointPoses.push_back({ 0.0f,  344.0f, 75.0f,  360.0f, 300.0f, 0.0f  });  // Home
        jointPoses.push_back({ 0.0f,  21.0f,  145.0f, 272.0f, 32.0f,  273.0f}); // Retract
        jointPoses.push_back({ 42.0f, 334.0f, 79.0f,  241.0f, 305.0f, 56.0f });// Angular pick down
    }
    else if(degreesOfFreedom == 6) // 6DoF and not Gen3 Lite
    {
        jointPoses.push_back({ 360.0f, 35.6f, 281.8f, 0.8f,   23.8f, 88.9f  });
        jointPoses.push_back({ 359.6f, 49.1f, 272.1f, 0.3f,   47.0f, 89.1f  });
        jointPoses.push_back({ 320.5f, 76.5f, 335.5f, 293.4f, 46.1f, 165.6f });
        jointPoses.push_back({ 335.6f, 38.8f, 266.1f, 323.9f, 49.7f, 117.3f });
        jointPoses.push_back({ 320.4f, 76.5f, 335.5f, 293.4f, 46.1f, 165.6f });
        jointPoses.push_back({ 28.8f,  36.7f, 273.2f, 40.8f,  39.5f, 59.8f  });
        jointPoses.push_back({ 360.0f, 45.6f, 251.9f, 352.2f, 54.3f, 101.0f });
    }
    else                           // 7DoF
    {
        jointPoses.push_back({ 360.0f, 35.6f, 180.7f, 281.8f, 0.8f,   23.8f, 88.9f  });
        jointPoses.push_back({ 359.6f, 49.1f, 181.0f, 272.1f, 0.3f,   47.0f, 89.1f  });
        jointPoses.push_back({ 320.5f, 76.5f, 166.5f, 335.5f, 293.4f, 46.1f, 165.6f });
        jointPoses.push_back({ 335.6f, 38.8f, 177.0f, 266.1f, 323.9f, 49.7f, 117.3f });
        jointPoses.push_back({ 320.4f, 76.5f, 166.5f, 335.5f, 293.4f, 46.1f, 165.6f });
        jointPoses.push_back({ 28.8f,  36.7f, 174.7f, 273.2f, 40.8f,  39.5f, 59.8f  });
        jointPoses.push_back({ 360.0f, 45.6f, 171.0f, 251.9f, 352.2f, 54.3f, 101.0f });        
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    const float firstTime = 5.0f;

    for(auto index = 0; index < jointPoses.size(); ++index)
    {
        k_api::Base::Waypoint *wpt = wpts.add_waypoints();
        if(wpt != nullptr)
        {
            wpt->set_name(std::string("waypoint_") + std::to_string(index));
            k_api::Base::AngularWaypoint *ang = wpt->mutable_angular_waypoint();
            if(ang != nullptr)
            {    
                for(auto angleIndex = 0;angleIndex < degreesOfFreedom; ++angleIndex)
                {
                    ang->add_angles(jointPoses.at(index).at(angleIndex));
                }

                // Joints/motors 5 and 7 are slower and need more time
                if(index == 4 || index == 6)
                {
                    ang->set_duration(firstTime * 6); // min 30 seconds
                }
                else
                {
                    ang->set_duration(firstTime);
                }
            }
        }        
    }

    // Connect to notification action topic
    std::promise<k_api::Base::ActionEvent> finish_promise_cart;
    auto finish_future_cart = finish_promise_cart.get_future();
    auto promise_notification_handle_cart = base->OnNotificationActionTopic( create_event_listener_by_promise(finish_promise_cart),
                                                                            k_api::Common::NotificationOptions());

    k_api::Base::WaypointValidationReport result;
    try
    {
        // Verify validity of waypoints
        auto validationResult = base->ValidateWaypointList(wpts);
        result = validationResult;
    }
    catch(k_api::KDetailedException& ex)
    {
        std::cout << "Try catch error on waypoint list" << std::endl;
        // You can print the error informations and error codes
        auto error_info = ex.getErrorInfo().getError();
        std::cout << "KDetailedoption detected what:  " << ex.what() << std::endl;
        
        std::cout << "KError error_code: " << error_info.error_code() << std::endl;
        std::cout << "KError sub_code: " << error_info.error_sub_code() << std::endl;
        std::cout << "KError sub_string: " << error_info.error_sub_string() << std::endl;

        // Error codes by themselves are not very verbose if you don't see their corresponding enum value
        // You can use google::protobuf helpers to get the string enum element for every error code and sub-code 
        std::cout << "Error code string equivalent: " << k_api::ErrorCodes_Name(k_api::ErrorCodes(error_info.error_code())) << std::endl;
        std::cout << "Error sub-code string equivalent: " << k_api::SubErrorCodes_Name(k_api::SubErrorCodes(error_info.error_sub_code())) << std::endl;
        return false;
    }
    
    // Trajectory error report always exists and we need to make sure no elements are found in order to validate the trajectory
    if(result.trajectory_error_report().trajectory_error_elements_size() == 0)
    {    
        // Execute action
        try
        {
            // Move arm with waypoints list
            std::cout << "Moving the arm creating a trajectory of " << jointPoses.size() << " angular waypoints" << std::endl;
            base->ExecuteWaypointTrajectory(wpts);
        }
        catch(k_api::KDetailedException& ex)
        {
            std::cout << "Try catch error executing normal trajectory" << std::endl;
            // You can print the error informations and error codes
            auto error_info = ex.getErrorInfo().getError();
            std::cout << "KDetailedoption detected what:  " << ex.what() << std::endl;
            
            std::cout << "KError error_code: " << error_info.error_code() << std::endl;
            std::cout << "KError sub_code: " << error_info.error_sub_code() << std::endl;
            std::cout << "KError sub_string: " << error_info.error_sub_string() << std::endl;

            // Error codes by themselves are not very verbose if you don't see their corresponding enum value
            // You can use google::protobuf helpers to get the string enum element for every error code and sub-code 
            std::cout << "Error code string equivalent: " << k_api::ErrorCodes_Name(k_api::ErrorCodes(error_info.error_code())) << std::endl;
            std::cout << "Error sub-code string equivalent: " << k_api::SubErrorCodes_Name(k_api::SubErrorCodes(error_info.error_sub_code())) << std::endl;
            return false;
        }
        // Wait for future value from promise
        const auto ang_status = finish_future_cart.wait_for(TIMEOUT_DURATION);

        base->Unsubscribe(promise_notification_handle_cart);

        if(ang_status != std::future_status::ready)
        {
            std::cout << "Timeout on action notification wait for angular waypoint trajectory" << std::endl;
        }
        else
        {
            const auto ang_promise_event = finish_future_cart.get();
            std::cout << "Angular waypoint trajectory completed" << std::endl;
            std::cout << "Promise value : " << k_api::Base::ActionEvent_Name(ang_promise_event) << std::endl; 

            success = true;

            // We are now ready to reuse the validation output to test default trajectory generated...
            // Here we need to understand that trajectory using angular waypoint is never optimized.
            // In other words the waypoint list is the same and this is a limitation of Kortex API for now
        }
    }
    else
    {
        std::cout << "Error found in trajectory" << std::endl; 
        result.trajectory_error_report().PrintDebugString();        
    }

    return success;
}

bool example_move_to_home_position(k_api::Base::BaseClient* base)
{
    // Make sure the arm is in Single Level Servoing before executing an Action
    auto servoingMode = k_api::Base::ServoingModeInformation();
    servoingMode.set_servoing_mode(k_api::Base::ServoingMode::SINGLE_LEVEL_SERVOING);
    base->SetServoingMode(servoingMode);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Move arm to ready position
    std::cout << "Moving the arm to a safe position" << std::endl;
    auto action_type = k_api::Base::RequestedActionType();
    action_type.set_action_type(k_api::Base::REACH_JOINT_ANGLES);
    auto action_list = base->ReadAllActions(action_type);
    auto action_handle = k_api::Base::ActionHandle();
    action_handle.set_identifier(0);
    
    for (auto action : action_list.action_list()) 
    {
        if (action.name() == "Home") 
        {
            action_handle = action.handle();
        }
    }

    if (action_handle.identifier() == 0) 
    {
        std::cout << "Can't reach safe position, exiting" << std::endl;
        return false;
    } 
    else 
    {
        // Connect to notification action topic
        std::promise<k_api::Base::ActionEvent> finish_promise_cart;
        auto finish_future_cart = finish_promise_cart.get_future();
        auto promise_notification_handle_cart = base->OnNotificationActionTopic(
            create_event_listener_by_promise(finish_promise_cart),
            k_api::Common::NotificationOptions()
        );

        // Execute action
        base->ExecuteActionFromReference(action_handle);


        // Wait for future value from promise
        const auto status = finish_future_cart.wait_for(TIMEOUT_DURATION);
        base->Unsubscribe(promise_notification_handle_cart);

        if(status != std::future_status::ready)
        {
            std::cout << "Timeout on action notification wait" << std::endl;
            return false;
        }
        const auto promise_event = finish_future_cart.get();

        std::cout << "Move to Home completed" << std::endl;
        std::cout << "Promise value : " << k_api::Base::ActionEvent_Name(promise_event) << std::endl; 

        return true;
    }
}


int main(int argc, char **argv)
{
    auto parsed_args = ParseExampleArguments(argc, argv);

    // Create API objects
    auto error_callback = [](k_api::KError err){ cout << "_________ callback error _________" << err.toString(); };
    auto transport = new k_api::TransportClientTcp();
    auto router = new k_api::RouterClient(transport, error_callback);
    transport->connect(parsed_args.ip_address, PORT);

    // Set session data connection information
    auto create_session_info = k_api::Session::CreateSessionInfo();
    create_session_info.set_username(parsed_args.username);
    create_session_info.set_password(parsed_args.password);
    create_session_info.set_session_inactivity_timeout(60000);   // (milliseconds)
    create_session_info.set_connection_inactivity_timeout(2000); // (milliseconds)

    // Session manager service wrapper
    std::cout << "Creating session for communication" << std::endl;
    auto session_manager = new k_api::SessionManager(router);
    session_manager->CreateSession(create_session_info);
    std::cout << "Session created" << std::endl;

    // Create services
    auto base = new k_api::Base::BaseClient(router);
    auto base_cyclic = new k_api::BaseCyclic::BaseCyclicClient(router);

    // Example core
    bool success = true;
    // We need to make sure to be hoome before attemping any trajectory
    success &= example_move_to_home_position(base);
    // This is a trajectory example using angular waypoints
    success &= example_trajectory(base);
    
    // Close API session
    session_manager->CloseSession();

    // Deactivate the router and cleanly disconnect from the transport object
    router->SetActivationStatus(false);
    transport->disconnect();

    // Destroy the API
    delete base;
    delete session_manager;
    delete router;
    delete transport;

    return success? 0: 1;
}