#include "MatrixTest.tpp"

TEST_F(MatrixTest, BasicSum) {
	Matrix<double, 2, 3> exp = {
			3., -7., 7.,
			-7., 12., 14.
	};

	ASSERT_EQ(m0 + m1, exp);

	Matrix<double, 2> m;
	Matrix<double, 2> n;

	m = {
		0, 0,
		0, 0
	};

	n = {
		0, 0,
		0, 0
	};

	ASSERT_TRUE((m + n).equal({
		0, 0,
		0, 0
	}));

	m = {
		1, 0,
		0, 1
	};

	n = {
		0, 0,
		0, 0
	};

	ASSERT_TRUE((m + n).equal({
		1, 0,
		0, 1
	}));

	m = {
		1, 1,
		1, 1
	};

	n = {
		1, 1,
		1, 1
	};

	ASSERT_TRUE((m + n).equal({
		2, 2,
		2, 2
	}));

	m = {
		21, 21,
		21, 21
	};

	n = {
		21, 21,
		21, 21
	};

	ASSERT_TRUE((m + n).equal({
		42, 42,
		42, 42
	}));
}

TEST_F(MatrixTest, AffectSum) {
	Matrix<double, 2, 3> exp = {
			3., -7., 7.,
			-7., 12., 14.
	};

	auto dest = m0;

	dest += m1;

	ASSERT_EQ(dest, exp);
}

TEST_F(MatrixTest, SumCommutative) {
	ASSERT_EQ(m0 + m1, m1 + m0);
}

TEST_F(MatrixTest, BasicSubstraction) {
	Matrix<double, 2, 3> exp = {
			-1., 11., -1.,
			15., -2., -2.
	};

	ASSERT_EQ(m0 - m1, exp);

	Matrix<double, 2> m;
	Matrix<double, 2> n;

	m = {
		0, 0,
		0, 0
	};

	n = {
		0, 0,
		0, 0
	};

	ASSERT_TRUE((m - n).equal({
		0, 0,
		0, 0
	}));

	m = {
		1, 0,
		0, 1
	};

	n = {
		0, 0,
		0, 0
	};

	ASSERT_TRUE((m - n).equal({
		1, 0,
		0, 1
	}));

	m = {
		1, 1,
		1, 1
	};

	n = {
		1, 1,
		1, 1
	};

	ASSERT_TRUE((m - n).equal({
		0, 0,
		0, 0
	}));

	m = {
		21, 21,
		21, 21
	};

	n = {
		21, 21,
		21, 21
	};

	ASSERT_TRUE((m - n).equal({
		0, 0,
		0, 0
	}));
}

TEST_F(MatrixTest, AffectSubstraction) {
	Matrix<double, 2, 3> exp = {
			-1., 11., -1.,
			15., -2., -2.
	};

	auto dest = m0;

	dest -= m1;

	ASSERT_EQ(dest, exp);
}

TEST_F(MatrixTest, BasicScale) {
	auto exp = {
			-42., -84., -126.,
			-168., -210., -252.
	};

	ASSERT_EQ(m0 * -42., exp);

	ASSERT_TRUE((stackixx::mat::Matrix<double, 2>{{0, 0}, {0, 0}} * 0).equal({{0, 0}, {0, 0}}));
	ASSERT_TRUE((stackixx::mat::Matrix<double, 2>{{1, 0}, {0, 1}} * 1).equal({{1, 0}, {0, 1}}));
	ASSERT_TRUE((stackixx::mat::Matrix<double, 2>{{1, 2}, {3, 4}} * 2).equal({{2, 4}, {6, 8}}));
	ASSERT_TRUE((stackixx::mat::Matrix<double, 2>{{21, 21}, {21, 21}} * .5).equal({{10.5, 10.5}, {10.5, 10.5}}));
}

TEST_F(MatrixTest, ScaleLoop) {
	auto dest = m0 * -42.;

	for (double i = -42.; i <= 42.; i += 1.) {
		ASSERT_EQ(m0 * i, dest);
		dest += m0;
	}
}
