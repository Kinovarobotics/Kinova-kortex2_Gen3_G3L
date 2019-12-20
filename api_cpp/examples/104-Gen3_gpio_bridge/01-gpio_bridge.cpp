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

/*
* 104-Gen3_gpio_bridge/gpio_bridge.cpp
*
* Usage example for the GPIO Expansion IO on the Gen3 Interconnect module.
*
* PHYSICAL SETUP:
* =========
* For this example to work, you will have to :
*    - Connect the GPIO_IO1 and GPIO_IO2 Interconnect pins to two input digital pins on your micro-controller
*    - Connect the GPIO_IO3 and GPIO_IO4 Interconnect pins to two output digital pins on your micro-controller
*    - Modify the Arduino code so the ROBOT_PIN_X variables correspond to your pin numbers
*    - Power on the micro-controller and upload the arduino_gpio_example_firmware.ino
*
* We used a MSP432 Launchpad (http://www.ti.com/tool/MSP-EXP432P401R) and made the connections:
*    - GPIO_IO1 -------------- Pin 23
*    - GPIO_IO2 -------------- Pin 24
*    - GPIO_IO3 -------------- Pin 29
*    - GPIO_IO4 -------------- Pin 30
*
* You can also use any Arduino board and this example will work as long as you specify the right pin numbers in the Arduino code. 
*
* DESCRIPTION OF CURRENT EXAMPLE:
* ===============================
* In this example, the GPIO bridge class encapsulates all necessary Kortex API
* objects and implements the functions to setup the GPIO, write to two pins and read back from two other pins.
* The Arduino reads from GPIO_IO1 and writes to pin GPIO_IO3 and reads from GPIO_IO2 and writes to pin GPIO_IO4.
* Essentially, what is written on pin GPIO_IO1 is read back on pin GPIO_IO3 and the same applies for pins GPIO_IO2
* and GPIO_IO4. 
* 
* The Init function creates the Kortex API objects and connects to the arm.
*
* The InitGpioInputsAndOutputs function uses the appropriate RPCs to activate the bridge as well as setup the pins
* either as output (GPIO_IDENTIFIER_1 and GPIO_IDENTIFIER_2) or as input pullup (GPIO_IDENTIFIER_3 and GPIO_IDENTIFIER_4).
* 
* The SetOutputPinValue function writes a logical value to a designated output pin.
*
* The ReadInputPinValue function reads a logical value from a designated input pin.
*
* The main function :
*   - Initializes the GpioBridge object
*   - Writes to pins GPIO_IO1 and GPIO_IO2
*   - Reads and prints the values read from GPIO_IO3 and GPIO_IO4
*/

#include <BaseClientRpc.h>
#include <InterconnectConfigClientRpc.h>
#include <SessionManager.h>
#include <DeviceManagerClientRpc.h>
#include <RouterClient.h>
#include <TransportClientTcp.h>
#include <thread>
#include <iostream>
#include <chrono>

namespace k_api = Kinova::Api;

#define IP_ADDRESS "192.168.1.10"
#define PORT 10000

///////////////////////////////////////////////////////////////////////
// class GpioBridge
//
// Implements methods for establishing and operating GPIO bridge through
// the base.
///////////////////////////////////////////////////////////////////////

class GpioBridge
{
public:
    GpioBridge(const std::string& ip_address, int port, const std::string& username = "admin", const std::string& password = "admin"):
    m_ip_address(ip_address), m_username(username), m_password(password), m_port(port), m_interconnect_device_id(0)
    {
        m_router              = nullptr;
        m_transport           = nullptr;
        m_session_manager     = nullptr;
        m_device_manager      = nullptr;
        m_interconnect_config = nullptr;
    }

    ~GpioBridge()
    {
        // Close API session
        m_session_manager->CloseSession();

        // Deactivate the router and cleanly disconnect from the transport object
        m_router->SetActivationStatus(false);
        m_transport->disconnect();

        // Destroy the API
        delete m_interconnect_config;
        delete m_device_manager;
        delete m_session_manager;
        delete m_router;
        delete m_transport;
    }

    void Init()
    {
        m_transport = new k_api::TransportClientTcp();
        m_transport->connect(m_ip_address, m_port);

        m_router = new k_api::RouterClient(m_transport, [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); });
        
        // Set session data connection information
        auto createSessionInfo = k_api::Session::CreateSessionInfo();
        createSessionInfo.set_username(m_username);
        createSessionInfo.set_password(m_password);
        createSessionInfo.set_session_inactivity_timeout(60000);   // (milliseconds)
        createSessionInfo.set_connection_inactivity_timeout(2000); // (milliseconds)

        // Session manager service wrapper
        m_session_manager = new k_api::SessionManager(m_router);
        m_session_manager->CreateSession(createSessionInfo);

        // Create services
        m_device_manager      = new k_api::DeviceManager::DeviceManagerClient(m_router);
        m_interconnect_config = new k_api::InterconnectConfig::InterconnectConfigClient(m_router);

        m_interconnect_device_id = GetDeviceIdFromDevType(k_api::Common::INTERCONNECT, 0);
    }

    uint32_t GetDeviceIdFromDevType(k_api::Common::DeviceTypes device_type, uint32_t device_index)
    {
        auto device_handles = m_device_manager->ReadAllDevices();
        uint32_t current_index = 0;
        for (auto device_handle : device_handles.device_handle() )
        {
            if (device_handle.device_type() == device_type)
            {
                if (current_index == device_index)
                {
                    return device_handle.device_identifier();
                }
                ++current_index;
            }
        }
        return 0;
    }

    // This function sets pins 1 and 2 as output and pins 3 and 4 as input pullup
    void InitGpioInputsAndOutputs()
    {
        k_api::InterconnectConfig::GPIOConfiguration gpio_config;

        // Pins 1 and 2 as output
        gpio_config.set_mode(k_api::InterconnectConfig::GPIO_MODE_OUTPUT_PUSH_PULL);
        gpio_config.set_pull(k_api::InterconnectConfig::GPIO_PULL_NONE);
        gpio_config.set_default_value(k_api::InterconnectConfig::GPIO_VALUE_LOW);
        gpio_config.set_identifier(k_api::InterconnectConfig::GPIO_IDENTIFIER_1);
        std::cout << "Setting pin #1 as output..." << std::endl;
        m_interconnect_config->SetGPIOConfiguration(gpio_config, m_interconnect_device_id);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        gpio_config.set_identifier(k_api::InterconnectConfig::GPIO_IDENTIFIER_2);
        std::cout << "Setting pin #2 as output..." << std::endl;
        m_interconnect_config->SetGPIOConfiguration(gpio_config, m_interconnect_device_id);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // Pins 3 and 4 as input pullup
        gpio_config.set_mode(k_api::InterconnectConfig::GPIO_MODE_INPUT_FLOATING);
        gpio_config.set_pull(k_api::InterconnectConfig::GPIO_PULL_UP);
        gpio_config.set_identifier(k_api::InterconnectConfig::GPIO_IDENTIFIER_3);
        std::cout << "Setting pin #3 as input pullup..." << std::endl;
        m_interconnect_config->SetGPIOConfiguration(gpio_config, m_interconnect_device_id);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        gpio_config.set_identifier(k_api::InterconnectConfig::GPIO_IDENTIFIER_4);
        std::cout << "Setting pin #4 as input pullup..." << std::endl;
        m_interconnect_config->SetGPIOConfiguration(gpio_config, m_interconnect_device_id);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    void SetOutputPinValue(k_api::InterconnectConfig::GPIOIdentifier gpio_identifier, k_api::InterconnectConfig::GPIOValue gpio_value)
    {
        k_api::InterconnectConfig::GPIOState state;
        state.set_identifier(gpio_identifier);
        state.set_value(gpio_value);
        std::cout << "GPIO pin " << k_api::InterconnectConfig::GPIOIdentifier_Name(gpio_identifier) 
        << " will be put at value " << k_api::InterconnectConfig::GPIOValue_Name(gpio_value) << std::endl;
        m_interconnect_config->SetGPIOState(state, m_interconnect_device_id);
    }

    uint32_t ReadInputPinValue(k_api::InterconnectConfig::GPIOIdentifier gpio_identifier)
    {
        k_api::InterconnectConfig::GPIOIdentification gpio_identification;
        gpio_identification.set_identifier(gpio_identifier);
        k_api::InterconnectConfig::GPIOState state = m_interconnect_config->GetGPIOState(gpio_identification, m_interconnect_device_id);
        if (state.value() == k_api::InterconnectConfig::GPIO_VALUE_HIGH)
        {
            return 1;
        }
        else if (state.value() == k_api::InterconnectConfig::GPIO_VALUE_LOW)
        {
            return 0;
        }
        else
        {
            std::cout << "Error : the value read is unspecified" << std::endl;
            return -1;
        }
    } 

private:
    k_api::RouterClient*                                    m_router;
    k_api::TransportClientTcp*                              m_transport;
    k_api::SessionManager*                                  m_session_manager;
    k_api::DeviceManager::DeviceManagerClient*              m_device_manager;
    k_api::InterconnectConfig::InterconnectConfigClient*    m_interconnect_config;

    std::string                                             m_username;
    std::string                                             m_password;
    std::string                                             m_ip_address;
    int                                                     m_port;
    uint32_t                                                m_interconnect_device_id;
    static const std::vector<k_api::InterconnectConfig::GPIOIdentifier>  m_gpio_const_id;
};

const std::vector<k_api::InterconnectConfig::GPIOIdentifier> GpioBridge::m_gpio_const_id = {
    k_api::InterconnectConfig::GPIO_IDENTIFIER_1,
    k_api::InterconnectConfig::GPIO_IDENTIFIER_2,
    k_api::InterconnectConfig::GPIO_IDENTIFIER_3,
    k_api::InterconnectConfig::GPIO_IDENTIFIER_4
};

// Example core
int main(int argc, char **argv)
{
    GpioBridge* gpio_bridge;
    gpio_bridge = new GpioBridge(IP_ADDRESS , PORT, "admin", "admin");
    gpio_bridge->Init();

    gpio_bridge->InitGpioInputsAndOutputs();
    std::cout << "GPIO bridge object initialized" << std::endl;

    // We sleep a bit between the reads and the writes
    // The InterconnectConfig service runs at 25ms but we sleep 100ms to make sure we let enough time
    uint32_t sleep_time_ms = 100;

    // The Arduino reads pin 1 and sets pin 3 the same
    // The Arduino reads pin 2 and sets pin 4 the same
    gpio_bridge->SetOutputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_1, k_api::InterconnectConfig::GPIO_VALUE_HIGH);
    gpio_bridge->SetOutputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_2, k_api::InterconnectConfig::GPIO_VALUE_LOW);
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time_ms));
    uint32_t pin3_in = gpio_bridge->ReadInputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_3); // should be HIGH
    uint32_t pin4_in = gpio_bridge->ReadInputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_4); // should be LOW
    std::cout << "Value read for pin #3 is : " << pin3_in << std::endl;
    std::cout << "Value read for pin #4 is : " << pin4_in << std::endl;

    gpio_bridge->SetOutputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_1, k_api::InterconnectConfig::GPIO_VALUE_LOW);
    gpio_bridge->SetOutputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_2, k_api::InterconnectConfig::GPIO_VALUE_HIGH);
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time_ms));
    pin3_in = gpio_bridge->ReadInputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_3); // should be LOW
    pin4_in = gpio_bridge->ReadInputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_4); // should be HIGH
    std::cout << "Value read for pin #3 is : " << pin3_in << std::endl;
    std::cout << "Value read for pin #4 is : " << pin4_in << std::endl;

    gpio_bridge->SetOutputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_1, k_api::InterconnectConfig::GPIO_VALUE_HIGH);
    gpio_bridge->SetOutputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_2, k_api::InterconnectConfig::GPIO_VALUE_HIGH);
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time_ms));
    pin3_in = gpio_bridge->ReadInputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_3); // should be HIGH
    pin4_in = gpio_bridge->ReadInputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_4); // should be HIGH
    std::cout << "Value read for pin #3 is : " << pin3_in << std::endl;
    std::cout << "Value read for pin #4 is : " << pin4_in << std::endl;

    gpio_bridge->SetOutputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_1, k_api::InterconnectConfig::GPIO_VALUE_LOW);
    gpio_bridge->SetOutputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_2, k_api::InterconnectConfig::GPIO_VALUE_LOW);
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time_ms));
    pin3_in = gpio_bridge->ReadInputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_3); // should be LOW
    pin4_in = gpio_bridge->ReadInputPinValue(k_api::InterconnectConfig::GPIO_IDENTIFIER_4); // should be LOW
    std::cout << "Value read for pin #3 is : " << pin3_in << std::endl;
    std::cout << "Value read for pin #4 is : " << pin4_in << std::endl;

    delete gpio_bridge;

    return 0;
};