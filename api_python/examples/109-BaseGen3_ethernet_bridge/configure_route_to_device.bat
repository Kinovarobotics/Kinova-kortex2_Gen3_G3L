ECHO OFF

:: Usage
IF "%1%" == "-h" (
    GOTO usage
) 
IF "%1%" == "--help" (
    GOTO usage
)

:: Parameters
SET ARM_IP_ADDRESS=%1
SET DEVICE_ADDRESS=%2

:: Configure the route
ECHO Setting the route of the device's subnetwork through the base IP address...
route ADD 10.20.0.0 MASK 255.255.255.0 %ARM_IP_ADDRESS%

:: Ping the device
ECHO Pinging the device...
ping -n 4 %DEVICE_ADDRESS%

EXIT 0

:usage 
echo Usage guide : .\configure_route_to_device.bat ARM_IP_ADDRESS INTERFACE DEVICE_ADDRESS
echo ARM_IP_ADDRESS is the arm's IP address
echo DEVICE_ADDRESS is the address of the device connected to the Interconnect module
echo Example  : .\configure_route_to_device.bat 192.168.1.10 eth0 10.20.0.50
EXIT 0