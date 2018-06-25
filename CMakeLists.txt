cmake_minimum_required(VERSION 3.10)
project(ClionProject C)

set(CMAKE_C_STANDARD 99)

add_executable(ClionProject main.c assess.c assess.h board.h board.c generator.h generator.c alphabeta.c alphabeta.h)