cmake_minimum_required(VERSION 3.19)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 14)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
include_directories(include)
aux_source_directory(src SRC_LIST)

add_executable(main main.cpp ${SRC_LIST} include/prototype.hpp include/proxy.hpp)
