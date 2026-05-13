#include <gtest/gtest.h>
#include "Vector.hpp"

// Cross product tests
TEST(VectorOperations, CrossProductRightHandRule) {
    double aArr[3] = {1.0, 0.0, 0.0};
    double bArr[3] = {0.0, 1.0, 0.0};
    Vector<double, 3> a(aArr);
    Vector<double, 3> b(bArr);

    Vector<double, 3> c = a.crossProduct(b);

    ASSERT_DOUBLE_EQ(0.0, c[0]);
    ASSERT_DOUBLE_EQ(0.0, c[1]);
    ASSERT_DOUBLE_EQ(1.0, c[2]);
}

TEST(VectorOperations, CrossProductAnticommutative) {
    double aArr[3] = {1.0, 2.0, 3.0};
    double bArr[3] = {4.0, 5.0, 6.0};
    Vector<double, 3> a(aArr);
    Vector<double, 3> b(bArr);

    Vector<double, 3> ab = a.crossProduct(b);
    Vector<double, 3> ba = b.crossProduct(a);

    for (size_t i = 0; i < 3; ++i) {
        ASSERT_DOUBLE_EQ(ab[i], -ba[i]);
    }
}

TEST(VectorOperations, CrossProductParallelReturnsZero) {
    double aArr[3] = {2.0, -3.0, 1.0};
    double bArr[3] = {4.0, -6.0, 2.0}; // b = 2 * a
    Vector<double, 3> a(aArr);
    Vector<double, 3> b(bArr);

    Vector<double, 3> c = a.crossProduct(b);

    for (size_t i = 0; i < 3; ++i) {
        ASSERT_DOUBLE_EQ(0.0, c[i]);
    }
}

// Cosine tests
TEST(VectorOperations, CosineOfIdenticalVectorsIsOne) {
    double aArr[3] = {1.0, 2.0, 3.0};
    Vector<double, 3> a(aArr);

    double cos = a.cosine(a);
    ASSERT_DOUBLE_EQ(1.0, cos);
}

TEST(VectorOperations, CosineOfOrthogonalVectorsIsZero) {
    double aArr[3] = {1.0, 0.0, 0.0};
    double bArr[3] = {0.0, 1.0, 0.0};
    Vector<double, 3> a(aArr);
    Vector<double, 3> b(bArr);

    double cos = a.cosine(b);
    ASSERT_DOUBLE_EQ(0.0, cos);
}

TEST(VectorOperations, CosineOfOppositeVectorsIsMinusOne) {
    double aArr[3] = {1.0, -2.0, 0.5};
    double bArr[3] = {-1.0, 2.0, -0.5};
    Vector<double, 3> a(aArr);
    Vector<double, 3> b(bArr);

    double cos = a.cosine(b);
    ASSERT_DOUBLE_EQ(-1.0, cos);
}

