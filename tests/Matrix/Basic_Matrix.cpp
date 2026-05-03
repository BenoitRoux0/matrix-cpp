#include <gtest/gtest.h>
#include "Matrix.hpp"

TEST(MatrixTests, BasicMatrixInit) {
	int	source[3][5] = {
		{8, 6, 4, 2, 5},
		{8, 6, 4, 2, 5},
		{8, 6, 4, 2, 5}
	};
	Matrix<int, 3, 5>	m(source);

	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 5; ++j) {
			ASSERT_EQ(source[i][j], m[i][j]);
		}
	}
}