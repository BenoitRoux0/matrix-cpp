#include "VectorTest.tpp"



TEST_F(VectorTest, BasicDotProduct) {
	ASSERT_EQ(v4.dot(v5), -1);
	ASSERT_EQ(v2.dot(v3), 130);

	Vector<double, 2> u;
	Vector<double, 2> v;

	u = {0, 0};
	v = {0, 0};
	ASSERT_EQ(u.dot(v), 0);

	u = {1, 0};
	v = {0, 0};
	ASSERT_EQ(u.dot(v), 0);

	u = {1, 0};
	v = {1, 0};
	ASSERT_EQ(u.dot(v), 1);

	u = {1, 0};
	v = {0, 1};
	ASSERT_EQ(u.dot(v), 0);

	u = {1, 1};
	v = {1, 1};
	ASSERT_EQ(u.dot(v), 2);

	u = {4, 2};
	v = {2, 1};
	ASSERT_EQ(u.dot(v), 10);
}

TEST_F(VectorTest, NullDotProduct) {
	ASSERT_EQ(v0.dot(v1), 0);

	stackixx::mat::Vector<double, 2> ortho = {v4[1], -v4[0]};

	ASSERT_EQ(v4.dot(ortho), 0);
}

TEST_F(VectorTest, DotProductCommutative) {
	ASSERT_EQ(v4.dot(v5), v5.dot(v4));
	ASSERT_EQ(v2.dot(v3), v3.dot(v2));
}
