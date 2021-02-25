cmake_minimum_required(VERSION 3.15)
project(marketdata_ex)
set(CMAKE_CXX_STANDARD 17)

find_package(cbpro++ REQUIRED)

add_executable(marketdata_ex main.cpp)
target_link_libraries(marketdata_ex PRIVATE cbpro++::cbpro++)