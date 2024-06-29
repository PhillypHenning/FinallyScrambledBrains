cmake_minimum_required(VERSION 3.29.6)

# Set the project name and version
project(FinallyScrambledBrains VERSION 0.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the executable
add_executable(FinallyScrambledBrains
    src/main.cpp
    src/FSM.cpp
    src/state_machine/State.cpp
    src/state_machine/Idle/IdleState.cpp
    src/state_machine/Walk/WalkState.cpp
)