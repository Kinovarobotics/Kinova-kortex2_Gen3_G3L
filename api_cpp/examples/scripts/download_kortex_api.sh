echo "Checking if you need to download Kortex API..."
return_code=1
# check if include and lib folders were copied in kortex_api or in the sub-folder passed in param
if [ -d "../kortex_api/${1}include/" ]; then
    echo "Found the folder include"
    if [ -d "../kortex_api/${1}lib/" ]; then
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
    echo "Please download it here : https://artifactory.kinovaapps.com/artifactory/generic-public/kortex/API/2.3.0/"
    echo "Choose the proper archive for your target"
    echo "Unzip it in api_cpp\examples\kortex_api"
fi

exit ${return_code}