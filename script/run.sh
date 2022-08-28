#!/bin/bash
source ./project_config.sh
cd ${root_path}
exe_suffix=""

if [[ ${os} == "MINGW"* ]]; then
    exe_suffix=".exe"
fi

./${output_path}/${test_exe}${exe_suffix}
