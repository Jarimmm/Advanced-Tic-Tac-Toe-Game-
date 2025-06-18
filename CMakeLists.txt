cmake_minimum_required(VERSION 3.10)

project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_executable(TicTacToe ${SOURCES})

# Enable warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(TicTacToe PRIVATE -Wall -Wextra -pedantic)
elseif (MSVC)
    target_compile_options(TicTacToe PRIVATE /W4)
endif()

# Google Test setup
enable_testing()
find_package(GTest REQUIRED)
file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(TicTacToeTests ${TEST_SOURCES})
target_link_libraries(TicTacToeTests GTest::GTest GTest::Main pthread)
add_test(NAME TicTacToeTests COMMAND TicTacToeTests)
