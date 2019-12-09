#! /bin/bash

# Usage
if [ "$1" == "-h" ] || [ "$1" == "--help" ]; then
    echo "Usage guide : ./configure_route_to_device.bash ARM_IP_ADDRESS INTERFACE DEVICE_ADDRESS"
    echo "ARM_IP_ADDRESS is the arm's IP address"
    echo "INTERFACE is the host interface name connected to the arm"
    echo "DEVICE_ADDRESS is the address of the device connected to the Interconnect module"
    echo "Example  : ./configure_route_to_device.bash 192.168.1.10 eth0 10.20.0.50"
    exit 0
fi

# Parameters
ARM_IP_ADDRESS=$1
INTERFACE=$2
DEVICE_ADDRESS=$3

# Configure the route
echo "Setting the route of the device's subnetwork through the base IP address..."
sudo ip route add 10.20.0.0/24 via $ARM_IP_ADDRESS dev $INTERFACE

# Ping the device
echo "Pinging the device..."
ping -c 4 $DEVICE_ADDRESS
