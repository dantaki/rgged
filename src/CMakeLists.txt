cmake_minimum_required(VERSION 2.8)
project(rgged)
set( CMAKE_C_FLAGS "-Wall -g -O3")
include_directories (../lib/bamtools/src)
add_executable(rgged rgged.cc)
TARGET_LINK_LIBRARIES(rgged BamTools-static)
