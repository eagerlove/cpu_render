cmake_minimum_required(VERSION 3.25)

project(CPURender)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(extern/glm)
add_subdirectory(source)
