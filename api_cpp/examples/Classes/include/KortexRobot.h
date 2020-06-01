//
// Created by mleroux on 2020-05-04.
//

#ifndef KORTEXAPICPPEXAMPLES_KORTEXROBOT_H
#define KORTEXAPICPPEXAMPLES_KORTEXROBOT_H

#include <SessionManager.h>
#include <DeviceConfigClientRpc.h>
#include <BaseClientRpc.h>

#include <RouterClient.h>
#include <TransportClientTcp.h>
#include <vector>

class KortexRobot
{
public:
    KortexRobot(const std::string& IP);
    ~KortexRobot();

    bool Init();
    void SubscribeToNotifications();
    void UnsubscribeToNotifications();

protected:
    void OnError(Kinova::Api::KDetailedException& ex);
    void OnActionNotificationCallback(Kinova::Api::Base::ActionNotification& notif);

protected:
    std::string m_sIP;
    bool m_bIsConnected;
    std::vector<Kinova::Api::Common::NotificationHandle> m_NotificationHandleList;

    Kinova::Api::TransportClientTcp* m_pTcpClient;
    Kinova::Api::RouterClient* m_pRouterClient;
    Kinova::Api::SessionManager* m_pSessionManager;
    Kinova::Api::DeviceConfig::DeviceConfigClient* m_pDeviceConfigClient;
    Kinova::Api::Base::BaseClient* m_pBase;

};


#endif //KORTEXAPICPPEXAMPLES_KORTEXROBOT_H
