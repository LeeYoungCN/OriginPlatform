#!/bin/bash
cd ..

cache_path=buildcache
output_path=output
release_path=release
component_name=PublicFunctionTest
test_exe=${RunTest}

if [ ! -d buildcache ]; then
    mkdir buildcache
fi

rm -rf ${cache_path}
rm -rf ${output_path}
rm -rf ${release_path}

os=$(uname -s)
os=${os%_*}
if [[ ${os} == "MINGW"* ]]; then
    cmake -S . -B ${cache_path}  -G "MinGW Makefiles"
else
    cmake -S . -B ${cache_path}
fi
cmake --build ${cache_path} -j8
cmake --install ${cache_path} --component ${component_name}

./${output_path}/${test_exe}*
