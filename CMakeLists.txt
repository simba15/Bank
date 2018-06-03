cmake_minimum_required(VERSION 3.10)
project(Bank)

set(CMAKE_CXX_STANDARD 11)

include_directories(app)

add_executable(Bank
        app/dataOfClient.cpp
        app/dataOfClient.h
        app/main.cpp)
