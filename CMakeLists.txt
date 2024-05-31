# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.15)

# Name of the project
project(AtomServer)

# Add a library to this build. The name of the library is MyLibrary and it
# consists of only the MyLibrary.cpp file
#add_library(MyLibrary src/MyLibrary.cpp)

file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)


add_executable(server Main.cpp)