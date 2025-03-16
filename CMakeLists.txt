cmake_minimum_required(VERSION 3.16)
project(ATmega328P_Simulator LANGUAGES CXX)

# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set SystemC path (submodule location)
set(SYSTEMC_HOME ${CMAKE_SOURCE_DIR}/external/systemc)

# Include SystemC directories
include_directories(${SYSTEMC_HOME}/include)
link_directories(${SYSTEMC_HOME}/lib)

# Add SystemC as a subdirectory to build it
add_subdirectory(${SYSTEMC_HOME})

# Add source files
set(SOURCES src/main.cpp)

# Define the executable
add_executable(simulator ${SOURCES})

# Link SystemC library
target_link_libraries(simulator systemc)
