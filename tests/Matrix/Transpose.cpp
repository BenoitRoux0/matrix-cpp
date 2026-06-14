#include "MatrixTest.tpp"

TEST_F(MatrixTest, BasicTranspose) {
	Matrix<double, 2> m2;

	m2 = {
		0, 0,
		0, 0
	};
	ASSERT_TRUE(m2.transpose().equal({0, 0, 0, 0}));

	m2 = {
		1, 0,
		0, 1
	};
	ASSERT_TRUE(m2.transpose().equal({1, 0, 0, 1}));

	m2 = {
		1, 2,
		3, 4
	};
	ASSERT_TRUE(m2.transpose().equal({1, 3, 2, 4}));

	m2 = {
		0, 0,
		0, 0
	};
	ASSERT_TRUE(m2.transpose().equal({0, 0, 0, 0}));

	Matrix<double, 3> m3;

	m3 = Matrix<double, 3>::identity();
	ASSERT_TRUE(m3.transpose().equal({1, 0, 0, 0, 1, 0, 0, 0, 1}));

	Matrix<double, 3, 2> m32 = {
		1, 2,
		3, 4,
		5, 6
	};

	ASSERT_TRUE(m32.transpose().equal({1, 3, 5, 2, 4, 6}));
}
