cmake_minimum_required(VERSION 3.29.6)
project(FinallyScrambledBrains VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the shared library
add_library(FinallyScrambledBrains SHARED
    src/FSM.cpp
    src/state_machine/State.cpp
    src/state_machine/Idle/IdleState.cpp
    src/state_machine/Walk/WalkState.cpp
)

# Install targets
install(TARGETS FinallyScrambledBrains
    LIBRARY DESTINATION lib          # For shared libraries
    ARCHIVE DESTINATION lib/static   # For static libraries
    RUNTIME DESTINATION bin          # For executables
)

install(DIRECTORY include/ DESTINATION include)