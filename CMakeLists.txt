cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 23)
add_compile_options(-Wall -Wextra -Werror)
add_link_options(-Wl,-rpath=/home/beroux/apps/gcc-16.1.0/lib64)

project(matrix)

add_library(matrix STATIC)
target_sources(matrix PUBLIC src/Complex/Complex.cpp)

target_include_directories(matrix PUBLIC include src)

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
        tests/Vector/BasicOperations.cpp
        tests/Vector/LinearCombination.cpp
        tests/Vector/DotProduct.cpp
        tests/Vector/Norms.cpp
        tests/Vector/Cosine.cpp
        tests/Vector/CrossProduct.cpp
        tests/Matrix/BasicOperations.cpp
        tests/Matrix/Multiply.cpp
        tests/Matrix/Trace.cpp
        tests/Matrix/Transpose.cpp
        tests/Matrix/RowEchelon.cpp
        tests/Matrix/Determinant.cpp
        tests/Matrix/Inverse.cpp
        tests/Matrix/Rank.cpp
        tests/lerp.cpp
)

target_link_libraries(
        matrix_tests
        GTest::gtest_main
        matrix
)

include(GoogleTest)
gtest_discover_tests(matrix_tests)

add_executable(
        demo
        demo/main.cpp
)

target_link_libraries(
        demo
        matrix
)
