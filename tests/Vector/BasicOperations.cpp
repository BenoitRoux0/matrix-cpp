#include "VectorTest.tpp"

TEST_F(VectorTest, BasicSum) {
	ASSERT_EQ(v0 + v1, v1);

	stackixx::mat::Vector < double, 2 > exp = {9, -2};

	ASSERT_EQ(v4 + v5, exp);

	stackixx::mat::Vector<double, 2> u;
	stackixx::mat::Vector<double, 2> v;

	u = {0, 0};
	v = {0, 0};

	ASSERT_TRUE((u + v).equal({0, 0}));

	u = {1, 0};
	v = {0, 1};

	ASSERT_TRUE((u + v).equal({1, 1}));

	u = {1, 1};
	v = {1, 1};

	ASSERT_TRUE((u + v).equal({2, 2}));

	u = {21, 21};
	v = {21, 21};

	ASSERT_TRUE((u + v).equal({42, 42}));

	u = {-21, 21};
	v = {21, -21};

	ASSERT_TRUE((u + v).equal({0, 0}));

	ASSERT_TRUE((vA + vB).equal({9, 9, 9, 9, 9, 9, 9, 9, 9, 9}));
}

TEST_F(VectorTest, AffectSum) {
	stackixx::mat::Vector < double, 2 > dst = v5;
	stackixx::mat::Vector < double, 2 > exp = {9, -2};

	dst += v4;

	ASSERT_EQ(dst, exp);
	ASSERT_NE(dst, v5);
}

TEST_F(VectorTest, SumCommutative) {
	ASSERT_EQ(v0 + v1, v1 + v0);
	ASSERT_EQ(v2 + v3, v3 + v2);
	ASSERT_EQ(v4 + v5, v5 + v4);
}

TEST_F(VectorTest, BasicSubtraction) {
	ASSERT_EQ(v1 - v0, v1);

	stackixx::mat::Vector < double, 2 > exp = {-5, -8};

	ASSERT_EQ(v4 - v5, exp);

	stackixx::mat::Vector<double, 2> u;
	stackixx::mat::Vector<double, 2> v;

	u = {0, 0};
	v = {0, 0};

	ASSERT_TRUE((u - v).equal({0, 0}));

	u = {1, 0};
	v = {0, 1};

	ASSERT_TRUE((u - v).equal({1, -1}));

	u = {1, 1};
	v = {1, 1};

	ASSERT_TRUE((u - v).equal({0, 0}));

	u = {21, 21};
	v = {21, 21};

	ASSERT_TRUE((u - v).equal({0, 0}));

	u = {-21, 21};
	v = {21, -21};

	ASSERT_TRUE((u - v).equal({-42, 42}));

	ASSERT_TRUE((vA - vB).equal({-9, -7, -5, -3, -1, 1, 3, 5, 7, 9}));
}

TEST_F(VectorTest, AffectSubtraction) {
	stackixx::mat::Vector < double, 2 > dst = v5;
	stackixx::mat::Vector < double, 2 > exp = {5, 8};

	dst -= v4;

	ASSERT_EQ(dst, exp);
	ASSERT_NE(dst, v5);
}

TEST_F(VectorTest, BasicScale) {
	stackixx::mat::Vector < double, 5 > exp = {3, 6, 9, 12, 15};

	ASSERT_EQ(v2 * 3, exp);

	exp = {5, 10, 15, 20, 25};

	ASSERT_EQ(5. * v2, exp);

	ASSERT_TRUE((stackixx::mat::Vector<double, 2>{0, 0} * 1).equal({0, 0}));
	ASSERT_TRUE((stackixx::mat::Vector<double, 2>{1, 0} * 1).equal({1, 0}));
	ASSERT_TRUE((stackixx::mat::Vector<double, 2>{1, 1} * 2).equal({2, 2}));
	ASSERT_TRUE((stackixx::mat::Vector<double, 2>{21, 21} * 2).equal({42, 42}));
	ASSERT_TRUE((stackixx::mat::Vector<double, 2>{42, 42} * 0.5).equal({21, 21}));
}

TEST_F(VectorTest, ScaleCommutative) {
	ASSERT_EQ(v2 * 3, 3. * v2);
	ASSERT_EQ(v2 * -8, -8. * v2);
	ASSERT_EQ(v2 * (1. / 2), (1. / 2) * v2);
	ASSERT_EQ(v2 * 3.5, 3.5 * v2);
	ASSERT_EQ(v2 * 3 * 9, 9. * 3. * v2);
}
