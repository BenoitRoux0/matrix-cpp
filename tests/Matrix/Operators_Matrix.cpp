#include <gtest/gtest.h>
#include "Matrix.hpp"

// ============================================================================
// MATRIX ADDITION TESTS
// ============================================================================

TEST(MatrixOperators, AdditionBasic) {
	int a[2][3] = {
			{1, 2, 3},
			{4, 5, 6}
	};
	int b[2][3] = {
			{1, 1, 1},
			{2, 2, 2}
	};
	Matrix<int, 2, 3> ma(a);
	Matrix<int, 2, 3> mb(b);

	Matrix<int, 2, 3> result = ma + mb;

	ASSERT_EQ(2, result[0][0]);
	ASSERT_EQ(3, result[0][1]);
	ASSERT_EQ(4, result[0][2]);
	ASSERT_EQ(6, result[1][0]);
	ASSERT_EQ(7, result[1][1]);
	ASSERT_EQ(8, result[1][2]);
}

TEST(MatrixOperators, AdditionWithZero) {
	int a[2][2] = {
			{1, 2},
			{3, 4}
	};
	int zero[2][2] = {
			{0, 0},
			{0, 0}
	};
	Matrix<int, 2, 2> ma(a);
	Matrix<int, 2, 2> mzero(zero);

	Matrix<int, 2, 2> result = ma + mzero;

	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			ASSERT_EQ(a[i][j], result[i][j]);
		}
	}
}

TEST(MatrixOperators, AdditionNegativeNumbers) {
	int a[2][2] = {
			{5, -3},
			{2, 8}
	};
	int b[2][2] = {
			{-2, 3},
			{-4, 1}
	};
	::Matrix<int, 2, 2> ma(a);
	::Matrix<int, 2, 2> mb(b);

	::Matrix<int, 2, 2> result = ma + mb;

	ASSERT_EQ(3, result[0][0]);
	ASSERT_EQ(0, result[0][1]);
	ASSERT_EQ(-2, result[1][0]);
	ASSERT_EQ(9, result[1][1]);
}

TEST(MatrixOperators, AdditionFloating) {
	double a[2][2] = {
			{1.5, 2.5},
			{3.5, 4.5}
	};
	double b[2][2] = {
			{0.5, 0.5},
			{0.5, 0.5}
	};
	::Matrix<double, 2, 2> ma(a);
	::Matrix<double, 2, 2> mb(b);

	::Matrix<double, 2, 2> result = ma + mb;

	ASSERT_DOUBLE_EQ(2.0, result[0][0]);
	ASSERT_DOUBLE_EQ(3.0, result[0][1]);
	ASSERT_DOUBLE_EQ(4.0, result[1][0]);
	ASSERT_DOUBLE_EQ(5.0, result[1][1]);
}

TEST(MatrixOperators, AdditionCommutative) {
	int a[2][2] = {
			{1, 2},
			{3, 4}
	};
	int b[2][2] = {
			{5, 6},
			{7, 8}
	};
	::Matrix<int, 2, 2> ma(a);
	::Matrix<int, 2, 2> mb(b);

	::Matrix<int, 2, 2> result1 = ma + mb;
	::Matrix<int, 2, 2> result2 = mb + ma;

	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			ASSERT_EQ(result1[i][j], result2[i][j]);
		}
	}
}

TEST(MatrixOperators, AdditionLargeMatrix) {
	int a[5][5];
	int b[5][5];
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			a[i][j] = i + j;
			b[i][j] = i * j;
		}
	}
	::Matrix<int, 5, 5> ma(a);
	::Matrix<int, 5, 5> mb(b);

	::Matrix<int, 5, 5> result = ma + mb;

	for (size_t i = 0; i < 5; ++i) {
		for (size_t j = 0; j < 5; ++j) {
			ASSERT_EQ(a[i][j] + b[i][j], result[i][j]);
		}
	}
}

TEST(MatrixOperators, AdditionRectangularMatrix) {
	int a[3][4] = {
			{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12}
	};
	int b[3][4] = {
			{1, 1, 1, 1},
			{1, 1, 1, 1},
			{1, 1, 1, 1}
	};
	::Matrix<int, 3, 4> ma(a);
	::Matrix<int, 3, 4> mb(b);

	::Matrix<int, 3, 4> result = ma + mb;

	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			ASSERT_EQ(a[i][j] + b[i][j], result[i][j]);
		}
	}
}

// ============================================================================
// MATRIX SUBTRACTION TESTS
// ============================================================================

TEST(MatrixOperators, SubtractionBasic) {
	int a[2][3] = {
			{5, 7, 9},
			{11, 13, 15}
	};
	int b[2][3] = {
			{1, 2, 3},
			{4, 5, 6}
	};
	::Matrix<int, 2, 3> ma(a);
	::Matrix<int, 2, 3> mb(b);

	::Matrix<int, 2, 3> result = ma - mb;

	ASSERT_EQ(4, result[0][0]);
	ASSERT_EQ(5, result[0][1]);
	ASSERT_EQ(6, result[0][2]);
	ASSERT_EQ(7, result[1][0]);
	ASSERT_EQ(8, result[1][1]);
	ASSERT_EQ(9, result[1][2]);
}

TEST(MatrixOperators, SubtractionFromZero) {
	int a[2][2] = {
			{1, 2},
			{3, 4}
	};
	int zero[2][2] = {
			{0, 0},
			{0, 0}
	};
	::Matrix<int, 2, 2> ma(a);
	::Matrix<int, 2, 2> mzero(zero);

	::Matrix<int, 2, 2> result = mzero - ma;

	ASSERT_EQ(-1, result[0][0]);
	ASSERT_EQ(-2, result[0][1]);
	ASSERT_EQ(-3, result[1][0]);
	ASSERT_EQ(-4, result[1][1]);
}

TEST(MatrixOperators, SubtractionSameMatrix) {
	int a[2][2] = {
			{5, 7},
			{9, 11}
	};
	::Matrix<int, 2, 2> ma(a);

	::Matrix<int, 2, 2> result = ma - ma;

	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			ASSERT_EQ(0, result[i][j]);
		}
	}
}

TEST(MatrixOperators, SubtractionNegativeNumbers) {
	int a[2][2] = {
			{-5, -3},
			{2, 8}
	};
	int b[2][2] = {
			{-2, 3},
			{-4, 1}
	};
	::Matrix<int, 2, 2> ma(a);
	::Matrix<int, 2, 2> mb(b);

	::Matrix<int, 2, 2> result = ma - mb;

	ASSERT_EQ(-3, result[0][0]);
	ASSERT_EQ(-6, result[0][1]);
	ASSERT_EQ(6, result[1][0]);
	ASSERT_EQ(7, result[1][1]);
}

TEST(MatrixOperators, SubtractionFloating) {
	double a[2][2] = {
			{3.5, 2.5},
			{1.5, 0.5}
	};
	double b[2][2] = {
			{0.5, 0.5},
			{0.5, 0.5}
	};
	::Matrix<double, 2, 2> ma(a);
	::Matrix<double, 2, 2> mb(b);

	::Matrix<double, 2, 2> result = ma - mb;

	ASSERT_DOUBLE_EQ(3.0, result[0][0]);
	ASSERT_DOUBLE_EQ(2.0, result[0][1]);
	ASSERT_DOUBLE_EQ(1.0, result[1][0]);
	ASSERT_DOUBLE_EQ(0.0, result[1][1]);
}

TEST(MatrixOperators, SubtractionNotCommutative) {
	int a[2][2] = {
			{1, 2},
			{3, 4}
	};
	int b[2][2] = {
			{5, 6},
			{7, 8}
	};
	::Matrix<int, 2, 2> ma(a);
	::Matrix<int, 2, 2> mb(b);

	::Matrix<int, 2, 2> result1 = ma - mb;
	::Matrix<int, 2, 2> result2 = mb - ma;

	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			ASSERT_EQ(result1[i][j], -result2[i][j]);
		}
	}
}

TEST(MatrixOperators, SubtractionLargeMatrix) {
	int a[4][4];
	int b[4][4];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			a[i][j] = 20 + i * 4 + j;
			b[i][j] = i * 4 + j;
		}
	}
	::Matrix<int, 4, 4> ma(a);
	::Matrix<int, 4, 4> mb(b);

	::Matrix<int, 4, 4> result = ma - mb;

	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			ASSERT_EQ(20, result[i][j]);
		}
	}
}

// ============================================================================
// MATRIX SCALAR MULTIPLICATION TESTS
// ============================================================================

TEST(MatrixOperators, ScalarMultiplicationBasic) {
	int a[2][2] = {
			{1, 2},
			{3, 4}
	};
	::Matrix<int, 2, 2> ma(a);

	::Matrix<int, 2, 2> result = ma * 2;

	ASSERT_EQ(2, result[0][0]);
	ASSERT_EQ(4, result[0][1]);
	ASSERT_EQ(6, result[1][0]);
	ASSERT_EQ(8, result[1][1]);
}

TEST(MatrixOperators, ScalarMultiplicationByZero) {
	int a[2][2] = {
			{1, 2},
			{3, 4}
	};
	::Matrix<int, 2, 2> ma(a);

	::Matrix<int, 2, 2> result = ma * 0;

	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			ASSERT_EQ(0, result[i][j]);
		}
	}
}

TEST(MatrixOperators, ScalarMultiplicationByOne) {
	int a[2][2] = {
			{1, 2},
			{3, 4}
	};
	::Matrix<int, 2, 2> ma(a);

	::Matrix<int, 2, 2> result = ma * 1;

	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			ASSERT_EQ(a[i][j], result[i][j]);
		}
	}
}

TEST(MatrixOperators, ScalarMultiplicationNegative) {
	int a[2][2] = {
			{1, -2},
			{3, -4}
	};
	::Matrix<int, 2, 2> ma(a);

	::Matrix<int, 2, 2> result = ma * (-2);

	ASSERT_EQ(-2, result[0][0]);
	ASSERT_EQ(4, result[0][1]);
	ASSERT_EQ(-6, result[1][0]);
	ASSERT_EQ(8, result[1][1]);
}

TEST(MatrixOperators, ScalarMultiplicationFloating) {
	double a[2][2] = {
			{1.0, 2.0},
			{3.0, 4.0}
	};
	::Matrix<double, 2, 2> ma(a);

	::Matrix<double, 2, 2> result = ma * 2.5;

	ASSERT_DOUBLE_EQ(2.5, result[0][0]);
	ASSERT_DOUBLE_EQ(5.0, result[0][1]);
	ASSERT_DOUBLE_EQ(7.5, result[1][0]);
	ASSERT_DOUBLE_EQ(10.0, result[1][1]);
}

TEST(MatrixOperators, ScalarMultiplicationFractional) {
	double a[2][2] = {
			{2.0, 4.0},
			{6.0, 8.0}
	};
	::Matrix<double, 2, 2> ma(a);

	::Matrix<double, 2, 2> result = ma * 0.5;

	ASSERT_DOUBLE_EQ(1.0, result[0][0]);
	ASSERT_DOUBLE_EQ(2.0, result[0][1]);
	ASSERT_DOUBLE_EQ(3.0, result[1][0]);
	ASSERT_DOUBLE_EQ(4.0, result[1][1]);
}

TEST(MatrixOperators, ScalarMultiplicationLargeMatrix) {
	int a[5][5];
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			a[i][j] = i * 5 + j + 1;
		}
	}
	::Matrix<int, 5, 5> ma(a);

	::Matrix<int, 5, 5> result = ma * 3;

	for (size_t i = 0; i < 5; ++i) {
		for (size_t j = 0; j < 5; ++j) {
			ASSERT_EQ(a[i][j] * 3, result[i][j]);
		}
	}
}

TEST(MatrixOperators, ScalarMultiplicationRectangularMatrix) {
	int a[3][4] = {
			{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12}
	};
	::Matrix<int, 3, 4> ma(a);
	int                 scalar = 2;

	::Matrix<int, 3, 4> result = ma * scalar;

	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			ASSERT_EQ(a[i][j] * scalar, result[i][j]);
		}
	}
}

// ============================================================================
// COMBINED OPERATOR TESTS
// ============================================================================

TEST(MatrixOperators, CombinedAdditionAndMultiplication) {
	int a[2][2] = {
			{1, 2},
			{3, 4}
	};
	int b[2][2] = {
			{2, 3},
			{4, 5}
	};
	::Matrix<int, 2, 2> ma(a);
	::Matrix<int, 2, 2> mb(b);

	// (ma + mb) * 2
	::Matrix<int, 2, 2> result = (ma + mb) * 2;

	ASSERT_EQ(6, result[0][0]); // (1+2)*2 = 6
	ASSERT_EQ(10, result[0][1]); // (2+3)*2 = 10
	ASSERT_EQ(14, result[1][0]); // (3+4)*2 = 14
	ASSERT_EQ(18, result[1][1]); // (4+5)*2 = 18
}

TEST(MatrixOperators, CombinedSubtractionAndMultiplication) {
	int a[2][2] = {
			{5, 6},
			{7, 8}
	};
	int b[2][2] = {
			{1, 2},
			{3, 4}
	};
	::Matrix<int, 2, 2> ma(a);
	::Matrix<int, 2, 2> mb(b);

	// (ma - mb) * 2
	::Matrix<int, 2, 2> result = (ma - mb) * 2;

	ASSERT_EQ(8, result[0][0]); // (5-1)*2 = 8
	ASSERT_EQ(8, result[0][1]); // (6-2)*2 = 8
	ASSERT_EQ(8, result[1][0]); // (7-3)*2 = 8
	ASSERT_EQ(8, result[1][1]); // (8-4)*2 = 8
}

TEST(MatrixOperators, CombinedAdditionAndSubtraction) {
	int a[2][2] = {
			{1, 2},
			{3, 4}
	};
	int b[2][2] = {
			{2, 3},
			{4, 5}
	};
	int c[2][2] = {
			{1, 1},
			{1, 1}
	};
	::Matrix<int, 2, 2> ma(a);
	::Matrix<int, 2, 2> mb(b);
	::Matrix<int, 2, 2> mc(c);

	// (ma + mb) - mc
	::Matrix<int, 2, 2> result = (ma + mb) - mc;

	ASSERT_EQ(2, result[0][0]); // (1+2)-1 = 2
	ASSERT_EQ(4, result[0][1]); // (2+3)-1 = 4
	ASSERT_EQ(6, result[1][0]); // (3+4)-1 = 6
	ASSERT_EQ(8, result[1][1]); // (4+5)-1 = 8
}

TEST(MatrixOperators, MultipleMultiplications) {
	int a[2][2] = {
			{1, 2},
			{3, 4}
	};
	::Matrix<int, 2, 2> ma(a);

	// ma * 2 * 3
	::Matrix<int, 2, 2> result = (ma * 2) * 3;

	ASSERT_EQ(6, result[0][0]); // 1*2*3 = 6
	ASSERT_EQ(12, result[0][1]); // 2*2*3 = 12
	ASSERT_EQ(18, result[1][0]); // 3*2*3 = 18
	ASSERT_EQ(24, result[1][1]); // 4*2*3 = 24
}

TEST(MatrixOperators, OriginalMatrixUnchangedAfterAddition) {
	int a[2][2] = {
			{1, 2},
			{3, 4}
	};
	int b[2][2] = {
			{5, 6},
			{7, 8}
	};
	::Matrix<int, 2, 2> ma(a);
	::Matrix<int, 2, 2> mb(b);

	(void) (ma + mb);

	ASSERT_EQ(1, ma[0][0]);
	ASSERT_EQ(2, ma[0][1]);
	ASSERT_EQ(3, ma[1][0]);
	ASSERT_EQ(4, ma[1][1]);
	ASSERT_EQ(5, mb[0][0]);
	ASSERT_EQ(6, mb[0][1]);
	ASSERT_EQ(7, mb[1][0]);
	ASSERT_EQ(8, mb[1][1]);
}

TEST(MatrixOperators, OriginalMatrixUnchangedAfterSubtraction) {
	int a[2][2] = {
			{5, 7},
			{9, 11}
	};
	int b[2][2] = {
			{1, 2},
			{3, 4}
	};
	::Matrix<int, 2, 2> ma(a);
	::Matrix<int, 2, 2> mb(b);

	(void) (ma - mb);

	ASSERT_EQ(5, ma[0][0]);
	ASSERT_EQ(7, ma[0][1]);
	ASSERT_EQ(9, ma[1][0]);
	ASSERT_EQ(11, ma[1][1]);
	ASSERT_EQ(1, mb[0][0]);
	ASSERT_EQ(2, mb[0][1]);
	ASSERT_EQ(3, mb[1][0]);
	ASSERT_EQ(4, mb[1][1]);
}

TEST(MatrixOperators, OriginalMatrixUnchangedAfterMultiplication) {
	int a[2][2] = {
			{1, 2},
			{3, 4}
	};
	::Matrix<int, 2, 2> ma(a);

	(void) (ma * 5);

	ASSERT_EQ(1, ma[0][0]);
	ASSERT_EQ(2, ma[0][1]);
	ASSERT_EQ(3, ma[1][0]);
	ASSERT_EQ(4, ma[1][1]);
}

TEST(MatrixOperators, AssociativityOfAddition) {
	int a[2][2] = {
			{1, 2},
			{3, 4}
	};
	int b[2][2] = {
			{2, 3},
			{4, 5}
	};
	int c[2][2] = {
			{1, 1},
			{1, 1}
	};
	::Matrix<int, 2, 2> ma(a);
	::Matrix<int, 2, 2> mb(b);
	::Matrix<int, 2, 2> mc(c);

	// (ma + mb) + mc == ma + (mb + mc)
	::Matrix<int, 2, 2> result1 = (ma + mb) + mc;
	::Matrix<int, 2, 2> result2 = ma + (mb + mc);

	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			ASSERT_EQ(result1[i][j], result2[i][j]);
		}
	}
}

TEST(MatrixOperators, DistributivityOfScalarMultiplication) {
	int a[2][2] = {
			{1, 2},
			{3, 4}
	};
	int b[2][2] = {
			{2, 3},
			{4, 5}
	};
	::Matrix<int, 2, 2> ma(a);
	::Matrix<int, 2, 2> mb(b);

	// k*(A + B) == k*A + k*B
	int                 k = 3;
	::Matrix<int, 2, 2> result1 = (ma + mb) * k;
	::Matrix<int, 2, 2> result2 = (ma * k) + (mb * k);

	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			ASSERT_EQ(result1[i][j], result2[i][j]);
		}
	}
}

// ============================================================================
// MATRIX COMPARISON TESTS
// ============================================================================

TEST(MatrixOperators, ComparisonEqualMatrices) {
	int a[2][3] = {
			{1, 2, 3},
			{4, 5, 6}
	};
	int b[2][3] = {
			{1, 2, 3},
			{4, 5, 6}
	};
	::Matrix<int, 2, 3> ma(a);
	::Matrix<int, 2, 3> mb(b);
	(void) (ma * 5);
	ASSERT_TRUE(ma == mb);
}

TEST(MatrixOperators, ComparisonDifferentMatrices) {
	int a[2][3] = {
			{1, 2, 3},
			{4, 5, 6}
	};
	int b[2][3] = {
			{1, 2, 3},
			{4, 0, 6}
	};
	::Matrix<int, 2, 3> ma(a);
	::Matrix<int, 2, 3> mb(b);

	ASSERT_FALSE(ma == mb);
}
