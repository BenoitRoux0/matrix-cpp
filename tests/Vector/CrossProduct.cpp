#include "VectorTest.tpp"

TEST_F(VectorTest, BasicCrossProduct) {
	Vector < double, 3 > exp = {0., 0., 0.};
	ASSERT_EQ(v0.crossProduct(v1), exp);

	exp = {21., 74., 41.};
	ASSERT_EQ(v6.crossProduct(v7), exp);

	exp = {-13., 6., 7.};
	ASSERT_EQ(v6.crossProduct(v1), exp);

	Vector<double, 3> u;
	Vector<double, 3> v;

	u = {0, 0, 0};
	v = {0, 0, 0};
	ASSERT_TRUE(u.crossProduct(v).equal({0, 0, 0}));

	u = {1, 0, 0};
	v = {0, 0, 0};
	ASSERT_TRUE(u.crossProduct(v).equal({0, 0, 0}));

	u = {1, 0, 0};
	v = {0, 1, 0};
	ASSERT_TRUE(u.crossProduct(v).equal({0, 0, 1}));

	u = {8, 7, -4};
	v = {3, 2, 1};
	ASSERT_TRUE(u.crossProduct(v).equal({15, -20, -5}));

	u = {1, 1, 1};
	v = {0, 0, 0};
	ASSERT_TRUE(u.crossProduct(v).equal({0, 0, 0}));

	u = {1, 1, 1};
	v = {1, 1, 1};
	ASSERT_TRUE(u.crossProduct(v).equal({0, 0, 0}));
}

TEST_F(VectorTest, CrossProductAntiCommutative) {
	ASSERT_EQ(v6.crossProduct(v7), -1. * v7.crossProduct(v6));
	ASSERT_EQ(v1.crossProduct(v7), -1. * v7.crossProduct(v1));
	ASSERT_EQ(v6.crossProduct(v1), -1. * v1.crossProduct(v6));
}

TEST_F(VectorTest, SelfCrossProduct) {
	ASSERT_EQ(v1.crossProduct(v1), v0);
	ASSERT_EQ(v6.crossProduct(v6), v0);
	ASSERT_EQ(v7.crossProduct(v7), v0);
}

TEST_F(VectorTest, CrossProductDistributiveOverAddition) {
	ASSERT_EQ(v1.crossProduct(v6 + v7), v1.crossProduct(v6) + v1.crossProduct(v7));
	ASSERT_EQ(v6.crossProduct(v1 + v7), v6.crossProduct(v1) + v6.crossProduct(v7));
}

TEST_F(VectorTest, CrossProductJacobiIdentity) {
	ASSERT_EQ(
		v1.crossProduct(v6.crossProduct(v7)) +
		v6.crossProduct(v7.crossProduct(v1)) +
		v7.crossProduct(v1.crossProduct(v6)),
		v0);
}

