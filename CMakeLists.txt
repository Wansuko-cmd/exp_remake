cmake_minimum_required(VERSION 3.24)
project(exp2 C)

set(CMAKE_C_STANDARD 11)

add_executable(exp2 main.c domain/date.c domain/date.h domain/profile.h domain/profile.c)
