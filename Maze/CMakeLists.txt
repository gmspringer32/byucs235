cmake_minimum_required(VERSION 3.23)
project(Lab4Maze)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab4Maze main.cpp Pathfinder.cpp Pathfinder.h PathfinderInterface.h)
