#include <gtest/gtest.h>
#include <print>
#include "Matrix.hpp"

TEST(MatrixOperations, TraceBasicSquareMatrix) {
	int a[3][3] = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9}
	};
	Matrix<int, 3, 3> m(a);

	int t = m.trace();
	ASSERT_EQ(15, t); // 1 + 5 + 9
}

TEST(MatrixOperations, TraceZeroDiagonal) {
	int a[2][2] = {
			{0, 5},
			{7, 0}
	};
	Matrix<int, 2, 2> m(a);

	int t = m.trace();
	ASSERT_EQ(0, t);
}

TEST(MatrixOperations, TransposeSwapsDimensions) {
	int a[2][3] = {
			{1, 2, 3},
			{4, 5, 6}
	};
	Matrix<int, 2, 3> m(a);

	Matrix<int, 3, 2> mt = m.transpose();

	ASSERT_EQ(1, mt[0][0]);
	ASSERT_EQ(4, mt[0][1]);
	ASSERT_EQ(2, mt[1][0]);
	ASSERT_EQ(5, mt[1][1]);
	ASSERT_EQ(3, mt[2][0]);
	ASSERT_EQ(6, mt[2][1]);
}

TEST(MatrixOperations, TransposeTwiceIsOriginal) {
	int a[2][3] = {
			{1, 2, 3},
			{4, 5, 6}
	};
	Matrix<int, 2, 3> m(a);

	Matrix<int, 2, 3> twice = m.transpose().transpose();

	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			ASSERT_EQ(m[i][j], twice[i][j]);
		}
	}
}

TEST(MatrixOperations, RowEchelonSimpleReduction) {
	double a[2][2] = {
			{1, 2},
			{3, 4}
	};
	Matrix<double, 2, 2> m(a);

	Matrix<double, 2, 2> r = m.rowEchelon();

	std::print("{}\n{}\n", m, r);

	// Expect first row unchanged (pivot 1), second row reduced by 3*first
	ASSERT_EQ(1, r[0][0]);
	ASSERT_EQ(0, r[0][1]);
	ASSERT_EQ(0, r[1][0]);
	ASSERT_EQ(1, r[1][1]);
}

TEST(MatrixOperations, RowEchelonZeroRowsRemainZero) {
	int a[2][3] = {
			{0, 0, 0},
			{0, 0, 0}
	};
	Matrix<int, 2, 3> m(a);

	Matrix<int, 2, 3> r = m.rowEchelon();

	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			ASSERT_EQ(0, r[i][j]);
		}
	}
}
