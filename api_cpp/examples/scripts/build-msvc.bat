@ECHO OFF

: First argument, build type, must be debug or release (default: release)
: Second argument, MSVC runtime, must be static or dynamic (default: static)
: Third argument, kortex api sub-directory, is optional (default: empty)
set build_type=%1 
IF "%build_type%"=="" (SET build_type="release")
set build_folder=build-msvc-%build_type%
set msvc_runtime=%2 
set kortex_api_folder=%3

mkdir %build_folder%
: Give write permission to everyone in build folder
ICACLS %build_folder% /grant Everyone:F /t

pushd %build_folder%
del * /s /f /q

SET /A errno=0
cmake .. -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=%build_type% -DMSVC_RUNTIME=%msvc_runtime% -DKORTEX_SUB_DIR=%kortex_api_folder% && nmake
SET /A errno=%ERRORLEVEL% 
popd

EXIT /B %errno%