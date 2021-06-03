/*
 * KINOVA (R) KORTEX (TM)
 *
 * Copyright (c) 2021 Kinova inc. All rights reserved.
 *
 * This software may be modified and distributed
 * under the terms of the BSD 3-Clause license.
 *
 * Refer to the LICENSE file for details.
 *
 */

#ifndef KORTEX_EXAMPLES_UTILITIES_H
#define KORTEX_EXAMPLES_UTILITIES_H

#include <cxxopts.hpp>

struct ExampleArgs
{
    std::string ip_address;
    std::string   username;
    std::string   password;
};

ExampleArgs ParseExampleArguments(int argc, char *argv[]);

#endif //KORTEX_EXAMPLES_UTILITIES_H