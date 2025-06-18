cmake_minimum_required(VERSION 3.10)

# Project name
project(TicTacToe)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files from 'include/' directory
include_directories(include)

# Collect all .cpp files in the src/ directory
file(GLOB SOURCES "src/*.cpp")

# Define the main executable
add_executable(TicTacToe ${SOURCES})

# Optional: Enable verbose compiler warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(TicTacToe PRIVATE -Wall -Wextra -pedantic)
elseif (MSVC)
    target_compile_options(TicTacToe PRIVATE /W4)
endif()

# ----------------------
# Google Test Setup
# ----------------------

# Enable testing
enable_testing()

# Find GoogleTest package manually built in CI
find_package(GTest REQUIRED)

# Collect test source files (adjust as needed)
file(GLOB TEST_SOURCES "tests/*.cpp")

# Define the test executable
add_executable(TicTacToeTests ${TEST_SOURCES})

# Link test executable with GoogleTest + pthread
target_link_libraries(TicTacToeTests GTest::GTest GTest::Main pthread)

# Add a test for ctest to run
add_test(NAME TicTacToeTests COMMAND TicTacToeTests)
