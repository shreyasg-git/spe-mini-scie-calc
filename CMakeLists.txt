cmake_minimum_required(VERSION 3.15)
project(calculator)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)

# Core Library
add_library(calc_core src/calculator.cpp)

# Main Executable
add_executable(calculator src/main.cpp)
target_link_libraries(calculator PRIVATE calc_core ${CURSES_LIBRARIES})
target_include_directories(calculator PRIVATE ${CURSES_INCLUDE_DIR} src)

# Testing
enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(calc_test tests/test_calculator.cpp)
target_link_libraries(calc_test PRIVATE calc_core gtest_main)
target_include_directories(calc_test PRIVATE src)

include(GoogleTest)
gtest_discover_tests(calc_test)