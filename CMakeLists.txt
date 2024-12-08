cmake_minimum_required(VERSION 3.11.x)
project("msdmgrab" C)
set(CMAKE_C_STANDARD 99)

if(MSVC)
  add_executable(${PROJECT_NAME} main.c win32.c)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
  SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\" /SUBSYSTEM:CONSOLE")

else()
  add_executable(${PROJECT_NAME} main.c linux.c)
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -std=c99 -O2)
endif()