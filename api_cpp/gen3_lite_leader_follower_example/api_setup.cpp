/*
 * This class initializes the API of a robot with the specified IP address
 */

 #include "api_setup.hpp"
 
 namespace k_api = Kinova::Api;

 
    void Robot::create_api(std::string ip_address, std::string username,std::string password)
    {
        // -----------------------------------------------------------
        // Initialize Kinova API with TCP and UDP transport layers
        // -----------------------------------------------------------
        
        // Define error callback function to handle API errors
        auto error_callback = [](k_api::KError err){ cout << "_________ callback error _________" << err.toString(); };
        // Create TCP transport and router for standard API communication
        transport_ = new k_api::TransportClientTcp();
        router_ = new k_api::RouterClient(transport_, error_callback);
        transport_->connect(ip_address, PORT);

        // Create UDP transport and router for real-time communication (faster, lower latency)
        transport_real_time_ = new k_api::TransportClientUdp();
        router_real_time_ = new k_api::RouterClient(transport_real_time_, error_callback);
        transport_real_time_->connect(ip_address, PORT_REAL_TIME);

        // Configure session parameters for authentication and timeout settings
        auto create_session_info = k_api::Session::CreateSessionInfo();
        create_session_info.set_username(username);
        create_session_info.set_password(password);
        create_session_info.set_session_inactivity_timeout(60000);   // Session timeout: 60 seconds
        create_session_info.set_connection_inactivity_timeout(2000); // Connection timeout: 2 seconds

        // Create session managers for both TCP and UDP connections
        std::cout << "Creating session for communication" << std::endl;
        session_manager_ = new k_api::SessionManager(router_);
        session_manager_->CreateSession(create_session_info);
        session_manager_real_time_ = new k_api::SessionManager(router_real_time_);
        session_manager_real_time_->CreateSession(create_session_info);
        std::cout << "Session created" << std::endl;

        // Initialize API client services for robot control
        device_config_ = new k_api::DeviceConfig::DeviceConfigClient(router_);  // Device configuration
        base_ = new k_api::Base::BaseClient(router_);                          // Base robot control

        // Initialize real-time and actuator clients
        base_cyclic_ = new k_api::BaseCyclic::BaseCyclicClient(router_real_time_);  // Real-time cyclic data
        actuator_config_ = new k_api::ActuatorConfig::ActuatorConfigClient(router_); // Actuator configuration
        
        // API initialization complete - ready for robot operations
 
    }
 
    // -- Constructor -- 
    // Initialize Robot object and establish API connection
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
        
        ip_address_ = ip_address;
        create_api(ip_address, username, password);
    }

    // -- Destructor -- 
    // Clean up all API resources and close connections
    Robot::~Robot(){

        // Properly tear down the API connection

        // Close both TCP and UDP API sessions
        
        session_manager_->CloseSession();
        
        
        session_manager_real_time_->CloseSession();
        

        // Deactivate router and disconnect from transport layer
        
        router_->SetActivationStatus(false);
        
       
        transport_->disconnect();
        

        // Free all allocated API client objects with null pointer checks
        
        delete base_;
        base_ = nullptr;
        
      
        delete device_config_;
        device_config_ = nullptr;
        
     
        delete base_cyclic_;
        base_cyclic_ = nullptr;
  
        delete actuator_config_;
        actuator_config_ = nullptr;
        
       
        delete session_manager_;
        session_manager_ = nullptr;
        

        delete session_manager_real_time_;
        session_manager_real_time_ = nullptr;
        
        
        delete router_;
        router_ = nullptr;
        
       
        delete router_real_time_;
        router_real_time_ = nullptr;
        

        delete transport_;
        transport_ = nullptr;
        
    
        delete transport_real_time_;
        transport_real_time_ = nullptr;
        

    }

    // Return pointer to base client for robot control operations
    k_api::Base::BaseClient* Robot::getBaseClient() const {
        return base_;
    }
    
    // Return pointer to base cyclic client for real-time data exchange
    k_api::BaseCyclic::BaseCyclicClient* Robot::getBaseCyclicClient() const {
        return base_cyclic_;
    }

    // Return pointer to actuator config client for actuator-specific settings
    k_api::ActuatorConfig::ActuatorConfigClient* Robot::getActuatorConfig() const {
        return actuator_config_;
    }

