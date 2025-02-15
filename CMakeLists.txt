cmake_minimum_required(VERSION 3.10)
project(cvector)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add executable
add_executable(cvector_test 
    src/vector.c
    src/main.c
)

# Include directories
target_include_directories(cvector_test PRIVATE include)