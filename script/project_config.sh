#!/bin/bash
os=$(uname -s)
os=${os%_*}
echo "os=${os}"
curr_path=$(pwd)
if [ "${curr_path##*/}" == "script" ]; then
    cd ..
fi
root_path=$(pwd)
echo "root_path=${root_path}"
buildcache_path=${root_path}/buildcache
echo "buildcache_path=${buildcache_path}"
output_path=${root_path}/output
echo "output_path=${output_path}"
release_path=${root_path}/release
echo "release_path=${release_path}"


component_name=OriginPlatform
test_exe=RunTest
