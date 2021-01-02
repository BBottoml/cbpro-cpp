#!/bin/bash

mkdir temp
cd temp
git clone https://github.com/gabime/spdlog.git
cd spdlog && mkdir build && cd build

cmake -DCMAKE_CXX_STANDARD=17 -DCMAKE_INSTALL_PREFIX=../../../install .. && make -j 
make install
cd ../../../
rm -rf temp
