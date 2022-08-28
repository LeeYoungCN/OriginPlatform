#!/bin/bash
source ./project_config.sh
cd ${root_path}

if [ ! -d buildcache ]; then
    mkdir buildcache
fi

if [[ "$*" =~ "clean" ]]; then
    rm -rf ${buildcache_path}/*
fi

rm -rf ${output_path}
rm -rf ${release_path}

if [[ ${os} == "MINGW"* ]]; then
    cmake -S . -B ${buildcache_path}  -G "MinGW Makefiles"
else
    cmake -S . -B ${buildcache_path}
fi

cmake --build ${buildcache_path}
cmake --install ${buildcache_path} --component ${component_name}

