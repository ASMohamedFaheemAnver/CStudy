cmake_minimum_required(VERSION 3.14)
project(CStudy C)

set(CMAKE_C_STANDARD 99 )

add_executable(CStudy main.c)
target_link_libraries(${PROJECT_NAME} pthread)
