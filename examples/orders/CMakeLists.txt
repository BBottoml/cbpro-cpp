cmake_minimum_required(VERSION 3.15)
project(order_ex)
set(CMAKE_CXX_STANDARD 17)

find_package(cbpro++ REQUIRED)

add_executable(order_ex main.cpp)
target_link_libraries(order_ex PRIVATE cbpro++::cbpro++)
