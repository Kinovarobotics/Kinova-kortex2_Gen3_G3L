/*
 * This class initializes the API of a robot with the specified IP address
 */

 #include "api_setup.hpp"
 
 namespace k_api = Kinova::Api;

 
    void Robot::create_api(std::string ip_address, std::string username,std::string password)
    {
        // -----------------------------------------------------------
        // How to create an API with the SessionManager, DeviceConfigClient and BaseClient services
        auto error_callback = [](k_api::KError err){ cout << "_________ callback error _________" << err.toString(); };
        transport_ = new k_api::TransportClientTcp();
        router_ = new k_api::RouterClient(transport_, error_callback);
        transport_->connect(ip_address, PORT);

        transport_real_time_ = new k_api::TransportClientUdp();
        router_real_time_ = new k_api::RouterClient(transport_real_time_, error_callback);
        transport_real_time_->connect(ip_address, PORT_REAL_TIME);

        // Set session data connection information
        auto create_session_info = k_api::Session::CreateSessionInfo();
        create_session_info.set_username(username);
        create_session_info.set_password(password);
        create_session_info.set_session_inactivity_timeout(60000);   // (milliseconds)
        create_session_info.set_connection_inactivity_timeout(2000); // (milliseconds)

        // Session manager service wrapper
        std::cout << "Creating session for communication" << std::endl;
        session_manager_ = new k_api::SessionManager(router_);
        session_manager_->CreateSession(create_session_info);
        session_manager_real_time_ = new k_api::SessionManager(router_real_time_);
        session_manager_real_time_->CreateSession(create_session_info);
        std::cout << "Session created" << std::endl;

        // Create DeviceConfigClient and BaseClient
        device_config_ = new k_api::DeviceConfig::DeviceConfigClient(router_);
        base_ = new k_api::Base::BaseClient(router_);

        
        base_cyclic_ = new k_api::BaseCyclic::BaseCyclicClient(router_real_time_);
        actuator_config_ = new k_api::ActuatorConfig::ActuatorConfigClient(router_);

        interconnect_config_ = new k_api::InterconnectConfig::InterconnectConfigClient(router_);
        device_manager_ = new k_api::DeviceManager::DeviceManagerClient(router_);
        
        // Now you're ready to use the API
 
    }
 
    // -- Constructor -- 
    Robot::Robot(std::string ip_address, std::string username, std::string password ){
        // Initialize all pointers to nullptr to prevent segfault during destruction
        transport_ = nullptr;
        router_ = nullptr;
        session_manager_ = nullptr;
        device_config_ = nullptr;
        base_ = nullptr;
        transport_real_time_ = nullptr;
        router_real_time_ = nullptr;
        base_cyclic_ = nullptr;
        session_manager_real_time_ = nullptr;
        actuator_config_ = nullptr;
        interconnect_config_ = nullptr;
        device_manager_ = nullptr;
        m_gripper_motor_command = nullptr;
        
        ip_address_ = ip_address;
        create_api(ip_address, username, password);
    }

    // -- Destructor -- 
    Robot::~Robot(){

        // After you're done, here's how to tear down the API

        // Close API session
        session_manager_->CloseSession();
        session_manager_real_time_->CloseSession();

        // Deactivate the router and cleanly disconnect from the transport object
        router_->SetActivationStatus(false);
        transport_->disconnect();

        // Destroy the API
        delete base_;
        delete device_config_;
        delete session_manager_;
        delete router_;
        delete transport_;
        delete base_cyclic_;
        delete router_real_time_;
        delete transport_real_time_;
        delete session_manager_real_time_;
        delete actuator_config_;
        delete m_gripper_motor_command;
        delete interconnect_config_;
        delete device_manager_;

    }

    k_api::Base::BaseClient* Robot::getBaseClient() const {
        return base_;
    }
    
    k_api::BaseCyclic::BaseCyclicClient* Robot::getBaseCyclicClient() const {
        return base_cyclic_;
    }

    k_api::ActuatorConfig::ActuatorConfigClient* Robot::getActuatorConfig() const {
        return actuator_config_;
    }

    k_api::DeviceManager::DeviceManagerClient* Robot::getDeviceManager() const {
        return device_manager_;
    }

    k_api::InterconnectConfig::InterconnectConfigClient* Robot::getInterconnectConfig() const {
        return interconnect_config_;
    }

