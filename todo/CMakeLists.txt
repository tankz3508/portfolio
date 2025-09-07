cmake_minimum_required(VERSION 4.0)
project(todo)

set(CMAKE_CXX_STANDARD 23)

add_executable(todo src/main.cpp
        include/todo.h
        src/todo.cpp)
