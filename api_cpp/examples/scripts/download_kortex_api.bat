echo off
echo Checking if you need to download Kortex API
set /A return_code=1
:: Check if OS-specific folders were copied in kortex_api 
if exist ..\kortex_api\win_mingw_x86\ (
    echo Found the folder win_mingw_x86
    set /A return_code=0
) else (
    echo Could not find folder win_mingw_x86 in folder kortex_api
)

if exist ..\kortex_api\win_msvc_x86-64\ (
    echo Found the folder win_msvc_x86-64
    set /A return_code=0
) else (
    echo Could not find folder win_msvc_x86-64 in folder kortex_api
)

:: If not, check if include and lib folders were copied in kortex_api
if exist ..\kortex_api\include\ (
    echo Found the folder include
    if exist ..\kortex_api\lib\ (
        echo Found the folder lib
        set /A return_code=0
    )
)

if /I "%return_code%" equ "1" (
    echo You need to download the Kortex API
    echo Please download it here : https://artifactory.kinovaapps.com/ui/repos/tree/General/generic-public%2Fkortex%2FAPI%2F2.2.0
    echo Choose the proper archive for your target
    echo Unzip it in api_cpp\examples\kortex_api
)

exit %return_code%