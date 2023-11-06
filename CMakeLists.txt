cmake_minimum_required(VERSION 3.26)
project(SortingAlgorithm C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -Wall -Wextra -Wpedantic -Werror ")

add_executable(SortingAlgorithm main.c)
