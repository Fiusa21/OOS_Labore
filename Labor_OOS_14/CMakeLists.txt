cmake_minimum_required(VERSION 3.27)
project(Labor_OOS_14)

set(CMAKE_CXX_STANDARD 23)

add_executable(Labor_OOS_14 main.cpp
        Worker.cpp
        Manager.cpp
        Employee.cpp)
