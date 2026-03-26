cmake_minimum_required(VERSION 3.10)
project(ufo)

set(CMAKE_CXX_STANDARD 11)

add_executable(ufo src/ufo/main.c)
target_include_directories(ufo PRIVATE src/ufo)
