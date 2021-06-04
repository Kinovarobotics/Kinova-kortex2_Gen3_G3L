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

#include "utilities.h"

#define PORT 10000

namespace k_api = Kinova::Api;

// Maximum allowed waiting time during actions
constexpr auto TIMEOUT_DURATION = std::chrono::seconds{60};

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

static constexpr int kWaypointNumber = 7;
static constexpr int kNumberOfVariables = 4; // x, y, z, blending radius
static constexpr int posX = 0;
static constexpr int posY = 1;
static constexpr int posZ = 2;
static constexpr int posBlendingRadius = 3;
static constexpr int posThetaX = 4;
static constexpr int posThetaY = 5;
static constexpr int posThetaZ = 6;

// Helper function to populate Cartesian waypoint
void populateCartesianCoordinate(k_api::Base::CartesianWaypoint* cartesianCoordinate, std::vector<float> waypointDefinition)
{    
    static const k_api::Common::CartesianReferenceFrame kReferenceFrame = k_api::Common::CartesianReferenceFrame::CARTESIAN_REFERENCE_FRAME_BASE;
 

    cartesianCoordinate->mutable_pose()->set_x(waypointDefinition[posX]);
    cartesianCoordinate->mutable_pose()->set_y(waypointDefinition[posY]);
    cartesianCoordinate->mutable_pose()->set_z(waypointDefinition[posZ]);
    cartesianCoordinate->set_blending_radius(waypointDefinition[posBlendingRadius]);

    cartesianCoordinate->mutable_pose()->set_theta_x(waypointDefinition[posThetaX]);
    cartesianCoordinate->mutable_pose()->set_theta_y(waypointDefinition[posThetaY]);
    cartesianCoordinate->mutable_pose()->set_theta_z(waypointDefinition[posThetaZ]);    


    cartesianCoordinate->set_reference_frame(kReferenceFrame);
}

bool example_trajectory(k_api::Base::BaseClient* base)
{
    bool success = false;
    std::vector<std::vector<float>> waypointsDefinition;
    auto product = base->GetProductConfiguration();
    if(   product.model() == k_api::ProductConfiguration::MODEL_ID_L53 
       || product.model() == k_api::ProductConfiguration::MODEL_ID_L31)
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Note : To customize this example for your needs an array of array is used containing the information needed :
        // 1 - x position
        // 2 - y position
        // 3 - z position
        // 4 - blending radius
        // 5 - Theta x
        // 6 - Theta y
        // 7 - Theta z
        // You may overwrite the waypointsDefinition vector by commenting the code bellow and populating it with your own
        // waypoint list information.
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(product.model() == k_api::ProductConfiguration::MODEL_ID_L31)
        {
            // Detected a PICO model
            const float kTheta_x = 90.6;
            const float kTheta_y = -1.0;
            const float kTheta_z = 150.0;
            waypointsDefinition = { {0.439f,  0.194f, 0.448f, 0.0f, kTheta_x, kTheta_y, kTheta_z},
                                    {0.200f,  0.150f, 0.400f, 0.0f, kTheta_x, kTheta_y, kTheta_z},
                                    {0.350f,  0.050f, 0.300f, 0.0f, kTheta_x, kTheta_y, kTheta_z}};
        }
        else
        {
            const float kTheta_x = 90.0;
            const float kTheta_y = 0.0;
            const float kTheta_z = 90.0;
            waypointsDefinition = { {0.7f,   0.0f,  0.5f,  0.0f, kTheta_x, kTheta_y, kTheta_z},
                                    {0.7f,   0.0f,  0.33f, 0.1f, kTheta_x, kTheta_y, kTheta_z},
                                    {0.7f,   0.48f, 0.33f, 0.1f, kTheta_x, kTheta_y, kTheta_z},
                                    {0.61f,  0.22f, 0.4f,  0.1f, kTheta_x, kTheta_y, kTheta_z},
                                    {0.7f,   0.48f, 0.33f, 0.1f, kTheta_x, kTheta_y, kTheta_z},
                                    {0.63f, -0.22f, 0.45f, 0.1f, kTheta_x, kTheta_y, kTheta_z},
                                    {0.65f,  0.05f, 0.33f, 0.0f, kTheta_x, kTheta_y, kTheta_z}};
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
    wpts.set_duration(0.0); // as fast as possible
    wpts.set_use_optimal_blending(false);

    // Start waypoint list creation
    int index  = 0;
    for(std::vector<std::vector<float>>::iterator it = waypointsDefinition.begin(); 
        it != waypointsDefinition.end(); ++it, ++index) 
    {
        k_api::Base::Waypoint *wpt = wpts.add_waypoints();
        if(wpt != nullptr)
        {
            wpt->set_name(std::string("waypoint_") + std::to_string(index));
            Kinova::Api::Base::CartesianWaypoint* coordinate = wpt->mutable_cartesian_waypoint();
            if(coordinate != nullptr)
            {
                populateCartesianCoordinate(coordinate, *it);
            }
        }
    }

    // Connect to notification action topic
    std::promise<k_api::Base::ActionEvent> finish_promise_cart;
    auto finish_future_cart = finish_promise_cart.get_future();
    auto promise_notification_handle_cart_end = base->OnNotificationActionTopic( create_event_listener_by_promise(finish_promise_cart),
                                                                            k_api::Common::NotificationOptions());

    // Verify validity of waypoints
    auto result = base->ValidateWaypointList(wpts);

    if(result.trajectory_error_report().trajectory_error_elements_size() == 0)
    {   
        // Execute action
        try
        {
            // Move arm with waypoints list
            std::cout << "Moving the arm creating a trajectory of " << waypointsDefinition.size() << " cartesian waypoints" << std::endl;
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
        const auto cart_end_status = finish_future_cart.wait_for(TIMEOUT_DURATION);

        base->Unsubscribe(promise_notification_handle_cart_end);

        if(cart_end_status != std::future_status::ready)
        {
            std::cout << "Timeout on action notification wait for cartesian waypoint trajectory" << std::endl;
        }
        else
        {
            const auto cart_promise_event = finish_future_cart.get();
            std::cout << "cartesian waypoint trajectory completed" << std::endl;
            std::cout << "Promise value : " << k_api::Base::ActionEvent_Name(cart_promise_event) << std::endl; 

            // Connect to notification action topic
            std::promise<k_api::Base::ActionEvent> finish_promise_cart_opt;
            auto finish_future_cart_opt = finish_promise_cart_opt.get_future();
            
            auto promise_notification_handle_cart_opt = base->OnNotificationActionTopic(create_event_listener_by_promise(finish_promise_cart_opt),
                                                                                    k_api::Common::NotificationOptions());

            // Execute optimized trajectory
            wpts.set_use_optimal_blending(true);
            try
            {
                base->ExecuteWaypointTrajectory(wpts);
            }
            catch(k_api::KDetailedException& ex)
            {
                std::cout << "Try catch error executing optimized trajectory" << std::endl;
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
            const auto cart_status = finish_future_cart_opt.wait_for(TIMEOUT_DURATION);
            base->Unsubscribe(promise_notification_handle_cart_opt);
            if(cart_status != std::future_status::ready)
            {
                std::cout << "Timeout on action notification wait for optimized cartesian waypoint trajectory" << std::endl;
            }
            else
            {
                const auto opt_cart_promise_event = finish_future_cart_opt.get();
                std::cout << "Optimized cartesian waypoint trajectory completed" << std::endl;
                std::cout << "Promise value : " << k_api::Base::ActionEvent_Name(opt_cart_promise_event) << std::endl; 
                success = true;
            }
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

    // Example core
    bool success = true;
    // We need to make sure to be hoome before attemping any trajectory
    success &= example_move_to_home_position(base);
    // This is a trajectory example using cartesian waypoints
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