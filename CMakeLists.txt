cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror -std=c++17")

# set the project name
project(scop)

add_subdirectory(lib/glad)
add_subdirectory(lib/glfw-3.3.7)
add_subdirectory(lib/glm)
#add_subdirectory(lib/assimp)


# add the executable
add_executable(scop src/scop.cpp)

target_link_libraries(scop PUBLIC glad glfw glm)

target_include_directories(scop PUBLIC include/)
#message("DIR:  ${PROJECT_BINARY_DIR}")
