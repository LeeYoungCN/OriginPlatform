#!/bin/bash
os="$(uname -s)"
if [[ ${os} =~ "MingGW" ]];
    os="Windows"
fi
echo "os=${os}"
buildcache_path="${root_path}/buildcache"
echo "buildcache_path=${buildcache_path}"
release_path=${root_path}/release
echo "release_path=${release_path}"

lib_target_name="origin"
test_target_name="test_origin"

test_exe_name="${test_target_name}"
test_exe_path="${buildcache_path}/bin"

component_name="OriginPlatform"
