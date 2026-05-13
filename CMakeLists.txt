cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 23)
add_compile_options(-Wall -Wextra -Werror)
add_compile_options(-fconcepts-diagnostics-depth=5)
add_link_options(-Wl,-rpath=/home/beroux/apps/gcc-16.1.0/lib64)

project(matrix)

add_library(matrix INTERFACE src/Matrix/Matrix.tpp src/Vector/Vector.tpp)

target_include_directories(matrix INTERFACE include src)

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
        tests/Misc/Lerp.cpp
        tests/Matrix/Basic_Matrix.cpp
        tests/Matrix/Operators_Matrix.cpp
        tests/Matrix/Trace_Transpose_RowEchelon.cpp
        tests/Matrix/Inverse.cpp
        tests/Vector/Basic_Vector.cpp
        tests/Vector/Operators_Vector.cpp
        tests/Vector/CrossCosine.cpp
        tests/Vector/Dot.cpp
        tests/Vector/Norms.cpp
)

target_link_libraries(
        matrix_tests
        GTest::gtest_main
        matrix
)

include(GoogleTest)
gtest_discover_tests(matrix_tests)
