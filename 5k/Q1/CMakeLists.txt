cmake_minimum_required(VERSION 3.23)
project(Q1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Q1 main.c core-types.c core-types.h linkedlist.c linkedlist.h utils.c utils.h)
