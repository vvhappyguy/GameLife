cmake_minimum_required(VERSION 3.13)
project(GameLife C)

set(CMAKE_C_STANDARD 11)

add_executable(GameLife main.c main.h logging.c logging.h game.h game.c)