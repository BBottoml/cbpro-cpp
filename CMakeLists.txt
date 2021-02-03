cmake_minimum_required(VERSION 3.15.0)
project(cbpro++ LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)

# TODO:
# Add support for install prefix (deprecate usage of INCLUDEDIR and LIBDIR) (DONE)
# Add support for custom Boost root
# Add support for find_package command and further general lib installation

# find files
file(GLOB cbpro++_TOP_HEADERS include/*.h)
file(GLOB cbpro++_MDATA_HEADERS include/marketdata/*.h)
file(GLOB cbpro++_RESPONSES_HEADERS include/responses/*.h)
set(cbpro++_PUBLIC_HEADERS ${cbpro++_TOP_HEADERS} ${cbpro++_MDATA_HEADERS} ${cbpro++_RESPONSES_HEADERS})

source_group("Header Files\\cbpro++" FILES ${cbpro++_TOP_HEADERS})
source_group("Header Files\\cbpro++\\marketdata" FILES ${cbpro++_MDATA_HEADERS})
source_group("Header Files\\cbpro++\\responses" FILES ${cbpro++_RESPONSES_HEADERS})

file(GLOB_RECURSE cbpro++_PRIVATE_HEADERS src/*.hpp)
file(GLOB_RECURSE cbpro++_SOURCES src/*.cpp)

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

add_library(cbpro++ ${cbpro++_SOURCES} ${cbpro++_PUBLIC_HEADERS} ${cbpro++_PRIVATE_HEADERS})

target_link_libraries(cbpro++ PRIVATE spdlog::spdlog OpenSSL::SSL OpenSSL::Crypto ${BOOST_INCLUDE_LIBS})
target_include_directories(cbpro++ PRIVATE SYSTEM ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})

target_include_directories(
        cbpro++
        PUBLIC
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

#target_compile_options(cbpro++ PRIVATE -Wall)

install(DIRECTORY include/ DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(TARGETS cbpro++
        EXPORT cbpro++_export
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )

configure_file("cmake/cbpro++-config.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cbpro++-config.cmake" @ONLY)

install(
        EXPORT cbpro++_export
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/cbpro++"
        NAMESPACE "cbpro++::"
        # In this CMake config file no dependencies are considered. But since we
        # do not use any `find_package` call here this approach is sufficient.
        FILE cbpro++-targets.cmake
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cbpro++-config.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/cbpro++")

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "CBPro++")
SET(CPACK_PACKAGE_VENDOR "BBottoml")
SET(CPACK_PACKAGE_VERSION "1.0.0")
SET(CPACK_GENERATOR "RPM;DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Nobody")
INCLUDE(CPack)