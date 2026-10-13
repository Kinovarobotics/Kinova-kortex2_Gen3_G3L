# Kinova Robot Leader-Follower System

A C++ application that implements a leader-follower robot control system using the Kinova Kortex API. This system allows one robot to mimic the movements of another robot in real-time.

## Overview

This project enables a follower robot to replicate the movements of a leader robot. On startup, both robots move to their **Retract** position. The leader is then put in **cartesian admittance (hand guiding) mode**: the robot compensates gravity and moves its end effector following the forces you apply, so it does not drop when you let go. The follower imitates the leader's movement joint by joint, and its Robotiq 2F-85 gripper follows the leader's gripper, until you press **Ctrl+C** (or for a fixed duration, see [Build Configuration](#build-configuration)).

Two programs are built:

| Program | Leader mode | Start position |
| :--- | :--- | :--- |
| `kinova_example` | Cartesian admittance (hand guiding), gravity compensated | Retract |
| `kinova_example_xbox` | Driven by an Xbox controller connected to the leader arm (no hand guiding) | Retract |
| `kinova_example_current_mode` | Original behaviour: low-level current mode at 0 A, **no gravity compensation** (the leader drops if not held) | Home |

This leader-follower system serves as a foundation for various dual arm control applications. The core API setup and real-time position tracking can be adapted for coordinated dual arm tasks such as **teleoperation systems** where a human operator controls one robot arm while the second arm provides assistance or performs complementary tasks in hazardous environments.

## Features

- **Leader-Follower Control**: One robot acts as the leader while another follows its movements
- **Hand Guided Leader**: The leader is moved by hand in cartesian admittance mode
- **Gripper Mirroring**: The follower's gripper follows the position of the leader's gripper (`kinova_example` and `kinova_example_xbox`)
- **Real-time Position Tracking**: Continuous monitoring and replication of robot positions (~1 kHz)
- **6DoF or 7DoF arms**: Selected at run time with `--dof`
- **Retract Position Reset**: Both robots move to their Retract position at startup
- **Clean Ctrl+C exit**: The leader is taken out of admittance mode and both arms are put back in single level servoing
- **Robot constructor**: Robot class that allows initialization and tear down of robots

## Requirements

- Kinova Kortex API 2.7.0
- CMake 3.10 or higher
- C++14 compatible compiler
- Two Kinova Gen3 arms with the same number of joints (both 6DoF or both 7DoF)
- Optional: a Robotiq 2F-85 gripper on each arm, with a wrist button control mapping activated on the leader to open/close its gripper (set up in the Kortex Web App, Controllers page)
- Network connection to both robots

## Setup

1. Connect two Gen3 robots to your computer
2. Setup the IP addresses of the robots

By default, this application assumes that your robots have the following IP addresses.

    Leader: 192.168.1.10
    Follower: 192.168.2.10

The robots are on two different subnets, so your computer needs an address on each, for example `192.168.1.11/24` and `192.168.2.11/24` (both can be on the same network interface).

If you wish to use different IP addresses for your robots, you must change the IP addresses of the robot constructor in the main of leader.cpp (and leader_current_mode.cpp)

```bash
    Robot leader = Robot("your.ip.address.here","admin","admin");
    Robot follower = Robot("your.ip.address.here","admin","admin");
```
Verify that your computer connects to both robots by running ping "your.ip.address.here"

3. Download the KINOVA KORTEX™ API from Artifactory : https://artifactory.kinovaapps.com/ui/repos/tree/General/generic-local-public/kortex/API/2.7.0 (Make sure to download the file that matches your operating system, only `linux_x86-64_gcc_5.4.zip` was tested)
4. Extract the .zip content and copy the include and lib folders of the API into the kortex_api folder, so that it looks like this:

```
kortex_api/
├ include/        (client, client_stubs, common, google, messages, ...)
└ lib/release/libKortexApiCpp.a
```

If you already built the main C++ examples (`api_cpp/examples`) with Conan, the same API is in your Conan cache and can be copied from there instead:

```bash
P=~/.conan/data/kortex_api_cpp/2.7.0-r.5/kortex/stable/package/<package_id>
mkdir -p kortex_api/lib/release
cp -r $P/include kortex_api/
cp -r $P/thirdParty/include/* kortex_api/include/      # protobuf headers
cp $P/lib/libKortexApiCpp.a kortex_api/lib/release/
```

## Building

1. Clone the repository
2. Ensure the Kortex API is properly installed and paths are configured in `CMakeLists.txt`
3. Build the project:

```bash
mkdir build
cd build
cmake ..
make
```

This builds both `kinova_example` and `kinova_example_current_mode` in the `build` folder.

### Build Configuration

By default the leader-follower operation runs until you press Ctrl+C. You can instead make it stop after a specified duration in seconds:
```bash
cmake -DDURATION=30 ..
make
```
CMake remembers this value: to go back to running until Ctrl+C, rebuild with `cmake -DDURATION=0 ..`. Ctrl+C also stops a timed run early.

## Usage

1. Start the demo by running one of the following commands from the `build` folder

```bash
./kinova_example              # two Gen3 7DoF arms (default)
./kinova_example --dof 6      # two Gen3 6DoF arms
./kinova_example --help
```

`--dof` must match the number of joints of both arms. The program checks the actuator count of both robots before moving them and exits if it does not match.

2. The leader robot and the follower robot will go to their Retract position. At startup the program prints the offset between the leader and follower for each joint, which should be close to 0 deg.

3. The leader is then put in cartesian admittance mode: guide it by its end effector and the follower imitates its movement. Since the arms start from Retract, which is a folded position, some directions may feel stiff at first; pull the end effector up and out before making fine movements.

4. Open and close the leader's gripper with its wrist button mapping: the follower's gripper follows it. At startup the program prints whether grippers were found on both arms; if not, the arms are still mirrored without the grippers. Do not use the follower's wrist buttons while the program runs, the follower's gripper is driven by the program.

5. Press **Ctrl+C** to stop. The leader is taken out of admittance mode and holds its position, and both arms are put back in single level servoing. Keep a hand near the leader while it switches back.

### Running `kinova_example_xbox`

```bash
./kinova_example_xbox --dof 7
```

Identical to `kinova_example`, except that the leader is not put in admittance mode: it stays in single level servoing and is driven by an Xbox controller plugged (USB) into the leader arm, using the controller mapping active on the leader (default Xbox map or your own, see the Kortex Web App Controllers page). Open and close the leader's gripper with the controller; the follower's arm and gripper follow as in `kinova_example`. Do not plug a controller into the follower.

### Running `kinova_example_current_mode`

```bash
./kinova_example_current_mode --dof 7
```

WARNING: In this mode the leader is **not** gravity compensated. Once both robots reach their Home position, lightly hold the leader robot by placing your hand under its end effector. It will drop if not held by the user at this stage, and again when you press Ctrl+C until it switches back to position mode.

## Configuration

- **Default velocity**: 20.0 degrees per second
- **Network timeout**: 5 seconds
- **Number of joints**: `--dof 6` or `--dof 7` at run time (default: 7)
- **Operation duration**: Configurable at build time with `-DDURATION` (default: 0, runs until Ctrl+C)
- **Start position**: Set with `move_to_named_position(..., "Retract")` in `leader.cpp`; any predefined joint angle action of the robot (e.g. `"Home"`) can be used
- **Ports**: 10000 (standard), 10001 (real-time)

### Gripper mirroring

The program does not command the leader's gripper, it only reads its position (0 = open, 100 = closed) from the leader's feedback. The follower's gripper is commanded in the same low-level cyclic command as its joints, with the proportional loop of the `107-Gripper_low_level_command` example: velocity = `GRIPPER_PROPORTIONAL_GAIN` x position error (max 100%), and the gripper stops when the error is below `GRIPPER_MINIMAL_POSITION_ERROR` (1.5%). Both constants are at the top of `leader.cpp`. `kinova_example_xbox` mirrors the grippers the same way; `kinova_example_current_mode` does not.

### Joint angle wrapping

Joint positions are reported between 0 and 360 degrees, and joints such as joint 1 sit at 0 degrees in Retract and Home, where readings flip between ~0 and ~360. The initial leader-follower offset is therefore wrapped to [-180, 180) with `wrap_angle_180()`, and every follower position command is wrapped to [0, 360) with `wrap_angle_360()`. Without this, the follower's joint could be commanded outside 0-360 degrees and rotate on its own.

## File Structure

- `leader.cpp` - Main application logic: leader in cartesian admittance mode, follower in low-level position mode
- `leader_xbox.cpp` - Same as `leader.cpp`, but the leader is driven by an Xbox controller connected to it instead of hand guiding
- `leader_current_mode.cpp` - Original version: leader in low-level current mode (no gravity compensation)
- `api_setup.cpp` - Kortex API initialization and setup
- `arm_core_functions.cpp` - Core robot movement functions (named position moves, low-level setup, angle wrapping)
- `include/` - Header files for the project
- `kortex_api/` - Kinova Kortex API libraries and headers

## API Setup (`api_setup.cpp`)

The `api_setup.cpp` file handles the initialization and management of the Kinova Kortex API connection. It provides a `Robot` class that encapsulates all the necessary API components for communicating with a Kinova Gen3 robot.

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


