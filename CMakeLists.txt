# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(MyProgram)

# Set C/C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra)

# Define source files
set(SRC_FILES src/main.c src/exercises.c)

# Define the executable
add_executable(my_program ${SRC_FILES})

####################### TESTING STUFF STARTS HERE ###########################################################

enable_testing()
add_subdirectory(tests)