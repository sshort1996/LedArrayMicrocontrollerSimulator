cmake_minimum_required(VERSION 3.10)
project(EMBEDDED_SIM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add executables
add_executable(logMod src/MicroController/microLogic.cpp)
add_executable(memMod src/MicroController/microMem.cpp)
add_executable(main src/main.cpp)

# Set compilation flags
target_compile_options(logMod PRIVATE -Wall -O2)
target_compile_options(memMod PRIVATE -Wall -O2)
target_compile_options(main PRIVATE -fopenmp -g)

# Include directories and link libraries (uncomment and adjust as needed)
# target_include_directories(progA PRIVATE include/)
# target_link_libraries(progB PRIVATE mylib)