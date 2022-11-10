cmake_minimum_required(VERSION 3.23)
project(TODO_list_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(TODO_list_project main.cpp TodoListInterface-1.h TodoListInterface.h TodoListInterface.cpp TodoListInterface.h TodoList.cpp TodoList.h)
