# Ethernet Bridge Configuration example

## Overview

This example shows you how to configure your computer, the robot and your device to route your Ethernet packets from your computer through the robot and the Interconnect module to your device, connected to the Ethernet Expansion IO of the Interconnect Module.

## Configuration steps

### 1 - Configuring your device

The example was developed using a Raspberry Pi connected by Ethernet to the Interconnect's Ethernet Expansion IO.

The configuration steps for the Raspberry Pi are : 

1. Configure a static IP address in the 10.20.0.0/24 subnetwork on the interface connected to the Interconnect module : 

    ```sudo ifconfig your_interface your_chosen_address netmask 255.255.255.0```

    For example, when using address 10.20.0.50 and interface eth0 : 

    ```sudo ifconfig eth0 10.20.0.50 netmask 255.255.255.0```

2. Configure the default gateway for the interface :

    ```sudo route add default gw 10.20.0.1 your_interface```

    For example, when using interface eth0 : 

    ```sudo route add default gw 10.20.0.1 eth0```

3. Unplug and replug the link to restart it.

> Note : Don't use address 10.20.0.100 because it is the Vision module's address!

### 2 - Configuring the arm

The [C++ code](./01-ethernet_bridge_configuration.cpp) configures and enables the arm's Ethernet link. You can change the ```speed``` and ```duplex``` options to match your required configuration. 

You can run the code with this command on Linux (from the build folder): 
```./01-ethernet_bridge_configuration```

You can run the code with this command on Windows (from the build folder): 
```01-ethernet_bridge_configuration.exe```

### 3 - Configuring your computer

- On Linux, you can run the [bash script](./configure_route_to_device.bash) to create the route to your device. This way, your computer will know that when it needs to send a packet to your device, it must route through the arm's base. The script also pings the device to show the route is working. 

    Usage guide : ```sudo ./configure_route_to_device.bash ARM_IP_ADDRESS INTERFACE DEVICE_ADDRESS```
    - ARM_IP_ADDRESS is the arm's IP address
    - INTERFACE is the host interface name connected to the arm
    - DEVICE_ADDRESS is the address of the device connected to the Interconnect module

    Example  : ```sudo ./configure_route_to_device.bash 192.168.1.10 eth0 10.20.0.50```


- On Windows, you can run the [batch file](./configure_route_to_device.bat) to create the route to your device. This way, your computer will know that when it needs to send a packet to your device, it must route through the arm's base. The script also pings the device to show the route is working.

    Usage guide : ```.\configure_route_to_device.bat ARM_IP_ADDRESS DEVICE_ADDRESS```
    - ARM_IP_ADDRESS is the arm's IP address
    - DEVICE_ADDRESS is the address of the device connected to the Interconnect module

    Example  : .\configure_route_to_device.bat 192.168.1.10 10.20.0.50

    > Note: You will need to run this command from an Admin Command Prompt or an Admin Powershell!
