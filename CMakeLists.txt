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
set(OPENSSL_USE_STATIC_LIBS TRUE)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(spdlog REQUIRED)
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED)

add_library(cbpro++ ${cbpro++_SOURCES} ${cbpro++_PUBLIC_HEADERS} ${cbpro++_PRIVATE_HEADERS} src/util/Base64.h)

target_link_libraries(cbpro++ PRIVATE spdlog::spdlog OpenSSL::SSL OpenSSL::Crypto ${BOOST_INCLUDE_LIBS})
target_include_directories(cbpro++ PRIVATE SYSTEM
        ${cbpro++_PUBLIC_HEADERS} ${cbpro++_PRIVATE_HEADERS} ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})

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

configure_file("cmake/cbpro++-config.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cbpro++-config.cmake" @ONLY)

install(
        EXPORT cbpro++_export
        DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cbpro++"
        NAMESPACE "cbpro++::"
        # In this CMake config file no dependencies are considered. But since we
        # do not use any `find_package` call here this approach is sufficient.
        FILE cbpro++-targets.cmake
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cbpro++-config.cmake"
        DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cbpro++")

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "CBPro++")
SET(CPACK_PACKAGE_VENDOR "BBottoml")
SET(CPACK_PACKAGE_VERSION "1.0.0")
SET(CPACK_GENERATOR "RPM;DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Nobody")
INCLUDE(CPack)