cmake_minimum_required(VERSION 3.10)

project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include headers
include_directories(include)

# All source files
file(GLOB SOURCES "src/*.cpp")

# Create a library from your source code
add_library(tictactoe_lib ${SOURCES})
target_include_directories(tictactoe_lib PUBLIC include)

# Main executable
add_executable(TicTacToe src/main.cpp)
target_link_libraries(TicTacToe PRIVATE tictactoe_lib)

# Enable warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(TicTacToe PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(tictactoe_lib PRIVATE -Wall -Wextra -pedantic)
elseif (MSVC)
    target_compile_options(TicTacToe PRIVATE /W4)
    target_compile_options(tictactoe_lib PRIVATE /W4)
endif()

# Google Test setup
enable_testing()
find_package(GTest REQUIRED)

# Test executable with test source files
file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(TicTacToeTests ${TEST_SOURCES})
target_link_libraries(TicTacToeTests PRIVATE tictactoe_lib GTest::GTest GTest::Main pthread)

# Register tests
add_test(NAME TicTacToeTests COMMAND TicTacToeTests)
