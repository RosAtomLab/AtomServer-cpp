# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.15)
project(AtomServer)

file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

set(CMAKE_CXX_STANDARD 17)


add_executable(${PROJECT_NAME} src/Main.cpp)

find_package(Boost COMPONENTS program_options regex filesystem REQUIRED)
target_link_libraries(${PROJECT_NAME} Boost::program_options Boost::regex Boost::filesystem)
