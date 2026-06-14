#include "MatrixTest.tpp"

TEST_F(MatrixTest, BasicMult) {
	Matrix<double, 2> m;
	Vector<double, 2> v;

	v = {4, 2};
	m = {
			1, 1,
			1, 1
	};
	ASSERT_TRUE((m * v).equal({6, 6}));

	v = {2, 1};
	m = {
			2, 0,
			0, 2
	};
	ASSERT_TRUE((m * v).equal({4, 2}));

	v = {4, 2};
	m = {
			.5, 0,
			0, .5
	};
	ASSERT_TRUE((m * v).equal({2, 1}));
}
