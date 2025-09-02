#ifndef API_SETUP_H 
#define API_SETUP_H

#include <string> 

#include <SessionManager.h>
#include <DeviceConfigClientRpc.h>
#include <BaseClientRpc.h>

#include <RouterClient.h>
#include <TransportClientTcp.h>

#include <BaseCyclicClientRpc.h>
#include <SessionClientRpc.h>
#include <TransportClientUdp.h>
#include <KDetailedException.h>
#include <ActuatorConfigClientRpc.h>

#define PORT 10000
#define PORT_REAL_TIME 10001

namespace k_api = Kinova::Api;

class Robot {
private:
    // --- Member Variables ---
    std::string ip_address_;
    k_api::TransportClientTcp *transport_;
    k_api::RouterClient *router_;
    k_api::SessionManager *session_manager_;
    k_api::DeviceConfig::DeviceConfigClient *device_config_;
    k_api::Base::BaseClient *base_;
    k_api::TransportClientUdp *transport_real_time_;
    k_api::RouterClient *router_real_time_;
    k_api::BaseCyclic::BaseCyclicClient *base_cyclic_;
    k_api::SessionManager *session_manager_real_time_;
    k_api::ActuatorConfig::ActuatorConfigClient *actuator_config_;
    

    // --- Private Member Function Declaration ---
    // Only DECLARE it here. The definition (body) goes in the .cpp file.
    void create_api(std::string ip_address, std::string username, std::string password);

public:
    // --- Constructor Declaration ---
    Robot(std::string ip_address, std::string username, std::string password);

    // --- Destructor Declaration ---
    ~Robot();

    // --- Getter Declarations ---
    // Added getter for base_
    k_api::Base::BaseClient* getBaseClient() const;

    // Added getter for base_cyclic_
    k_api::BaseCyclic::BaseCyclicClient* getBaseCyclicClient() const;

    // Added getter for actuator_config_
    k_api::ActuatorConfig::ActuatorConfigClient* getActuatorConfig() const;


}; 

#endif 