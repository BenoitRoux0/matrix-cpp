#include "VectorTest.tpp"

TEST_F(VectorTest, Norm1) {
	ASSERT_EQ(v0.norm1(), 0);
	ASSERT_EQ(v1.norm1(), 3);
	ASSERT_EQ(v2.norm1(), 15);
	ASSERT_EQ(v3.norm1(), 40);
	ASSERT_EQ(v4.norm1(), 7);
	ASSERT_EQ(v5.norm1(), 10);
}

TEST_F(VectorTest, Norm) {
	EXPECT_NEAR(v0.norm(), 0, 1e-9);
	EXPECT_NEAR(v1.norm(), sqrt(3), 1e-9);
	EXPECT_NEAR(v2.norm(), sqrt(55), 1e-9);
	EXPECT_NEAR(v3.norm(), sqrt(330), 1e-9);
	EXPECT_NEAR(v4.norm(), sqrt(29), 1e-9);
	EXPECT_NEAR(v5.norm(), sqrt(58), 1e-9);
}

TEST_F(VectorTest, NormInf) {
	ASSERT_EQ(v0.normInf(), 0);
	ASSERT_EQ(v1.normInf(), 1);
	ASSERT_EQ(v2.normInf(), 5);
	ASSERT_EQ(v3.normInf(), 10);
	ASSERT_EQ(v4.normInf(), 5);
	ASSERT_EQ(v5.normInf(), 7);
}
