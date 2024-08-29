cmake_minimum_required(VERSION 3.10)

project(the-interpreter-book)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(main src/main.cpp)

add_executable(tests tests/lexer_test.cpp src/lexer.cpp src/token.cpp)

target_compile_features(main PRIVATE cxx_std_20)

target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)

target_link_libraries(tests GTest::gtest_main)

target_include_directories(tests PUBLIC src)

enable_testing()

add_test(NAME the-interpreter-book-tests COMMAND tests)
