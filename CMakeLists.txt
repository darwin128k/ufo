cmake_minimum_required(VERSION 3.10)
project(ufo VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Build settings passed to the SDL subproject.
# The current submodule (libsdl-org/SDL) is SDL3 (headers in include/SDL3).
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(ufo src/ufo/main.c)
target_include_directories(ufo PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_subdirectory(lib/SDL3 EXCLUDE_FROM_ALL)
target_link_libraries(ufo PRIVATE SDL3::SDL3)