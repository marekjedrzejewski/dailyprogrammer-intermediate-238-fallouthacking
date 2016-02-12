cmake_minimum_required(VERSION 3.3)
project(intermediate_238_fallouthacking)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Dictionary.cpp Dictionary.h HackEngine.cpp HackEngine.h HackInterface.cpp HackInterface.h)
add_executable(intermediate_238_fallouthacking ${SOURCE_FILES})