cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 23)

project(matrix)

add_library(matrix INTERFACE src/Matrix/Matrix.tpp src/Vector/Vector.tpp)

target_include_directories(matrix INTERFACE include src/Matrix src/Vector)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        matrix_tests
        tests/Matrix/Basic_Matrix.cpp
        tests/Vector/Basic_Vector.cpp
)

target_link_libraries(
        matrix_tests
        GTest::gtest_main
        matrix
)

include(GoogleTest)
gtest_discover_tests(matrix_tests)
