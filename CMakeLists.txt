cmake_minimum_required(VERSION 3.24)
project(exp2 C)

set(CMAKE_C_STANDARD 11)

add_executable(exp2 main.c domain/date.c domain/date.h domain/profile.h domain/profile.c domain/profiles.h domain/profiles.c usecase/command/register.h usecase/result.h usecase/result.c usecase/command/register.c utils/char_utils.h utils/char_utils.c usecase/parser.c usecase/parser.h usecase/command/print.c usecase/command/print.h usecase/command/find.c usecase/command/find.h usecase/command/sort.c usecase/command/sort.h usecase/command/delete.c usecase/command/delete.h usecase/command/read.c usecase/command/read.h usecase/command/write.c usecase/command/write.h)
