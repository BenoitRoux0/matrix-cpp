#include <gtest/gtest.h>
#include <print>
#include "Matrix.hpp"

TEST(MatrixInverse, InverseOf2x2MatchesExpectedEntries) {
	double aArr[2][2] = {
			{4.0, 7.0},
			{2.0, 6.0}
	};
	Matrix<double, 2, 2> a(aArr);

	Matrix<double, 2, 2> inv = a.inverse();

	ASSERT_NEAR(0.6, inv[0][0], 1e-9);
	ASSERT_NEAR(-0.7, inv[0][1], 1e-9);
	ASSERT_NEAR(-0.2, inv[1][0], 1e-9);
	ASSERT_NEAR(0.4, inv[1][1], 1e-9);
}

TEST(MatrixInverse, InverseMultiplicationYieldsIdentity2x2) {
	double aArr[2][2] = {
			{4.0, 7.0},
			{2.0, 6.0}
	};
	Matrix<double, 2, 2> a(aArr);

	Matrix<double, 2, 2> prod = a * a.inverse();
	Matrix<double, 2, 2> id = Matrix<double, 2, 2>::identity();

	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			ASSERT_NEAR(id[i][j], prod[i][j], 1e-9);
		}
	}
}

TEST(MatrixInverse, InverseOfIdentityIsIdentity3x3) {
	Matrix<double, 3, 3> id = Matrix<double, 3, 3>::identity();
	Matrix<double, 3, 3> inv = id.inverse();

	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			ASSERT_DOUBLE_EQ(id[i][j], inv[i][j]);
		}
	}
}

TEST(MatrixInverse, InverseMultiplicationYieldsIdentity3x3) {
	double aArr[3][3] = {
			{3.0, 0.0, 2.0},
			{2.0, 0.0, -2.0},
			{0.0, 1.0, 1.0}
	};
	Matrix<double, 3, 3> a(aArr);

	Matrix<double, 3, 3> prod = a * a.inverse();
	Matrix<double, 3, 3> id = Matrix<double, 3, 3>::identity();

	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			ASSERT_NEAR(id[i][j], prod[i][j], 1e-9);
		}
	}
}
