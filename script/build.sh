#!/bin/bash
source ./project_config.sh
cd ${root_path}

if [ ! -d buildcache ]; then
    mkdir buildcache
fi

if [[ "$*" =~ "clean" ]]; then
    rm -rf ${buildcache_path}/*
fi

build_type="Release"

if [[ "$*" =~ "Debug" ]]; then
    build_type="Debug"
fi

rm -rf ${output_path}
rm -rf ${release_path}

if [[ ${os} == "MINGW"* ]]; then
    cmake -S . -B ${buildcache_path} -DCMAKE_BUILD_TYPE:STRING=${build_type} -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -G "MinGW Makefiles"
else
    cmake -S . -B ${buildcache_path} -DCMAKE_BUILD_TYPE:STRING=${build_type} -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON
fi

cmake --build ${buildcache_path}
cmake --install ${buildcache_path} --component ${component_name}
# pushd  ${buildcache_path}
# make all -j
# make install

