# Kinova Robot Leader-Follower System

A C++ application that implements a leader-follower robot control system using the Kinova Kortex API. This system allows one robot to mimic the movements of another robot in real-time.

## Overview

This project enables a follower robot to replicate the movements of a leader robot. Both robots start at their home position, and when the user presses the wrist buttons on the leader robot, they can freely move it for a specified duration while the follower robot mirrors these movements.

This leader-follower system serves as a foundation for various dual arm control applications. The core API setup and real-time position tracking can be adapted for coordinated dual arm tasks such as **teleoperation systems** where a human operator controls one robot arm while the second arm provides assistance or performs complementary tasks in hazardous environments.


## Features

- **Leader-Follower Control**: One robot acts as the leader while another follows its movements
- **Button-Activated Movement**: Uses wrist button presses to enable movement
- **Real-time Position Tracking**: Continuous monitoring and replication of robot positions
- **Home Position Reset**: Both robots return to their home position at startup
- **Robot constructor**: Robot class that allows initialization and tear down of robots

## Requirements

- Kinova Kortex API
- CMake 3.10 or higher
- C++14 compatible compiler
- Two Kinova Gen3Lite arms
- Network connection to both robots

## Setup

1. Connect two Gen3Lite robots to your computer
2. Setup the IP addresses of the robots

By default, this application assumes that your robots have the following IP addresses.

    Leader: 192.168.1.10
    Follower: 192.168.2.10

If you wish to use different IP addresses for your robots, you must change the IP addresses of the robot constructor in the main of leader.cpp

```bash
    Robot leader = Robot("your.ip.address.here","admin","admin");
    Robot follower = Robot("your.ip.address.here","admin","admin");
```
Verify that your computer connects to both robots by running ping "your.ip.address.here"

3. Download the API Kortex from Artifactory : https://artifactory.kinovaapps.com/artifactory/generic-local-public/kortex/API/2.7.0/ (Make sure to download the file that matches your operating system, only `linux_x86-64_gcc_5.4.zip` was tested)
4. Extract the .zip content and copy the include and lib folders of the API into the kortex_api folder

## Building

Build the project:

Open a terminal window in the path containing this README file and run the following:
```bash
mkdir build
cd build
cmake ..
make
```


### Build Configuration

You can configure the leader-follower operation to run for a specified duration. Default is 20 seconds.
```bash
cmake -DDURATION=30 ..
make
```

## Usage

Run the executable:

```bash
./kinova_example
```

The system will:
1. Initialize both robots and move them to home position
2. Wait for button presses on the leader robot's wrist
3. When buttons are pressed, allow free movement of the leader robot for a specified duration. WARNING: It is very important to hold the robot when pressing the buttons. It will drop if not held by the user at this stage.
4. Mirror the leader's movements on the follower robot in real-time

## Configuration

- **Default velocity**: 20.0 degrees per second
- **Network timeout**: 5 seconds
 **Operation duration**: Configurable at build time (default: 20 seconds)
- **Ports**: 10000 (standard), 10001 (real-time)



## File Structure

- `leader.cpp` - Main application logic and robot control
- `api_setup.cpp` - Kortex API initialization and setup
- `arm_core_functions.cpp` - Core robot movement functions
- `include/` - Header files for the project
- `kortex_api/` - Kinova Kortex API libraries and headers

## API Setup (`api_setup.cpp`)

The `api_setup.cpp` file handles the initialization and management of the Kinova Kortex API connection. It provides a `Robot` class that encapsulates all the necessary API components for communicating with a Kinova Gen3Lite robot.

### Robot Class Constructor

The `Robot` constructor establishes a connection to a Kinova robot:

```cpp
Robot(std::string ip_address, std::string username, std::string password)
```

**Parameters:**
- `ip_address`: The IP address of the robot (e.g., "192.168.2.10")
- `username`: Authentication username (typically "admin")
- `password`: Authentication password (typically "admin" )

**Example Usage:**
```cpp
// Create connection to leader robot
Robot leader_robot("192.168.1.10", "admin", "admin");

// Create connection to follower robot  
Robot follower_robot("192.168.2.10", "admin", "admin");
```

### What the API Setup Does

The `api_setup.cpp` file:

1. **Establishes Dual Communication Channels:**
   - TCP connection for standard robot control commands
   - UDP connection for real-time data exchange (lower latency)

2. **Manages Authentication:**
   - Creates secure sessions with configurable timeouts
   - Handles session management for both communication channels

3. **Initializes API Clients:**
   - `BaseClient`: Core robot control operations
   - `BaseCyclicClient`: Real-time position and sensor data
   - `DeviceConfigClient`: Device configuration management
   - `ActuatorConfigClient`: Individual actuator settings

4. **Provides Access Methods:**
   - `getBaseClient()`: Returns pointer to base control client
   - `getBaseCyclicClient()`: Returns pointer to real-time data client
   - `getActuatorConfig()`: Returns pointer to actuator configuration client

5. **Handles Cleanup:**
   - Automatically closes sessions and frees resources when the Robot object is destroyed
   - Ensures proper disconnection from the robot

### Network Configuration

The API uses two network ports:
- **Port 10000**: Standard TCP communication for control commands
- **Port 10001**: UDP communication for real-time data streaming

Both robots should be accessible on your network with the IP addresses configured in the main application.

## License

This project uses the Kinova Kortex API. Please refer to Kinova's licensing terms for usage restrictions.
