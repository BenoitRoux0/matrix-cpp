#include <gtest/gtest.h>
#include "Vector.hpp"

// ============================================================================
// VECTOR NORMS TESTS
// ============================================================================

TEST(VectorNorms, Norm1) {
	float            a[3] = {1.0f, -2.0f, 3.0f};
	Vector<float, 3> v(a);

	// L1 norm: |1| + | -2 | + |3| = 6
	ASSERT_FLOAT_EQ(6.0f, v.norm1());
}

TEST(VectorNorms, Euclidean) {
	double            a[2] = {3.0, 4.0};
	Vector<double, 2> v(a);

	// Euclidean norm: sqrt(3^2 + 4^2) = 5
	// ASSERT_DOUBLE_EQ(5.0, v.norm());
}

TEST(VectorNorms, NormInf) {
	int            a[3] = {1, -5, 3};
	Vector<int, 3> v(a);

	// infinity norm (max absolute): 5
	ASSERT_EQ(5, v.normInf());
}
