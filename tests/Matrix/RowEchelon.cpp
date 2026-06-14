#include "MatrixTest.tpp"

TEST_F(MatrixTest, BasicRowEchelon) {
	Matrix<double, 2> m;

	m = {0, 0, 0, 0};
	ASSERT_TRUE(m.rowEchelon().equal({0, 0, 0, 0}));

	m = {1, 0, 0, 1};
	ASSERT_TRUE(m.rowEchelon().equal({1, 0, 0, 1}));

	m = {4, 2, 2, 1};
	ASSERT_TRUE(m.rowEchelon().equal({1, 0.5, 0, 0}));

	m = {-7, 2, 4, 8};
	ASSERT_TRUE(m.rowEchelon().equal({1, 0, 0, 1}));

	m = {1, 2, 4, 8};
	ASSERT_TRUE(m.rowEchelon().equal({1, 2, 0, 0}));
}