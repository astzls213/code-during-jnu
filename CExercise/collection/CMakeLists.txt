cmake_minimum_required(VERSION 3.14)
project(collection C)

set(CMAKE_C_STANDARD 11)

add_executable(collection main.c mystd.h collectionOp.c)