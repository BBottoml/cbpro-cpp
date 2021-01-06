cmake_minimum_required(VERSION 3.15.0)
project(cbpro++ LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# TODO:
# Add support for install prefix (deprecate usage of INCLUDEDIR and LIBDIR) (DONE)
# Add support for custom Boost root
# Add support for find_package command and further general lib installation

# find files
file(GLOB cbpro++_PUBLIC_HEADERS include/cbpro++/*)
file(GLOB cbpro++_PRIVATE_HEADERS src/*.hpp src/util/*.hpp)
file(GLOB cbpro++_SOURCES src/*.cpp src/util/*.cpp)

# dependency handling
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/install)
find_package(Threads REQUIRED)
find_package(spdlog REQUIRED)

add_library(cbpro++ ${cbpro++_SOURCES} ${cbpro++_PUBLIC_HEADERS} ${cbpro++_PRIVATE_HEADERS})

target_link_libraries(cbpro++ PRIVATE spdlog::spdlog)
target_include_directories(cbpro++ PRIVATE SYSTEM ${CMAKE_SOURCE_DIR}/install/boost_1_72_0
        ${cbpro++_PUBLIC_HEADERS} ${cbpro++_PRIVATE_HEADERS})

target_include_directories(
        cbpro++
        PUBLIC
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>")

target_compile_options(cbpro++ PRIVATE -Wall -Wextra)

install(FILES ${cbpro++_PUBLIC_HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/cbpro++)
install(TARGETS cbpro++
        EXPORT cbpro++_export
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/
        )