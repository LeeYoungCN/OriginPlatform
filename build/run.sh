#!/bin/bash
source ./project_config.sh
cd ..
exe_suffix=""

os=$(uname -s)
os=${os%_*}
if [[ ${os} == "MINGW"* ]]; then
    exe_suffix=".exe"
fi

./${output_path}/${test_exe}${exe_suffix}
