#include <gtest/gtest.h>
#include "Vector.hpp"
#include <cmath>

// ============================================================================
// VECTOR ADDITION TESTS
// ============================================================================

TEST(VectorOperators, AdditionBasic) {
	int a[3] = {1, 2, 3};
	int b[3] = {4, 5, 6};
	Vector<int, 3> va(a);
	Vector<int, 3> vb(b);

	Vector<int, 3> result = va + vb;

	ASSERT_EQ(5, result[0]);
	ASSERT_EQ(7, result[1]);
	ASSERT_EQ(9, result[2]);
}

TEST(VectorOperators, AdditionWithZero) {
	int a[4] = {1, 2, 3, 4};
	int zero[4] = {0, 0, 0, 0};
	Vector<int, 4> va(a);
	Vector<int, 4> vzero(zero);

	Vector<int, 4> result = va + vzero;

	for (size_t i = 0; i < 4; ++i) {
		ASSERT_EQ(a[i], result[i]);
	}
}

TEST(VectorOperators, AdditionNegativeNumbers) {
	int a[3] = {5, -3, 2};
	int b[3] = {-2, 3, -4};
	Vector<int, 3> va(a);
	Vector<int, 3> vb(b);

	Vector<int, 3> result = va + vb;

	ASSERT_EQ(3, result[0]);
	ASSERT_EQ(0, result[1]);
	ASSERT_EQ(-2, result[2]);
}

TEST(VectorOperators, AdditionFloating) {
	double a[3] = {1.5, 2.5, 3.5};
	double b[3] = {0.5, 0.5, 0.5};
	Vector<double, 3> va(a);
	Vector<double, 3> vb(b);

	Vector<double, 3> result = va + vb;

	ASSERT_DOUBLE_EQ(2.0, result[0]);
	ASSERT_DOUBLE_EQ(3.0, result[1]);
	ASSERT_DOUBLE_EQ(4.0, result[2]);
}

TEST(VectorOperators, AdditionCommutative) {
	int a[3] = {1, 2, 3};
	int b[3] = {4, 5, 6};
	Vector<int, 3> va(a);
	Vector<int, 3> vb(b);

	Vector<int, 3> result1 = va + vb;
	Vector<int, 3> result2 = vb + va;

	for (size_t i = 0; i < 3; ++i) {
		ASSERT_EQ(result1[i], result2[i]);
	}
}

TEST(VectorOperators, AdditionLargeVector) {
	int size = 100;
	int a[100], b[100];
	for (int i = 0; i < size; ++i) {
		a[i] = i;
		b[i] = i * 2;
	}
	Vector<int, 100> va(a);
	Vector<int, 100> vb(b);

	Vector<int, 100> result = va + vb;

	for (size_t i = 0; i < 100; ++i) {
		ASSERT_EQ(a[i] + b[i], result[i]);
	}
}

// ============================================================================
// VECTOR SUBTRACTION TESTS
// ============================================================================

TEST(VectorOperators, SubtractionBasic) {
	int a[3] = {5, 7, 9};
	int b[3] = {1, 2, 3};
	Vector<int, 3> va(a);
	Vector<int, 3> vb(b);

	Vector<int, 3> result = va - vb;

	ASSERT_EQ(4, result[0]);
	ASSERT_EQ(5, result[1]);
	ASSERT_EQ(6, result[2]);
}

TEST(VectorOperators, SubtractionFromZero) {
	int a[3] = {1, 2, 3};
	int zero[3] = {0, 0, 0};
	Vector<int, 3> va(a);
	Vector<int, 3> vzero(zero);

	Vector<int, 3> result = vzero - va;

	ASSERT_EQ(-1, result[0]);
	ASSERT_EQ(-2, result[1]);
	ASSERT_EQ(-3, result[2]);
}

TEST(VectorOperators, SubtractionSameVector) {
	int a[3] = {5, 7, 9};
	Vector<int, 3> va(a);

	Vector<int, 3> result = va - va;

	ASSERT_EQ(0, result[0]);
	ASSERT_EQ(0, result[1]);
	ASSERT_EQ(0, result[2]);
}

TEST(VectorOperators, SubtractionNegativeNumbers) {
	int a[3] = {-5, -3, 2};
	int b[3] = {-2, 3, -4};
	Vector<int, 3> va(a);
	Vector<int, 3> vb(b);

	Vector<int, 3> result = va - vb;

	ASSERT_EQ(-3, result[0]);
	ASSERT_EQ(-6, result[1]);
	ASSERT_EQ(6, result[2]);
}

TEST(VectorOperators, SubtractionFloating) {
	double a[3] = {3.5, 2.5, 1.5};
	double b[3] = {0.5, 0.5, 0.5};
	Vector<double, 3> va(a);
	Vector<double, 3> vb(b);

	Vector<double, 3> result = va - vb;

	ASSERT_DOUBLE_EQ(3.0, result[0]);
	ASSERT_DOUBLE_EQ(2.0, result[1]);
	ASSERT_DOUBLE_EQ(1.0, result[2]);
}

TEST(VectorOperators, SubtractionNotCommutative) {
	int a[3] = {1, 2, 3};
	int b[3] = {4, 5, 6};
	Vector<int, 3> va(a);
	Vector<int, 3> vb(b);

	Vector<int, 3> result1 = va - vb;
	Vector<int, 3> result2 = vb - va;

	for (size_t i = 0; i < 3; ++i) {
		ASSERT_EQ(result1[i], -result2[i]);
	}
}

// ============================================================================
// VECTOR SCALAR MULTIPLICATION TESTS
// ============================================================================

TEST(VectorOperators, ScalarMultiplicationBasic) {
	int a[3] = {1, 2, 3};
	Vector<int, 3> va(a);

	Vector<int, 3> result = va * 2;

	ASSERT_EQ(2, result[0]);
	ASSERT_EQ(4, result[1]);
	ASSERT_EQ(6, result[2]);
}

TEST(VectorOperators, ScalarMultiplicationByZero) {
	int a[3] = {1, 2, 3};
	Vector<int, 3> va(a);

	Vector<int, 3> result = va * 0;

	ASSERT_EQ(0, result[0]);
	ASSERT_EQ(0, result[1]);
	ASSERT_EQ(0, result[2]);
}

TEST(VectorOperators, ScalarMultiplicationByOne) {
	int a[3] = {1, 2, 3};
	Vector<int, 3> va(a);

	Vector<int, 3> result = va * 1;

	for (size_t i = 0; i < 3; ++i) {
		ASSERT_EQ(a[i], result[i]);
	}
}

TEST(VectorOperators, ScalarMultiplicationNegative) {
	int a[3] = {1, -2, 3};
	Vector<int, 3> va(a);

	Vector<int, 3> result = va * (-3);

	ASSERT_EQ(-3, result[0]);
	ASSERT_EQ(6, result[1]);
	ASSERT_EQ(-9, result[2]);
}

TEST(VectorOperators, ScalarMultiplicationFloating) {
	double a[3] = {1.0, 2.0, 3.0};
	Vector<double, 3> va(a);

	Vector<double, 3> result = va * 2.5;

	ASSERT_DOUBLE_EQ(2.5, result[0]);
	ASSERT_DOUBLE_EQ(5.0, result[1]);
	ASSERT_DOUBLE_EQ(7.5, result[2]);
}

TEST(VectorOperators, ScalarMultiplicationFractional) {
	double a[3] = {2.0, 4.0, 6.0};
	Vector<double, 3> va(a);

	Vector<double, 3> result = va * 0.5;

	ASSERT_DOUBLE_EQ(1.0, result[0]);
	ASSERT_DOUBLE_EQ(2.0, result[1]);
	ASSERT_DOUBLE_EQ(3.0, result[2]);
}

TEST(VectorOperators, ScalarMultiplicationLargeVector) {
	int size = 100;
	int a[100];
	for (int i = 0; i < size; ++i) {
		a[i] = i;
	}
	Vector<int, 100> va(a);
	int scalar = 3;

	Vector<int, 100> result = va * scalar;

	for (size_t i = 0; i < 100; ++i) {
		ASSERT_EQ(a[i] * scalar, result[i]);
	}
}

// ============================================================================
// LINEAR COMBINATION TESTS
// ============================================================================

TEST(VectorOperators, LinearCombinationBasic) {
	int a[2] = {1, 0};
	int b[2] = {0, 1};
	int coefs[2] = {2, 3};

	Vector<int, 2> va(a);
	Vector<int, 2> vb(b);
	Vector<int, 2> vectors[2] = {va, vb};

	Vector<int, 2> result = Vector<int, 2>::linearCombination<2>(vectors, coefs);

	ASSERT_EQ(2, result[0]);
	ASSERT_EQ(3, result[1]);
}

TEST(VectorOperators, LinearCombinationZeroCoefficients) {
	int a[3] = {1, 2, 3};
	int b[3] = {4, 5, 6};
	int coefs[2] = {0, 0};

	Vector<int, 3> va(a);
	Vector<int, 3> vb(b);
	Vector<int, 3> vectors[2] = {va, vb};

	Vector<int, 3> result = Vector<int, 3>::linearCombination<2>(vectors, coefs);

	ASSERT_EQ(0, result[0]);
	ASSERT_EQ(0, result[1]);
	ASSERT_EQ(0, result[2]);
}

TEST(VectorOperators, LinearCombinationSingleVector) {
	int a[3] = {1, 2, 3};
	int coefs[1] = {5};

	Vector<int, 3> va(a);
	Vector<int, 3> vectors[1] = {va};

	Vector<int, 3> result = Vector<int, 3>::linearCombination<1>(vectors, coefs);

	ASSERT_EQ(5, result[0]);
	ASSERT_EQ(10, result[1]);
	ASSERT_EQ(15, result[2]);
}

TEST(VectorOperators, LinearCombinationMultipleVectors) {
	int a[2] = {1, 0};
	int b[2] = {0, 1};
	int c[2] = {1, 1};
	int coefs[3] = {1, 2, 3};

	Vector<int, 2> va(a);
	Vector<int, 2> vb(b);
	Vector<int, 2> vc(c);
	Vector<int, 2> vectors[3] = {va, vb, vc};

	Vector<int, 2> result = Vector<int, 2>::linearCombination<3>(vectors, coefs);

	ASSERT_EQ(4, result[0]);    // 1*1 + 0*2 + 1*3 = 4
	ASSERT_EQ(5, result[1]);    // 0*1 + 1*2 + 1*3 = 5
}

TEST(VectorOperators, LinearCombinationNegativeCoefficients) {
	int a[3] = {1, 2, 3};
	int b[3] = {2, 4, 6};
	int coefs[2] = {3, -1};

	Vector<int, 3> va(a);
	Vector<int, 3> vb(b);
	Vector<int, 3> vectors[2] = {va, vb};

	Vector<int, 3> result = Vector<int, 3>::linearCombination<2>(vectors, coefs);

	ASSERT_EQ(1, result[0]);    // 3*1 + (-1)*2 = 1
	ASSERT_EQ(2, result[1]);    // 3*2 + (-1)*4 = 2
	ASSERT_EQ(3, result[2]);    // 3*3 + (-1)*6 = 3
}

TEST(VectorOperators, LinearCombinationFloatingPoint) {
	double a[2] = {1.0, 0.0};
	double b[2] = {0.0, 1.0};
	double coefs[2] = {2.5, 3.5};

	Vector<double, 2> va(a);
	Vector<double, 2> vb(b);
	Vector<double, 2> vectors[2] = {va, vb};

	Vector<double, 2> result = Vector<double, 2>::linearCombination<2>(vectors, coefs);

	ASSERT_DOUBLE_EQ(2.5, result[0]);
	ASSERT_DOUBLE_EQ(3.5, result[1]);
}

TEST(VectorOperators, LinearCombinationFourVectors) {
	int a[4] = {1, 0, 0, 0};
	int b[4] = {0, 1, 0, 0};
	int c[4] = {0, 0, 1, 0};
	int d[4] = {0, 0, 0, 1};
	int coefs[4] = {2, 3, 4, 5};

	Vector<int, 4> va(a);
	Vector<int, 4> vb(b);
	Vector<int, 4> vc(c);
	Vector<int, 4> vd(d);
	Vector<int, 4> vectors[4] = {va, vb, vc, vd};

	Vector<int, 4> result = Vector<int, 4>::linearCombination<4>(vectors, coefs);

	ASSERT_EQ(2, result[0]);
	ASSERT_EQ(3, result[1]);
	ASSERT_EQ(4, result[2]);
	ASSERT_EQ(5, result[3]);
}

TEST(VectorOperators, LinearCombinationLargeVectors) {
	int arr1[10], arr2[10];
	for (int i = 0; i < 10; ++i) {
		arr1[i] = 1;
		arr2[i] = 2;
	}
	int coefs[2] = {2, 3};

	Vector<int, 10> v1(arr1);
	Vector<int, 10> v2(arr2);
	Vector<int, 10> vectors[2] = {v1, v2};

	Vector<int, 10> result = Vector<int, 10>::linearCombination<2>(vectors, coefs);

	for (size_t i = 0; i < 10; ++i) {
		ASSERT_EQ(8, result[i]);    // 2*1 + 3*2 = 8
	}
}

// ============================================================================
// COMBINED OPERATOR TESTS
// ============================================================================

TEST(VectorOperators, CombinedAdditionAndMultiplication) {
	int a[3] = {1, 2, 3};
	int b[3] = {2, 3, 4};
	Vector<int, 3> va(a);
	Vector<int, 3> vb(b);

	// (va + vb) * 2
	Vector<int, 3> result = (va + vb) * 2;

	ASSERT_EQ(6, result[0]);    // (1+2)*2 = 6
	ASSERT_EQ(10, result[1]);   // (2+3)*2 = 10
	ASSERT_EQ(14, result[2]);   // (3+4)*2 = 14
}

TEST(VectorOperators, CombinedSubtractionAndMultiplication) {
	int a[3] = {5, 6, 7};
	int b[3] = {1, 2, 3};
	Vector<int, 3> va(a);
	Vector<int, 3> vb(b);

	// (va - vb) * 2
	Vector<int, 3> result = (va - vb) * 2;

	ASSERT_EQ(8, result[0]);    // (5-1)*2 = 8
	ASSERT_EQ(8, result[1]);    // (6-2)*2 = 8
	ASSERT_EQ(8, result[2]);    // (7-3)*2 = 8
}

TEST(VectorOperators, CombinedAdditionAndSubtraction) {
	int a[3] = {1, 2, 3};
	int b[3] = {2, 3, 4};
	int c[3] = {1, 1, 1};
	Vector<int, 3> va(a);
	Vector<int, 3> vb(b);
	Vector<int, 3> vc(c);

	// (va + vb) - vc
	Vector<int, 3> result = (va + vb) - vc;

	ASSERT_EQ(2, result[0]);    // (1+2)-1 = 2
	ASSERT_EQ(4, result[1]);    // (2+3)-1 = 4
	ASSERT_EQ(6, result[2]);    // (3+4)-1 = 6
}

TEST(VectorOperators, OriginalVectorUnchangedAfterAddition) {
	int a[3] = {1, 2, 3};
	int b[3] = {4, 5, 6};
	Vector<int, 3> va(a);
	Vector<int, 3> vb(b);

	[[maybe_unused]] Vector<int, 3> result = va + vb;

	// Original vectors should not be modified
	ASSERT_EQ(1, va[0]);
	ASSERT_EQ(2, va[1]);
	ASSERT_EQ(3, va[2]);
	ASSERT_EQ(4, vb[0]);
	ASSERT_EQ(5, vb[1]);
	ASSERT_EQ(6, vb[2]);
}

TEST(VectorOperators, OriginalVectorUnchangedAfterSubtraction) {
	int a[3] = {5, 7, 9};
	int b[3] = {1, 2, 3};
	Vector<int, 3> va(a);
	Vector<int, 3> vb(b);

	[[maybe_unused]] Vector<int, 3> result = va - vb;

	// Original vectors should not be modified
	ASSERT_EQ(5, va[0]);
	ASSERT_EQ(7, va[1]);
	ASSERT_EQ(9, va[2]);
	ASSERT_EQ(1, vb[0]);
	ASSERT_EQ(2, vb[1]);
	ASSERT_EQ(3, vb[2]);
}

TEST(VectorOperators, OriginalVectorUnchangedAfterMultiplication) {
	int a[3] = {1, 2, 3};
	Vector<int, 3> va(a);

	[[maybe_unused]] Vector<int, 3> result = va * 5;

	// Original vector should not be modified
	ASSERT_EQ(1, va[0]);
	ASSERT_EQ(2, va[1]);
	ASSERT_EQ(3, va[2]);
}

// ============================================================================
// VECTOR COMPARISON TESTS
// ============================================================================

TEST(VectorOperators, ComparisonEqualVectors) {
	int a[4] = {1, 2, 3, 4};
	int b[4] = {1, 2, 3, 4};
	Vector<int, 4> va(a);
	Vector<int, 4> vb(b);

	ASSERT_TRUE(va == vb);
}

TEST(VectorOperators, ComparisonDifferentVectors) {
	int a[4] = {1, 2, 3, 4};
	int b[4] = {1, 2, 0, 4};
	Vector<int, 4> va(a);
	Vector<int, 4> vb(b);

	ASSERT_FALSE(va == vb);
}

