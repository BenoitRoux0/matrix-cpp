#include "MatrixTest.tpp"

TEST_F(MatrixTest, BasicTrace) {
	Matrix<double, 2> m;

	m = {
			0, 0,
			0, 0
	};
	ASSERT_EQ(m.trace(), 0);

	m = {
			1, 0,
			0, 1
	};
	ASSERT_EQ(m.trace(), 2);

	m = {
			1, 2,
			3, 4
	};
	ASSERT_EQ(m.trace(), 5);

	m = {
			8, -7,
			4, 2
	};
	ASSERT_EQ(m.trace(), 10);

	Matrix<double, 3> m3;

	m3 = {
			1, 0, 0,
			0, 1, 0,
			0, 0, 1
	};
	ASSERT_EQ(m3.trace(), 3);

}
