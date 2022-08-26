#!/bin/bash
source ./project_config.sh
cd ..

if [ ! -d buildcache ]; then
    mkdir buildcache
fi

if [[ "$*" =~ "clean" ]]; then
    rm -rf ${cache_path}/*
fi

rm -rf ${output_path}
rm -rf ${release_path}

os=$(uname -s)
os=${os%_*}
if [[ ${os} == "MINGW"* ]]; then
    cmake -S . -B ${cache_path}  -G "MinGW Makefiles"
else
    cmake -S . -B ${cache_path}
fi

cmake --build ${cache_path}
cmake --install ${cache_path} --component ${component_name}

