cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include header directory
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")
add_executable(TicTacToe ${SOURCES})

# Enable warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(TicTacToe PRIVATE -Wall -Wextra -pedantic)
elseif (MSVC)
    target_compile_options(TicTacToe PRIVATE /W4)
endif()

# ---------------------------------------
# ✅ GoogleTest Setup using FetchContent
# ---------------------------------------
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # For MSVC
FetchContent_MakeAvailable(googletest)

enable_testing()

# Test sources
file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(TicTacToeTests ${TEST_SOURCES})

target_link_libraries(TicTacToeTests
    gtest
    gtest_main
    pthread  # needed for Linux
)

add_test(NAME TicTacToeTests COMMAND TicTacToeTests)
