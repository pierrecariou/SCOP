cmake_minimum_required(VERSION 3.10)

# set the project name
project(scop)

add_subdirectory(lib/glad)
add_subdirectory(lib/glfw-3.3.7)

# add the executable
add_executable(scop src/scop.cpp src/glad.c)

target_link_libraries(scop PUBLIC glad glfw)

#message("DIR:  ${PROJECT_BINARY_DIR}")

target_include_directories(scop PUBLIC include/)
