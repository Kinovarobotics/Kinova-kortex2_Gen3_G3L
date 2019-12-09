# First argument, build type, must be Debug or Release (default: Release)
# Second argument, kortex api sub-directory, is optional (default: empty)
if [ -z "$1" ]
then
    build_type="release"
else
    build_type="${1}"
fi
build_folder="build-gcc-${build_type}"

kortex_api_folder="$2"

mkdir -p ${build_folder}
cd ${build_folder}
rm -rf *

cmake .. -DCMAKE_BUILD_TYPE=${build_type} -DKORTEX_SUB_DIR=${kortex_api_folder} && make