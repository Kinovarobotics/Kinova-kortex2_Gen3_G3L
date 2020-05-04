//
// Created by mleroux on 2020-05-04.
//

#include "Classes/include/KortexRobot.h"

KortexRobot::KortexRobot(const string &IP)
{
    m_sIP = IP;
}

KortexRobot::~KortexRobot()
{

    if (m_bIsConnected)
    {
        m_pSessionManager->CloseSession();

        // Deactivate the router and cleanly disconnect from the transport object
        m_pRouterClient->SetActivationStatus(false);
        m_pTcpClient->disconnect();
    }

    // Destroy the API
    delete m_pBase;
    delete m_pDeviceConfigClient;
    delete m_pSessionManager;
    delete m_pRouterClient;
    delete m_pTcpClient;

}

bool KortexRobot::Init()
{
    //Connect the API to the robot

    auto error_callback = [](Kinova::Api::KError err){ cout << "_________ callback error _________" << err.toString(); };
    m_pTcpClient = new Kinova::Api::TransportClientTcp();
    m_pRouterClient = new Kinova::Api::RouterClient(m_pTcpClient, error_callback);
    if(!m_pTcpClient->connect(m_sIP, 10000))
    {
        std::cout<<"Failed to connect"<<std::endl;
        return false;
    }
    try {
        //Log in with a session
        m_pSessionManager = new Kinova::Api::SessionManager(m_pRouterClient);
        auto create_session_info = Kinova::Api::Session::CreateSessionInfo();
        create_session_info.set_username("admin");
        create_session_info.set_password("admin");
        create_session_info.set_session_inactivity_timeout(60000);   // (milliseconds)
        create_session_info.set_connection_inactivity_timeout(2000); // (milliseconds)
        m_pSessionManager->CreateSession(create_session_info);

        m_bIsConnected = true;

        //Access devices
        m_pDeviceConfigClient = new Kinova::Api::DeviceConfig::DeviceConfigClient(m_pRouterClient);
        m_pBase = new Kinova::Api::Base::BaseClient(m_pRouterClient);
    }
    catch(Kinova::Api::KDetailedException& ex)
    {
        OnError(ex);
    }
    return true;
}

void KortexRobot::SubscribeToNotifications() {

    if(~m_bIsConnected)
    {
        return;
    }
    //Action notifications
    Kinova::Api::Common::NotificationOptions options;
    options.set_type(Kinova::Api::Common::NOTIFICATION_TYPE_EVENT);

    using namespace std::placeholders;

    std::function<void(Kinova::Api::Base::ActionNotification)> actionCallback = std::bind(&KortexRobot::OnActionNotificationCallback, this, _1);
    auto handle = m_pBase->OnNotificationActionTopic(actionCallback,options);
    m_NotificationHandleList.push_back(handle);
}

void KortexRobot::OnError(Kinova::Api::KDetailedException &ex)
{
    // You can print the error information and error codes
    auto error_info = ex.getErrorInfo().getError();
    std::cout << "KDetailedoption detected what:  " << ex.what() << std::endl;

    std::cout << "KError error_code: " << error_info.error_code() << std::endl;
    std::cout << "KError sub_code: " << error_info.error_sub_code() << std::endl;
    std::cout << "KError sub_string: " << error_info.error_sub_string() << std::endl;

    // Error codes by themselves are not very verbose if you don't see their corresponding enum value
    // You can use google::protobuf helpers to get the string enum element for every error code and sub-code
    std::cout << "Error code string equivalent: " << Kinova::Api::ErrorCodes_Name(Kinova::Api::ErrorCodes(error_info.error_code())) << std::endl;
    std::cout << "Error sub-code string equivalent: " << Kinova::Api::SubErrorCodes_Name(Kinova::Api::SubErrorCodes(error_info.error_sub_code())) << std::endl;
}

void KortexRobot::UnsubscribeToNotifications()
{
    if(~m_bIsConnected)
    {
        return;
    }

    for (auto handle:m_NotificationHandleList)
    {
        m_pBase->Unsubscribe(handle);
    }

}


