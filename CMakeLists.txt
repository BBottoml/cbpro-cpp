cmake_minimum_required(VERSION 3.15.0)
project(cbpro++ LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# temporary
set(CMAKE_INSTALL_INCLUDEDIR "/home/bbottoml/output/include/")

# find files
file(GLOB cbpro++_PUBLIC_HEADERS include/cbpro++/*)
file(GLOB cbpro++_PRIVATE_HEADERS src/*.hpp)
file(GLOB cbpro++_SOURCES src/*.cpp)

# dependency handling
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/install)
find_package(Threads REQUIRED)
find_package(spdlog REQUIRED)

add_library(cbpro++ ${cbpro++_SOURCES} ${cbpro++_PUBLIC_HEADERS} ${cbpro++_PRIVATE_HEADERS} include/cbpro++/Auth.h)

target_link_libraries(cbpro++ PRIVATE spdlog::spdlog)
# TODO: Suppress Beast compliation warnings
target_include_directories(cbpro++ PRIVATE SYSTEM ${CMAKE_SOURCE_DIR}/install/boost_1_66_0
        ${cbpro++_PUBLIC_HEADERS} ${cbpro++_PRIVATE_HEADERS})

target_include_directories(
        cbpro++
        PUBLIC
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

target_compile_options(cbpro++ PRIVATE -Wall -Wextra)

# TODO: Implement make install capabilities
install(FILES ${cbpro++_PUBLIC_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cbpro++)
install(TARGETS cbpro++
        EXPORT cbpro++_export
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )