cmake_minimum_required(VERSION 3.6)
project(Include_c__)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    String_addon.cpp
    String_addon.h)

add_executable(Include_c__ ${SOURCE_FILES})