#!/bin/bash
script_path=$(cd $(dirname "$0"); pwd)
root_path=$(cd ${script_path}/..; pwd)

source ${script_path}/project_config.sh
#args=$(getopt -o civrgt: --long clean,install,verbose,release,gtest,target -n "$0" -- "$@")
#eval set -- "${args}"
${script_path}/build.sh -g "$@"

if [[ ${os} == "Windows" ]]; then
    exe_suffix=".exe"
fi
${test_exe_path}/${test_exe_name}${exe_suffix}
