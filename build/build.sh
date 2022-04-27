#!/bin/bash
cd ..

if [ ! -d buildcache ]; then
    mkdir buildcache
fi
os=$(uname -s)
os=${os%_*}
    
pushd ./buildcache
rm -rf *
if [[ ${os} == "MINGW"* ]]; then
    cmake -S .. -G "MinGW Makefiles"
else
    cmake -S ..
fi
make -j8
make install
popd
./output/TestPlatform.exe
