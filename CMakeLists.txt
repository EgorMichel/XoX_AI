cmake_minimum_required(VERSION 3.24)
project(XoXAI LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

add_executable(XoXAI main.cpp)

target_link_libraries(XoXAI XoX)
