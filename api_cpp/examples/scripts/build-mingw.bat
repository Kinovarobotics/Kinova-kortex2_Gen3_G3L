
: First argument, build type, must be Debug or Release (default: Release)
: Second argument, kortex api sub-directory, is optional (default: empty)
set build_type=%1 
IF "%build_type%"=="" (SET build_type="release")
set build_folder=build-mingw-%build_type%

set kortex_api_folder=%2

mkdir %build_folder%
: Give write permission to everyone in build folder
ICACLS %build_folder% /grant Everyone:F /t

cd %build_folder%
del * /s /f /q

cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=%build_type% -DKORTEX_SUB_DIR=%kortex_api_folder% && mingw32-make