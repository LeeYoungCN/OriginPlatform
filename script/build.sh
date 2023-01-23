#!/bin/bash
script_path=$(cd $(dirname "$0"); pwd)
root_path=$(cd ${script_path}/..; pwd)
source ${script_path}/project_config.sh

enable_clean=1
enable_install=1
build_type="Debug"
target="${lib_target_name}"
verbose=OFF
args=$(getopt -o civrgt: --long clean,install,verbose,release,gtest,target: -n "$0" -- "$@")
eval set -- "${args}"
echo ${args}
while true; do
    case ${1} in
        -c|--clean)
            enable_clean=0
            shift 1
        ;;
        -i|--install)
            enable_install=0
            shift 1
        ;;
        -v|--verbose)
            verbose="ON"
            shift 1
        ;;
        -t|--target)
            target="$2"
            shift 2
        ;;
        -g|--gtest)
            target="${test_target_name}"
            shift 1
        ;;
        -r|--release)
            build_type="Release"
            shift 1
        ;;
        --)
            shift 1
            break
        ;;
        *)
            echo "Param error: ${1}"
            exit 1
        ;;
    esac
done

if [ ! -d ${buildcache_path} ]; then
    mkdir -p ${buildcache_path}
fi

if [ ${enable_clean} -eq 0 ]; then
    rm -rf ${buildcache_path}/*
fi

# config
cofig_args=""
if [ ${os} == "Windows" ]; then
   config_args="-G \"MinGW Makefiles\" "
fi

cmake -S "${root_path}" \
      -B "${buildcache_path}" \
      -DCMAKE_BUILD_TYPE:STRING="${build_type}" \
      -DCMAKE_VERBOSE_MAKEFILE:BOOL="${verbose}" \
      ${config_args}
# build
cmake --build ${buildcache_path} --target ${target}

# install
if [ -d "${release_path}" ]; then
    rm -rf "${release_path}"
fi
if [ ${enable_install} -eq 0 ]; then
    cmake --install ${buildcache_path} --component ${component_name}
fi
# make all -j
# make install

