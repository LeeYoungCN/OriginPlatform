#!/bin/bash
cd ..

cache_path=buildcache
output_path=output
release_path=release
component_name=OriginPlatform
test_exe=RunTest
exe_suffix=""

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
    exe_suffix=".exe"
else
    cmake -S . -B ${cache_path}
fi

cmake --build ${cache_path}
cmake --install ${cache_path} --component ${component_name}

./${output_path}/${test_exe}${exe_suffix}
