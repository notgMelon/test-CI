cmake_minimum_required(VERSION 3.14)
project(calculator_test)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(include)

add_library(calculator STATIC src/calculator.cpp)

add_executable(calculator_demo demo.cpp)
target_link_libraries(calculator_demo calculator)

set(DOCTEST_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/test")
if(NOT EXISTS "${DOCTEST_INCLUDE_DIR}/doctest.h")
    message(WARNING "doctest.h not found at ${DOCTEST_INCLUDE_DIR}, downloading...")
    file(DOWNLOAD 
        "https://raw.githubusercontent.com/doctest/doctest/v2.4.11/doctest/doctest.h"
        "${DOCTEST_INCLUDE_DIR}/doctest.h"
    )
endif()

enable_testing()

add_executable(calculator_test test/calculator_test.cpp)
target_include_directories(calculator_test PRIVATE 
    "${DOCTEST_INCLUDE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(calculator_test calculator)

add_test(NAME calculator_test COMMAND calculator_test)
