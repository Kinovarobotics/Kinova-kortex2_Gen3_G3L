#include "KortexRobot.h"

int main(int argc, char **argv)
{
    KortexRobot robot = KortexRobot("192.168.1.10");

    bool connected = robot.Init();

    if(connected)
    {
        std::cout<< "Connection successful" << std::endl;

        robot.SubscribeToNotifications();
        //Do Stuff
        robot.UnsubscribeToNotifications();
    }
    std::cout << "End of example" << std::endl;

}

