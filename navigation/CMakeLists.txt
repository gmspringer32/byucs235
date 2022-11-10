cmake_minimum_required(VERSION 3.23)
project(Lab2_NavigationCode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab2_NavigationCode
        graphicsStuff.cpp
        main.cpp
        NavigationInterface.h Navigation.cpp Navigation.h)
