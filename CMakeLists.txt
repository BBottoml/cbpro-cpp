cmake_minimum_required(VERSION 3.15.0)
project(cbpro++ LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)

# gather headers
file(GLOB cbpro++_TOP_HEADERS include/*.h)
file(GLOB cbpro++_MDATA_HEADERS include/marketdata/*.h)
file(GLOB cbpro++_ACCOUNTS_HEADERS include/accounts/*.h)
file(GLOB cbpro++_ORDERS_HEADERS include/orders/*.h)
file(GLOB_RECURSE cbpro++_PRIVATE_HEADERS src/*.hpp)
file(GLOB_RECURSE cbpro++_SOURCES src/*.cpp)
source_group("Header Files\\cbpro++" FILES ${cbpro++_TOP_HEADERS})
source_group("Header Files\\cbpro++\\marketdata" FILES ${cbpro++_MDATA_HEADERS})
source_group("Header Files\\cbpro++\\accounts" FILES ${cbpro++_ACCOUNTS_HEADERS})
source_group("Header Files\\cbpro++\\orders" FILES ${cbpro++_ORDERS_HEADERS})

set(cbpro++_PUBLIC_HEADERS ${cbpro++_TOP_HEADERS} ${cbpro++_MDATA_HEADERS} ${cbpro++_ACCOUNTS_HEADERS} ${cbpro++_ORDERS_HEADERS})

# dependency handling
set(cbpro++_PUBLIC_HEADERS ${cbpro++_TOP_HEADERS} ${cbpro++_MDATA_HEADERS} ${cbpro++_ACCOUNTS_HEADERS} ${cbpro++_ORDERS_HEADERS})
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/install)
set(OPENSSL_USE_STATIC_LIBS TRUE)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED)

add_library(cbpro++ ${cbpro++_SOURCES} ${cbpro++_PUBLIC_HEADERS} ${cbpro++_PRIVATE_HEADERS})

target_link_libraries(cbpro++ PRIVATE OpenSSL::SSL OpenSSL::Crypto ${CMAKE_THREAD_LIBS_INIT} ${BOOST_INCLUDE_LIBS})
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
        FILE cbpro++-targets.cmake
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cbpro++-config.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/cbpro++")

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "cbpro++")
SET(CPACK_PACKAGE_VENDOR "bbottoml")
SET(CPACK_PACKAGE_VERSION "1.0.0")
SET(CPACK_GENERATOR "RPM;DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "N/A")
INCLUDE(CPack)