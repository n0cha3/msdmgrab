cmake_minimum_required(VERSION 3.11.x)
project("msdmgrab" C)
set(CMAKE_C_STANDARD 99)
add_executable(${PROJECT_NAME} main.c linux.c)