#include <gtest/gtest.h>
#include "Vector.hpp"

// ============================================================================
// DOT PRODUCT TESTS
// ============================================================================

TEST(VectorDot, BasicInt) {
    int a[3] = {1, 2, 3};
    int b[3] = {4, 5, 6};
    Vector<int, 3> va(a);
    Vector<int, 3> vb(b);

    const int& result = va.dot(vb);
    ASSERT_EQ(32, result); // 1*4 + 2*5 + 3*6 = 32
}

TEST(VectorDot, Orthogonal) {
    int a[3] = {1, 0, 0};
    int b[3] = {0, 1, 0};
    Vector<int, 3> va(a);
    Vector<int, 3> vb(b);

    const int& result = va.dot(vb);
    ASSERT_EQ(0, result);
}

TEST(VectorDot, Float) {
    float a[2] = {1.5f, 2.0f};
    float b[2] = {2.0f, -1.0f};
    Vector<float, 2> va(a);
    Vector<float, 2> vb(b);

    const float& result = va.dot(vb);
    ASSERT_FLOAT_EQ(1.0f, result); // 1.5*2 + 2*(-1) = 1
}

