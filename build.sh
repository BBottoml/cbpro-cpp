#!/bin/bash

mkdir temp
cd temp

# spdlog installation 
git clone https://github.com/gabime/spdlog.git
cd spdlog && mkdir build && cd build
cmake -DCMAKE_CXX_STANDARD=17 -DCMAKE_INSTALL_PREFIX=../../../install .. && make -j 
make install
cd ../../

# boost installation 
wget https://dl.bintray.com/boostorg/release/1.66.0/source/boost_1_66_0.tar.bz2
tar --bzip2 -xf ./boost_1_66_0.tar.bz2
mv ./boost_1_66_0 ../install

cd ../
rm -rf temp
