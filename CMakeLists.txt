cmake_minimum_required(VERSION 3.16)

project(Example)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_CXX_FLAGS "-static")

set(SerenityOS_SOURCE_DIR /home/anon/Code/serenity)
include(${SerenityOS_SOURCE_DIR}/Meta/CMake/code_generators.cmake)
add_custom_target(all_generated)
include_directories(${SerenityOS_SOURCE_DIR}/Userland/Libraries)

compile_gml(src/ExampleWindow.gml ExampleWindowGML.h example_window_gml)

set(SOURCES
    src/main.cpp
    ExampleWindowGML.h
)

add_executable(Example ${SOURCES})
target_link_libraries(Example gui core gcc_s gcc_eh)

install(TARGETS Example RUNTIME DESTINATION bin)
