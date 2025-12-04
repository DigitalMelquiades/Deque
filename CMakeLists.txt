cmake_minimum_required(VERSION 4.0)
project(deque)

set(CMAKE_CXX_STANDARD 20)

add_executable(deque main.cpp
        Deque.h
        Deque.cpp)
