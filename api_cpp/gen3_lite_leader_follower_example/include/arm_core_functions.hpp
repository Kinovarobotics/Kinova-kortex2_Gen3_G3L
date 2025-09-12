#ifndef ARM_CORE_FUNCTIONS_H 
#define ARM_CORE_FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <api_setup.hpp>

#include <google/protobuf/util/json_util.h>

#if defined(_MSC_VER)
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <time.h>

// Waiting time during actions
const auto ACTION_WAITING_TIME = std::chrono::seconds(1);

std::function<void(k_api::Base::ActionNotification)> check_for_end_or_abort(bool& finished);
int64_t GetTickUs();
void move_to_home_position(k_api::Base::BaseClient* base);
k_api::BaseCyclic::Command setup_actuators_low_level(k_api::Base::BaseClient* base, k_api::BaseCyclic::BaseCyclicClient* base_cyclic, int actuator_count);


#endif 