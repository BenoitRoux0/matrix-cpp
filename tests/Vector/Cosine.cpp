#include "VectorTest.tpp"

TEST_F(VectorTest, BasicCosine) {
	EXPECT_NEAR(v2.cosine(v3).value(), 13 * sqrt(6) / 33, 1e-9);
	EXPECT_NEAR(v4.cosine(v5).value(), -1 * sqrt(2) / 58, 1e-9);

	Vector<double, 2> u;
	Vector<double, 2> v;

	u = {1, 0};
	v = {0, 1};
	EXPECT_NEAR(u.cosine(v).value(), 0., 1e-9);

	u = {8, 7};
	v = {3, 2};
	EXPECT_NEAR(u.cosine(v).value(), 0.9914542955425437, 1e-9);

	u = {1, 1};
	v = {1, 1};
	EXPECT_NEAR(u.cosine(v).value(), 1., 1e-9);

	u = {4, 2};
	v = {1, 1};
	EXPECT_NEAR(u.cosine(v).value(), 0.9486832980505138, 1e-9);

	u = {-7, 3};
	v = {6, 4};
	EXPECT_NEAR(u.cosine(v).value(), -0.5462677805469223, 1e-9);
}

TEST_F(VectorTest, ZeroVectorCosine) {
	ASSERT_EQ(v0.cosine(v1).has_value(), false);
}

TEST_F(VectorTest, CosineCommutative) {
	EXPECT_NEAR(v2.cosine(v3).value(), v3.cosine(v2).value(), 1e-9);
	EXPECT_NEAR(v4.cosine(v5).value(), v5.cosine(v4).value(), 1e-9);
}
