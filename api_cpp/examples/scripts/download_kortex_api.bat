echo off
echo Checking if you need to download Kortex API
set /A return_code=1
:: Change forward slash to backslash for Windows directory
set subdir=%1:/=\%

:: If not, check if include and lib folders were copied in kortex_api
if exist ..\kortex_api\%subdir%include\ (
    echo Found the folder include
    if exist ..\kortex_api\%subdir%lib\ (
        echo Found the folder lib
        set /A return_code=0
    )
)

if /I "%return_code%" equ "1" (
    echo You need to download the Kortex API
    echo Please download it here : https://artifactory.kinovaapps.com/artifactory/generic-public/kortex/API/2.3.0/
    echo Choose the proper archive for your target
    echo Unzip it in api_cpp\examples\kortex_api
)

exit %return_code%
