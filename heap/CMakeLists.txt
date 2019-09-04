cmake_minimum_required(VERSION 3.14)
project(heap C)

set(CMAKE_C_STANDARD 11)

add_executable(heap main.c mystd.h heapOperation.c)