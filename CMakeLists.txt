cmake_minimum_required(VERSION 3.21)
project(engine)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_subdirectory(./third-party/glad/)

add_executable(engine main.cpp src/shader/shader.cpp src/shader/shader.h src/shader/shader_program.cpp src/shader/shader_program.h src/resource_manager.cpp src/resource_manager.h)

include_directories(src)
include_directories(third-party/stb-image)

target_link_libraries(engine OpenGL::GL glfw glad ${CMAKE_DL_LIBS})
