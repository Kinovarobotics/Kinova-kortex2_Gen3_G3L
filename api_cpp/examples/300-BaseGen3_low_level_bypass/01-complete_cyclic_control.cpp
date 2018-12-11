/*
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2018 Kinova inc. All rights reserved.
*
* This software may be modified and distributed under the
* terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <SessionManager.h>
#include <BaseClientRpc.h>

#include <ActuatorConfigClientRpc.h>
#include <ActuatorCyclicClientRpc.h>

#include <RouterClient.h>
#include <TransportClientUdp.h>

#if defined(_MSC_VER)
#include <windows.h> // Include so we can actually use WinAPI functions.
#define DWORD_XFORMAT PRIX64
#elif defined(__MINGW32__)
#include <windows.h> // Include so we can actually use WinAPI functions.
#include <unistd.h>
#define DWORD_XFORMAT "X"
#else
#include <unistd.h>
#endif

namespace k_api = Kinova::Api;

#define PORT 10000
#define LOOP_FRQ_US 1000

#define MAX_CONSECUTIVE_FEEDBACK_LOST  12
#define MAX_DELAYED_FEEDBACK_US         (LOOP_FRQ_US * 1.5)


/////////////////////////////////////////////////////////////////////////
// Struct
/////////////////////////////////////////////////////////////////////////
#if defined(__MINGW32__) || defined(_MSC_VER)
bool selectThreadPriority(std::thread::native_handle_type thread_handle);
bool selectPriorityAndAffinity(bool isFallBackHighPriorityAllowed);
#endif


struct ActuatorParameters
{
    std::string ip;
    int direction;
    float velocity;
    float positionDelta;
};


struct BenchmarkData
{
    uint32_t cmdId;
    int64_t timeStampCmdTheo;
    
    float   cmdPosition;
    float   feedbackPosition;
    
    int64_t cmdTimeStamp;
    int64_t sentTimeStamp;
    int64_t feedbackTimeStamp;
    
    int64_t lateCmdDelay;
    int64_t sendingDelay;
    int64_t feedbackDelay;
};


struct ArmBaseApi
{
    std::string m_ipAddress;
    
    k_api::TransportClientUdp* m_pTransport;
    k_api::RouterClient* m_pRouterClient;
    k_api::Base::BaseClient* m_pBase;
    k_api::SessionManager* m_pSessionMng;
    
    uint32_t m_nbrRobotJoints;
    
    ArmBaseApi(const std::string& ipAddress)
    {
        m_ipAddress = ipAddress;
        m_pTransport = new k_api::TransportClientUdp();
        m_pTransport->connect(m_ipAddress, PORT);
        m_pRouterClient = new k_api::RouterClient(m_pTransport, [](k_api::KError err) { std::cout << "_________ callback error _________" << err.toString(); });
        m_pBase = new k_api::Base::BaseClient(m_pRouterClient);
        m_pSessionMng = new k_api::SessionManager(m_pRouterClient);
    
        auto createSessionInfo = k_api::Session::CreateSessionInfo();
        createSessionInfo.set_username("admin");
        createSessionInfo.set_password("admin");
        createSessionInfo.set_session_inactivity_timeout(60000);
        createSessionInfo.set_connection_inactivity_timeout(2000);
    
        std::cout << "Creating Session for communication" << std::endl;
        m_pSessionMng->CreateSession(createSessionInfo);
        std::cout << "Session Created" << std::endl;
    
        auto actuatorInfo = m_pBase->GetActuatorCount();
        m_nbrRobotJoints = actuatorInfo.count();
    }
    
    ~ArmBaseApi()
    {
        SetServoingMode( k_api::Base::ServoingMode::SINGLE_LEVEL_SERVOING );

        m_pTransport->disconnect();
        delete m_pBase;
        delete m_pSessionMng;
        delete m_pRouterClient;
        delete m_pTransport;
    }

	bool ValidateServoingMode(k_api::Base::ServoingMode mode)
	{
		bool isOk;

		try
		{
			std::cout << "validate that servoing mode is " << mode << std::endl;
			auto getMode = m_pBase->GetServoingMode();
			isOk = (getMode.servoing_mode() == mode);
		}
		catch (...) 
		{
			isOk = false;
		}

		return isOk;
	}

	bool SetServoingMode(k_api::Base::ServoingMode mode)
	{
		std::cout << "try to set servoing mode: " << mode << std::endl;

		auto servoingMode = k_api::Base::ServoingModeInformation();
		servoingMode.set_servoing_mode(mode);
		m_pBase->SetServoingMode(servoingMode);

		return ValidateServoingMode(mode);
	}

    bool ValidateAngularPositionsProximity( std::map<uint32_t, float> actuatorPositions, float tolerance )
    {
        auto redActuatorPositions = m_pBase->GetMeasuredJointAngles();

        for (auto actuatorPos : actuatorPositions)
        {
            if ( actuatorPos.first >= redActuatorPositions.joint_angles_size() )
                return false;

            auto redAngle = redActuatorPositions.joint_angles(actuatorPos.first).value();
            float deltaPos = fabs (redAngle - actuatorPos.second);
            
            if (deltaPos > 180)
                deltaPos = fabs(deltaPos - 360);
                    
            if (deltaPos > tolerance)
                return false;
        }

        return true;
    }
    
    bool ReachActuatorPositions( std::map<uint32_t, float> actuatorPositions )
    {
        bool isOk = false;
        
        try
        {
            k_api::Base::ConstrainedJointAngles constrainedJointAngles;
            k_api::Base::JointAngles* pJointAngles = constrainedJointAngles.mutable_joint_angles();
            for (auto actuatorPos : actuatorPositions)
            {
                if ( actuatorPos.first >= m_nbrRobotJoints )
                    return false;
    
                k_api::Base::JointAngle* pJointsAngle = pJointAngles->add_joint_angles();
                pJointsAngle->set_joint_identifier(actuatorPos.first);
                pJointsAngle->set_value(actuatorPos.second);
            }
            
            m_pBase->PlayJointTrajectory(constrainedJointAngles);
    
            std::this_thread::sleep_for(std::chrono::milliseconds(8000));
    
            isOk = true;
        }
        catch(k_api::KDetailedException ex)
        {
            printf("unable to reach the initial position\n");
            printf("%s\n", ex.what());
        }
        return isOk;
    }
};


struct ActuatorApi
{
    std::string m_ipAddress;
    
    k_api::TransportClientUdp* m_pTransport;
    k_api::RouterClient* m_pRouterClient;
    k_api::ActuatorConfig::ActuatorConfigClient* m_pActuatorConfig;
    k_api::ActuatorCyclic::ActuatorCyclicClient* m_pActuatorCyclic;
    
    ActuatorApi(const std::string& actuatorAddress)
    {
        m_ipAddress = actuatorAddress;
        m_pTransport = new k_api::TransportClientUdp();
        m_pTransport->connect(actuatorAddress, PORT);
        m_pRouterClient = new k_api::RouterClient(m_pTransport, [](k_api::KError err) { std::cout << "_________ callback error _________" << err.toString(); });
        m_pActuatorConfig = new k_api::ActuatorConfig::ActuatorConfigClient(m_pRouterClient);
        m_pActuatorCyclic = new k_api::ActuatorCyclic::ActuatorCyclicClient(m_pRouterClient);
        
        #if defined(_MSC_VER)
        if(!selectThreadPriority(m_pTransport->m_receiveThread.native_handle()))
            throw (new std::runtime_error("Setting thread priority failed."));
        #endif
    }
    
    ~ActuatorApi()
    {
		m_pTransport->disconnect();
		delete m_pActuatorConfig;
		delete m_pActuatorCyclic;
		delete m_pRouterClient;
		delete m_pTransport;
    }
};


struct ActuatorControl
{
    ActuatorApi m_api;
    std::vector<BenchmarkData> m_datas;
    
    k_api::ActuatorCyclic::Command m_command;
    k_api::ActuatorCyclic::Feedback m_feedback;
    
    std::function< void (const k_api::Error &, const k_api::ActuatorCyclic::Feedback&) > m_feedbackCall;

    int   m_direction;
    float m_velocity;
    float m_positionDelta;

    float m_currentPosition;
    float m_targetPosition;
    
    bool  m_isPositionReached;
    bool  m_faultDetected;

    ActuatorControl(ActuatorParameters& parameters) : m_api(parameters.ip)
    {
        assert(parameters.direction == 1 || parameters.direction == -1);
        assert(parameters.velocity <= 20.0);
        assert(parameters.positionDelta >= 0);

        m_direction = parameters.direction;
        m_velocity = parameters.velocity;
        m_positionDelta = parameters.positionDelta;
        m_isPositionReached = (m_positionDelta == 0.0f);
        m_faultDetected = false;
        
        assert(m_direction == parameters.direction);
        assert(m_velocity == parameters.velocity);
        assert(m_positionDelta == parameters.positionDelta);

        m_datas.resize(65000);
    }
    ~ActuatorControl() = default;

    void initializeCyclic()
    {
		// std::cout << "Get Actual Feedback " << std::endl;
        k_api::ActuatorCyclic::MessageId messageId;
        messageId.set_identifier(0);
        m_feedback = m_api.m_pActuatorCyclic->RefreshFeedback(messageId);
    
        // auto lastFeedbackCmdId = m_feedback.feedback_id().identifier();
        auto bankA = m_feedback.fault_bank_a();
        auto bankB = m_feedback.fault_bank_b();
        if(bankA != 0 || bankB !=0)
        {
            std::cout << "Actuator " << m_api.m_ipAddress << " in fault before launching test." << "\n"
                 << "Fault bank A: " << bankA << "\n"
                 << "Fault bank B: " << bankB << std::endl;
        }
    
        m_api.m_pActuatorConfig->ClearFaults();
    
        std::cout << "Switch in cyclic mode " << std::endl;
        auto modeInfo = k_api::ActuatorConfig::CommandModeInformation();
        modeInfo.set_command_mode(k_api::ActuatorConfig::CYCLIC);
        m_api.m_pActuatorConfig->SetCommandMode(modeInfo);
    
        std::cout << "Enable actuators servoing" << std::endl;
        m_command.set_flags(1);
        auto servoing = k_api::ActuatorConfig::Servoing();
        servoing.set_enabled(true);
        m_api.m_pActuatorConfig->SetServoing(servoing);
    
        std::cout << "Compute trajectory " << std::endl;
        calculateTargetPosition(m_feedback.position());
    }

    void calculateTargetPosition(float currentPosition)
    {
        m_currentPosition = currentPosition;
        m_targetPosition = m_currentPosition + m_direction * m_positionDelta;
        m_isPositionReached = (m_positionDelta == 0.0f);
    }
    
    void printInfo()
    {
        std::cout << "Settings for actuator of ip:" << m_api.m_ipAddress << std::endl;
        std::cout << "direction: " << (((m_direction > 0) ? ("clockwise"): ("counter-clockwise")))
             << ", velocity: " << m_velocity << ", positionDelta: " << m_positionDelta << std::endl;
        std::cout << "currentPosition: " << m_currentPosition << ", targetPosition: " << m_targetPosition << std::endl;
    }
};

/////////////////////////////////////////////////////////////////////////
//  Utilities
/////////////////////////////////////////////////////////////////////////
std::mutex mutexTimer;
int64_t GetTickUs()
{
    mutexTimer.lock();
    
    int64_t ret;
#if defined(_MSC_VER)
    LARGE_INTEGER start, frequency;
    
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    
    ret = (start.QuadPart * 1000000)/frequency.QuadPart;
#else
    struct timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    ret = (start.tv_sec * 1000000LLU) + (start.tv_nsec / 1000);
#endif
    
    mutexTimer.unlock();
    
    return ret;
    
}


#if defined(_MSC_VER)
bool selectThreadPriority(std::thread::native_handle_type thread_handle)
{
    int res;
    DWORD priority = GetThreadPriority(thread_handle);
    printf("Current thread priority: red priority 0x%lX\n", priority);

    auto newThreadPriority = THREAD_PRIORITY_ABOVE_NORMAL;
    printf("modify priority: (0x%lX)\n", newThreadPriority);
    res = SetThreadPriority(thread_handle, newThreadPriority);
    if (res == 0)
    {
        printf("Error: unable to change priority\n");
        return false;
    }

    priority = GetThreadPriority(thread_handle);
    if (priority != newThreadPriority)
    {
        printf("Error to modify priority: red priority 0x%lX\n", priority);
        return false;
    }

    printf("\n");
    return true;
}
#endif

#if defined(__MINGW32__) || defined(_MSC_VER)
bool selectPriorityAndAffinity(bool isFallBackHighPriorityAllowed)
{
    HANDLE hProcess = GetCurrentProcess();
    int res;
    
    auto priority2 = GetPriorityClass(GetCurrentProcess());
    
    printf("Initial priority: red priority 0x%lX\n", priority2);
    
    DWORD priority = REALTIME_PRIORITY_CLASS; // NORMAL_PRIORITY_CLASS, ABOVE_NORMAL_PRIORITY_CLASS, HIGH_PRIORITY_CLASS, REALTIME_PRIORITY_CLASS
    printf("modify priority: REALTIME_PRIORITY_CLASS (0x%lX)\n", priority);
    res = SetPriorityClass(hProcess, priority);
    if (res == 0)
    {
        printf("Error: unable to change priority\n");
        return false;
    }
    
    priority = GetPriorityClass(GetCurrentProcess());
    if (priority != REALTIME_PRIORITY_CLASS)
    {
        if (isFallBackHighPriorityAllowed)
        {
            printf("Warning fallback to high priority needed\n");
            if (priority != HIGH_PRIORITY_CLASS)
            {
                printf("Error to modify priority: red priority 0x%lX\n", priority);
                return false;
            }
        }
        else
        {
            printf("Error to modify priority: red priority 0x%lX\n", priority);
            return false;
        }
    }
    
    printf("\n");
    
    SYSTEM_INFO SystemInfo;
    GetSystemInfo(&SystemInfo);
    printf("get system info: dwNumberOfProcessors = %lu\n", SystemInfo.dwNumberOfProcessors);
    
    DWORD_PTR processAffinityMask;
    DWORD_PTR systemAffinityMask;
    res = GetProcessAffinityMask(hProcess, &processAffinityMask, &systemAffinityMask);
    printf("get actual affinity: (res %d) - process 0x%" DWORD_XFORMAT "; system 0x%" DWORD_XFORMAT "\n", res, processAffinityMask, systemAffinityMask);
    if (res == 0)
    {
        printf("Error: unable to read affinity\n");
        return false;
    }
    
    if (SystemInfo.dwNumberOfProcessors >= 2)
    {
        auto cnt = 0;
        DWORD_PTR affinityMask = 0;
        for (int bit = sizeof(DWORD_PTR) * 8 - 1; bit >= 0; bit--)
        {
            DWORD_PTR mask = ((DWORD_PTR)0x01 << bit);
            if (mask & processAffinityMask)
            {
                affinityMask = (affinityMask | mask);
                if (++cnt == 2)
                    break;
            }
        }
        processAffinityMask = affinityMask;
    
        res = SetProcessAffinityMask(hProcess, processAffinityMask);
        printf("set affinity: (res %d) - 0x%" DWORD_XFORMAT "\n", res, processAffinityMask);

        if (res == 0)
        {
            printf("Error: unable to change affinity\n");
            return false;
        }
        
        res = GetProcessAffinityMask(hProcess, &processAffinityMask, &systemAffinityMask);
        printf("get new affinity: (res %d) - process 0x%" DWORD_XFORMAT "; system 0x%" DWORD_XFORMAT "\n", res, processAffinityMask, systemAffinityMask);
        if (res == 0)
        {
            printf("Error: unable to read new affinity\n");
            return false;
        }
    }
    
    return true;
}
#endif

std::vector<std::string> tokenizeLine(std::string rawLine)
{
    std::vector<std::string> tokens;
    
    auto tokenStart = rawLine.find_first_not_of(' ');
    auto tokenEnd = rawLine.find_first_of(' ', tokenStart);
    
    while (tokenStart != tokenEnd)
    {
        std::string token = rawLine.substr(tokenStart, tokenEnd);
        tokens.push_back(token);
        
        rawLine.erase(tokenStart, rawLine.find_first_not_of(' ', tokenEnd));
        tokenStart = rawLine.find_first_not_of(' ');
        tokenEnd = rawLine.find_first_of(' ', tokenStart);
    }
    
    return tokens;
}

bool readParametersFromFile(std::string& fileName, std::vector<ActuatorParameters>& allTokens)
{
    bool ret =  true;
    std::string line;
    ifstream paramsFile(fileName);
    
    if(paramsFile.is_open())
    {
        while (std::getline(paramsFile, line))
        {
            ActuatorParameters parameters;
            if (line.find_first_of('#') == 0)
            {
                continue;
            }
            else
            {
                auto tokens = tokenizeLine(line);
                parameters.ip = tokens.at(0);
                parameters.direction = std::stoi(tokens.at(1));
                parameters.positionDelta = std::stof(tokens.at(2));
                parameters.velocity = std::stof(tokens.at(3));
                allTokens.push_back(parameters);
            }
        }
        
        paramsFile.close();
    }
    else
    {
        ret = false;
        std::cout << "Unable to open file. Make sure it is in the same directory as the executable." << "\n";
    }
    
    return ret;
    
}

bool writeToFile(const std::string& fileName, const std::string& separator, const std::vector<BenchmarkData>& data)
{
    bool ret = true;
    std::ofstream file(fileName);

    if(file.is_open())
    {
        file << "cmdId" << separator << "timeStampCmdTheo" << separator << "cmdPosition" << separator << "feedbackPosition" << separator <<
             "cmdTimeStamp" << separator << "sentTimeStamp" << separator << "feedbackTimeStamp" << separator <<
             "lateCmdDelay" << separator << "sendingDelay" << separator << "feedbackDelay" << "\n";

        for(auto it = data.begin(); it != data.end(); it++)
        {
            file << it->cmdId << separator << it->timeStampCmdTheo << separator  << it->cmdPosition << separator << it->feedbackPosition << separator <<
                 it->cmdTimeStamp << separator << it->sentTimeStamp << separator << it->feedbackTimeStamp << separator <<
                 it->lateCmdDelay << separator << it->sendingDelay << separator << it->feedbackDelay << "\n";
        }

        file.close();
    }
    else
    {
        ret = false;
        std::cout << "Unable to open file" << "\n";
    }
    
    return ret;
}


/////////////////////////////////////////////////////////////////////////
// Example
/////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    #if defined(__MINGW32__) || defined(_MSC_VER)
    if (!selectPriorityAndAffinity(true))
        return 1;

    // cin.get();
    // return 1;
    #endif
    
    std::string ipArmBase = "192.168.1.10";
    std::string filePathAndName = "./demo.txt";
    
    ArmBaseApi* pArmApi = nullptr;
    try
    {
        if (ipArmBase.empty())
            throw std::runtime_error("error armbase ip address not specified !!");
        
        pArmApi = new ArmBaseApi(ipArmBase);
    
        std::map<uint32_t, float> actuatorPositions;
        for (uint32_t index = 0u; index < pArmApi->m_nbrRobotJoints; ++index)
        {
            actuatorPositions.insert({ index, 0.0f });
        }
    
        pArmApi->ReachActuatorPositions(actuatorPositions);
    }
    catch (...)
    {
        std::cout << "Error detected while initializing armbase" << "\n";
        return 1;
    }

    std::vector<ActuatorParameters> allParameters;
    if(!readParametersFromFile(filePathAndName, allParameters))
    {
        std::cout << "Error reading from file, cannot continue run." << "\n";
        delete pArmApi;
        return 1;
    }

    auto actuatorCountFromParams = allParameters.size();
    std::vector<std::thread> threads;
    std::vector<ActuatorControl*> actuators;
    
    try
    {
        std::cout << "Switching in ByPass mode  " << std::endl;
        if ( !pArmApi->SetServoingMode( k_api::Base::ServoingMode::BYPASS_SERVOING ) )
        {
            std::cout << "error : pArmApi->SetServoingMode( Base::ServoingMode::BYPASS_SERVOING )" << std::endl;
            throw std::runtime_error("pArmApi->SetServoingMode( Base::ServoingMode::BYPASS_SERVOING )");
        }
    
        std::cout << "Create Actuator apis" << std::endl;
        for (size_t index = 0; index < actuatorCountFromParams; ++index)
        {
            auto curAct = new ActuatorControl(allParameters[index]);
            actuators.push_back(curAct);
        }
    
        std::cout << "Init actuators " << std::endl;
        for (auto&& curAct : actuators)
        {
            curAct->initializeCyclic();
        }
    }
    catch (...)
    {
        std::cout << "Error detected while initializing test settings in actuators !!!" << std::endl;
        delete pArmApi;
        for (auto&& act : actuators) delete act;
        return 1;
    }

    for (auto&& curAct : actuators)
    {
        curAct->printInfo();
    }
    
    try
    {
        auto cyclicCallback = [&] (const k_api::Error &error, k_api::ActuatorCyclic::Feedback feedbackRcv, ActuatorControl* pCurAct) mutable
        {
            if (error.error_code() == k_api::SUCCESS)
            {
                pCurAct->m_feedback = feedbackRcv;
    
                uint32_t cmdId = pCurAct->m_feedback.feedback_id().identifier();
                auto &data = pCurAct->m_datas.at(cmdId);
                data.feedbackTimeStamp = GetTickUs();
                data.feedbackDelay = data.feedbackTimeStamp - data.timeStampCmdTheo;
                data.feedbackPosition = pCurAct->m_feedback.position();
    
                // if (data.feedbackDelay > MAX_DELAYED_FEEDBACK_US)
                //     std::cout << "Feedback Actuator " << pCurAct->m_api.m_ipAddress << " received after " << feedbackTimeStamp - sentTimeStamp << "\n";
    
                auto bankA = feedbackRcv.fault_bank_a();
                auto bankB = feedbackRcv.fault_bank_b();
                if (bankA != 0 || bankB != 0)
                {
                    std::cout << "Actuator " << pCurAct->m_api.m_ipAddress << " in fault at position " << pCurAct->m_feedback.position() << "\n"
                         << "Fault bank A: " << bankA << "\n"
                         << "Fault bank B: " << bankB << std::endl;
        
                    pCurAct->m_faultDetected = true;
                }
            }
        };

        using namespace std::placeholders;
        for (auto&& curAct : actuators)
        {
            curAct->m_feedbackCall = std::bind(cyclicCallback, _1, _2, curAct);
        }
        
        int64_t loopTimeRef = 0;
        int64_t lastSendRef = GetTickUs();

        uint32_t cmdId = 0;
    
        // tmp : to reset the actual msg_id cmpt
        for (auto&& curAct : actuators)
        {
            float pos = static_cast<float>(fmod(curAct->m_currentPosition + 360.0 * 5, 360.0));
    
            k_api::ActuatorCyclic::MessageId *msgId = curAct->m_command.mutable_command_id();
            msgId->set_identifier(0);
            curAct->m_command.set_flags(1);
            curAct->m_command.set_position(pos);
            curAct->m_command.set_velocity(0);

            curAct->m_api.m_pActuatorCyclic->Refresh(curAct->m_command);
        }
        
        bool areActuatorsStillRunning = false;
        while (!areActuatorsStillRunning)
        {
            loopTimeRef = GetTickUs();
    
            if (loopTimeRef - lastSendRef > LOOP_FRQ_US)
            {
                lastSendRef += LOOP_FRQ_US;
                int64_t lateCmdDelay = loopTimeRef -  lastSendRef;
    
                areActuatorsStillRunning = true;
                for (auto&& curAct : actuators)
                {
                    if (curAct->m_faultDetected || curAct->m_isPositionReached)
                        continue;
                    
                    curAct->m_currentPosition += curAct->m_direction * (LOOP_FRQ_US / 1000000.0f * curAct->m_velocity);
    
                    auto& data = curAct->m_datas.at(cmdId);
                    data.cmdId = cmdId;
                    data.timeStampCmdTheo   = lastSendRef;
                    data.cmdTimeStamp       = loopTimeRef;
                    data.lateCmdDelay       = lateCmdDelay;
                    data.cmdPosition        = curAct->m_currentPosition;

                    float pos = static_cast<float>(fmod(curAct->m_currentPosition + 360.0 * 5, 360.0));

                    k_api::ActuatorCyclic::MessageId *msgId = curAct->m_command.mutable_command_id();

                    msgId->set_identifier(cmdId);
                    curAct->m_command.set_flags(1);
                    curAct->m_command.set_position(pos);
                    curAct->m_command.set_velocity(curAct->m_velocity);
    
                    curAct->m_api.m_pActuatorCyclic->Refresh_callback(curAct->m_command, curAct->m_feedbackCall);
    
                    curAct->m_isPositionReached = (curAct->m_direction > 0) ? (curAct->m_currentPosition >= curAct->m_targetPosition) : (curAct->m_currentPosition <= curAct->m_targetPosition);
                    areActuatorsStillRunning = areActuatorsStillRunning && curAct->m_isPositionReached;
                }
    
                int64_t sentTimeStamp = GetTickUs();
                int64_t sendingDelay = sentTimeStamp - lastSendRef;
                for (auto&& curAct : actuators)
                {
                    auto &data = curAct->m_datas.at(cmdId);
                    data.sentTimeStamp = sentTimeStamp;
                    data.sendingDelay = sendingDelay;
                }
                
                ++cmdId;
            }
        }
    }
    catch (...)
    {
        std::cout << "Error during movement step " << "\n";
        delete pArmApi;
        for (auto&& act : actuators) delete act;
        return 1;
    }
    
    for (auto&& curAct : actuators)
    {
        std::ostringstream stream;
        stream << "actuator_" << curAct->m_api.m_ipAddress << ".csv";
        writeToFile(stream.str(), ",", curAct->m_datas);
        
        std::cout << "Actuator " << curAct->m_api.m_ipAddress << " done " << ((curAct->m_faultDetected) ? ("with"): ("without")) << " fault." << "\n"
                << "actual position: " << curAct->m_api.m_pActuatorCyclic->RefreshFeedback(k_api::ActuatorCyclic::MessageId()).position() << "\n"
                << "Final cmd position: " << curAct->m_currentPosition << "\n"
                << "Target position: " << curAct->m_targetPosition << "\n";
    }
    
    std::cout << "Test Terminated ..." << std::endl;
    delete pArmApi;
    for (auto &&act : actuators) delete act;
    return 0;
}
