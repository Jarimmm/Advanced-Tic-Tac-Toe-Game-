@@ -4,22 +4,26 @@ cmake_minimum_required(VERSION 3.10)
# Project name
project(TicTacToe)

# Use C++17 standard
# Use modern C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set include directory for header files
# Include header files from 'include/' directory
include_directories(include)

# Collect all .cpp source files inside src/
# Collect all .cpp files in the src/ directory
file(GLOB SOURCES "src/*.cpp")

# Add the executable using the collected source files
# Define the main executable
add_executable(TicTacToe ${SOURCES})

# (Optional) Show all warnings
# Optional: Enable verbose compiler warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(TicTacToe PRIVATE -Wall -Wextra -pedantic)
elseif (MSVC)
    target_compile_options(TicTacToe PRIVATE /W4)
endif()

# Optional: For future testing support
# enable_testing()
# add_test(NAME TicTacToeTest COMMAND TicTacToe)
