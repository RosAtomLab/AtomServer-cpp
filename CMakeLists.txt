# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.15)

project(AtomServer)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(server ${HEADERS} ${SOURCES})

find_package(Boost REQUIRED)

target_link_libraries(server Boost)