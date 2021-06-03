echo "Checking if you need to download Kortex API..."
return_code=1
# Check if OS-specific folders were copied in kortex_api 
if [ -d "../kortex_api/linux_gcc_x86-64" ]; then
    echo "Found the folder linux_gcc_x86-64"
    return_code=0
else
    echo "Could not find folder linux_gcc_x86 in folder kortex_api"
fi

# If not, check if include and lib folders were copied in kortex_api
if [ -d "../kortex_api/include/" ]; then
    echo "Found the folder include"
    if [ -d "../kortex_api/lib/" ]; then
        echo "Found the folder lib"
        return_code=0
    else
        echo "Could not find the folder lib"
    fi
else
    echo "Could not find the folder include"
fi

if [ "${return_code}" -eq "1" ]; then
    echo "You need to download the Kortex API"
    echo "Please download it here : https://artifactory.kinovaapps.com/ui/repos/tree/General/generic-public%2Fkortex%2FAPI%2F2.2.0"
    echo "Choose the proper archive for your target"
    echo "Unzip it in api_cpp\examples\kortex_api"
fi

exit ${return_code}