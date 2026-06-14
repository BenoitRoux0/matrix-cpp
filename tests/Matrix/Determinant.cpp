#include "MatrixTest.tpp"

TEST_F(MatrixTest, BasicDet) {
	Matrix<double, 2> m;

	m = {0, 0, 0, 0};
	ASSERT_EQ(m.determinant(), 0.);

	m = {1, 0, 0, 1};
	ASSERT_EQ(m.determinant(), 1.);

	m = {2, 0, 0, 2};
	ASSERT_EQ(m.determinant(), 4.);

	m = {1, 1, 1, 1};
	ASSERT_EQ(m.determinant(), 0.);

	m = {0, 1, 1, 0};
	ASSERT_EQ(m.determinant(), -1.);

	m = {1, 2, 3, 4};
	ASSERT_EQ(m.determinant(), -2.);

	m = {-7, 5, 4, 6};
	ASSERT_EQ(m.determinant(), -62.);

	ASSERT_EQ((Matrix<double, 3>::identity().determinant()), 1);
}