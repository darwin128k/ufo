cmake_minimum_required(VERSION 3.10)
project(ufo VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Build settings passed to the SDL subproject.
# The current submodule (libsdl-org/SDL) is SDL3 (headers in include/SDL3).
set(SDL_SHARED ON CACHE BOOL "" FORCE)
set(SDL_STATIC OFF CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(ufo 
                    src/ufo/main.c
                    src/ufo/ufo.c
                    src/ufo/driver.c
                    src/ufo/entity.c
                    src/ufo/window.c
                    src/ufo/layer.c
                    src/ufo/display.c
                    src/ufo/monitor.c

                    src/ufo/driver/gl.c
                    src/ufo/driver/sdl.c
)
target_include_directories(ufo PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL3/include"
)

add_subdirectory(lib/SDL3 EXCLUDE_FROM_ALL)
target_link_libraries(ufo PRIVATE SDL3::SDL3)

if(WIN32)
  target_link_libraries(ufo PRIVATE opengl32)

  # Copy SDL runtime next to ufo.exe for local runs.
  if(TARGET SDL3::SDL3-shared)
    add_custom_command(
      TARGET ufo POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3::SDL3-shared>
        $<TARGET_FILE_DIR:ufo>
      VERBATIM
    )
  endif()
endif()