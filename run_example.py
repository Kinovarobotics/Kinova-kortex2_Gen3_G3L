#! /usr/local/env python3

import os
import re
import platform
import shutil
import argparse

def run_python_example():

    example_dir = os.path.abspath("./api_python/examples")
    print(example_dir)
    
    file_to_execute = list()
    for root, dirs, files in os.walk(example_dir):
        for file in files:
            if re.match("^[0-9][0-9]-.*\.py$",file):
                file_to_execute.append(os.path.join(root, file))

    running_platform = platform.system()
    for example in file_to_execute:
        if running_platform == "Windows":
            os.system("python {0}".format(example))
        else: # assume linux and darwin execute the same
            os.system("python3 {0}".format(example))

def run_cpp_example():
    
    example_dir = os.path.abspath("./api_cpp/examples")
    build_dir = os.path.join(example_dir, "build")
    
    if os.path.isdir(build_dir):
        shutil.rmtree(build_dir, ignore_errors=False)

    os.mkdir(build_dir)
    os.chdir(build_dir)
    
    running_platform = platform.system()
    if running_platform == "Windows":
        os.system('cmake .. -G "MinGW makefiles" -DCMAKE_BUILD_TYPE=release')
        os.system('mingw32-make')
    else: #Assuming linux and darwin exexute the same
        os.system("cmake .. -DCMAKE_BUILD_TYPE=release")
        os.system("make")

    for root, dirs, files in os.walk(build_dir):
        for file in files:
            if re.match("^[0-9][0-9].*",file)and root.find("CMakeFiles") == -1: # must remove file from CMakeFiles and sub directory
                os.system(os.path.join(root, file))


def run_all_example():
    print("all")
    run_python_example()
    run_cpp_example()

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-l", "--language", action="store", 
                        type=str,
                        default="all", 
                        choices=["python", "cpp", "all"], 
                        help="Select to which language to run example" 
                        )
    args = parser.parse_args()

    if args.language == "all":
        run_all_example()
    elif args.language == "python":
        run_python_example()
    elif args.language == "cpp":
        run_cpp_example()
    else:
        pass
