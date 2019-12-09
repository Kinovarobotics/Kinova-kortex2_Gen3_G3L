/*
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2019 Kinova inc. All rights reserved.
*
* This software may be modified and distributed
* under the terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
*/

/*
* 105-Gen3_i2c_bridge/i2c_bridge.cpp
*
* Usage example for the I2C Expansion IO on the Gen3 Interconnect module.
*
* PHYSICAL SETUP:
* =========
*
* We used a I2C IO Extender PCA9505 for this example (https://www.nxp.com/docs/en/data-sheet/PCA9505_9506.pdf) and made the connections:
*    - SDA -------------- Pin 1
*    - SCL -------------- Pin 2
*    - DC --------------- Pins 18, 46, 86
*    - GND -------------- Pins 6, 11, 23, 27, 28, 29, 34, 39, 51
*
* DESCRIPTION OF CURRENT EXAMPLE:
* ===============================
* In this example, the I2C bridge class encapsulates all necessary Kortex API
* objects and implements the functions to setup the I2C, write to the bus and read from the bus.
* Upon a read request, the IO Extender supplies the input values read from the bank 0 pins (IO0_X pins from page 5 of the datasheet)
* The IO Extender can take configuration commands from write requests and the register values are supplied in the data sheet.
* 
* For this example, we first read the values of IO0_X pins, then invert the polarity on half of the pins and read them again.
* 
* The Init function creates the Kortex API objects and connects to the arm.
*
* The Configure function uses the appropriate RPC to activate the bridge with the desired settings.
* 
* The WriteValue function writes a request to the bus.
*
* The ReadValue function initiates a read request to the bus.
*
* The main function :
*   - Initializes the I2CBridge object
*   - Creates and sends a read request to read from the bank 0 pins on the IO Extender
*   - Creates and sends a write request to invert the polarity of half the bank 0 pins on the IO Extender
*   - Creates and sends a read request to read from the bank 0 pins on the IO Extender (which will not give the same output as the first request)
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
#include <bitset>

namespace k_api = Kinova::Api;

#define IP_ADDRESS "192.168.1.10"
#define PORT 10000

///////////////////////////////////////////////////////////////////////
// class I2CBridge
//
// Implements methods for establishing and operating I2C bridge through
// the base.
///////////////////////////////////////////////////////////////////////

class I2CBridge
{
public:
    I2CBridge(const std::string& ip_address, int port, const std::string& username = "admin", const std::string& password = "admin"):
    m_ip_address(ip_address), m_username(username), m_password(password), m_port(port)
    {
        m_router              = nullptr;
        m_transport           = nullptr;
        m_session_manager     = nullptr;
        m_device_manager      = nullptr;
        m_interconnect_config = nullptr;
        
        m_is_init = true;
    }

    ~I2CBridge()
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
        m_device_manager = new k_api::DeviceManager::DeviceManagerClient(m_router);
        m_interconnect_config = new k_api::InterconnectConfig::InterconnectConfigClient(m_router);

        m_interconnect_device_id = GetDeviceIdFromDevType(k_api::Common::INTERCONNECT, 0);
        m_is_init = true;
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

    bool WriteValue(uint32_t device_address, const char* value, uint32_t value_length, uint32_t timeout_ms)
    {
        if (m_is_init == false)
        {
            return false;
        }
        if (value == nullptr)
        {
            return false;
        }

        k_api::InterconnectConfig::I2CWriteParameter i2c_write_request;
        i2c_write_request.set_device(k_api::InterconnectConfig::I2C_DEVICE_EXPANSION);
        i2c_write_request.set_device_address(device_address);
        i2c_write_request.set_timeout(timeout_ms);
        k_api::InterconnectConfig::I2CData* i2c_data = i2c_write_request.mutable_data();

        i2c_data->set_data(value, value_length);
        i2c_data->set_size(value_length);
        m_interconnect_config->I2CWrite(i2c_write_request, m_interconnect_device_id);
        return true;
    }

    bool ReadValue(uint32_t device_address, uint32_t bytes_to_read, uint32_t timeout_ms)
    {
        if (m_is_init == false)
        {
            return false;
        }

        k_api::InterconnectConfig::I2CReadParameter i2c_read_request;
        i2c_read_request.set_device(k_api::InterconnectConfig::I2C_DEVICE_EXPANSION);
        i2c_read_request.set_device_address(device_address);
        i2c_read_request.set_size(bytes_to_read);
        i2c_read_request.set_timeout(timeout_ms);

        k_api::InterconnectConfig::I2CData read_data = m_interconnect_config->I2CRead(i2c_read_request, m_interconnect_device_id);
        std::string data = read_data.data();
        std::cout << "We were supposed to read " << bytes_to_read << " bytes and we read " << read_data.size() << " bytes." << std::endl;
        std::cout << "The data is : ";
        for (auto c : data)
        {
            std::cout << std::bitset<8>(c);
        }
        std::cout << std::endl;

        return true;

    }

    bool Configure(bool is_enabled, k_api::InterconnectConfig::I2CMode mode, k_api::InterconnectConfig::I2CDeviceAddressing addressing)
    {
        if (m_is_init == false)
        {
            return false;
        }

        k_api::InterconnectConfig::I2CConfiguration i2c_config;

        i2c_config.set_device(k_api::InterconnectConfig::I2C_DEVICE_EXPANSION);
        i2c_config.set_enabled(is_enabled);
        i2c_config.set_mode(mode);
        i2c_config.set_addressing(addressing);
        m_interconnect_config->SetI2CConfiguration(i2c_config, m_interconnect_device_id);
        return true;
    }


private:
    k_api::RouterClient*                                    m_router;
    k_api::TransportClientTcp*                              m_transport;
    k_api::SessionManager*                                  m_session_manager;
    k_api::DeviceManager::DeviceManagerClient*              m_device_manager;
    k_api::InterconnectConfig::InterconnectConfigClient*    m_interconnect_config;
    bool        m_is_init;
    std::string m_username;
    std::string m_password;
    std::string m_ip_address;
    int         m_port;
    uint32_t    m_interconnect_device_id;
};

// Example core
// Implements a sample I2C bridge application
int main(int argc, char **argv)
{
    I2CBridge* i2c_bridge;
    i2c_bridge = new I2CBridge(IP_ADDRESS, PORT, "admin", "admin");

    // This has to match the device's slave address (see data sheet)
    int slave_address = 0x20;
    
    i2c_bridge->Init();
    i2c_bridge->Configure(true, k_api::InterconnectConfig::I2C_MODE_FAST, k_api::InterconnectConfig::I2C_DEVICE_ADDRESSING_7_BITS);

    std::cout << "I2C bridge object initialized" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // Read the state of the pins in bank 0
    std::cout << "Reading byte array from interconnect I2C bus..." << std::endl;
    try
    {
        uint32_t bytes_to_read = 1;
        i2c_bridge->ReadValue(slave_address, bytes_to_read, 100);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Send byte array to inverse polarity on half the pins
    std::cout << "Sending byte array to interconnect I2C bus..." << std::endl;
    try
    {
        // By looking at the data sheet, we see that to write to the polarity register, 
        // we have to send command register 0x10 as the first byte, then our data byte
        const uint8_t buf[] = {0x10, 0xAA};

        i2c_bridge->WriteValue(0x20, (char*)buf, sizeof(buf), 100);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Read the state of the pins in bank 0
    // Half of them should be inverted now
    std::cout << "Reading byte array from interconnect I2C bus..." << std::endl;
    try
    {
        uint32_t bytes_to_read = 1;
        i2c_bridge->ReadValue(slave_address, bytes_to_read, 100);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    delete i2c_bridge;

    return 0;
};
