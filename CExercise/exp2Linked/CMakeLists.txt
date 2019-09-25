cmake_minimum_required(VERSION 3.14)
project(exp2Linked C)

set(CMAKE_C_STANDARD 11)

add_executable(exp2Linked main.c LinkedOp.c linkedHead.h)