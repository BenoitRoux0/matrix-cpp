#include "MatrixTest.tpp"

TEST_F(MatrixTest, BasicInverse) {
	Matrix<double, 2> m;

	m = {1, 0, 0, 1};
	ASSERT_TRUE(m.inverse().has_value());
	ASSERT_TRUE(m.inverse()->equal({1, 0, 0, 1}));

	m = {2, 0, 0, 2};
	ASSERT_TRUE(m.inverse().has_value());
	ASSERT_TRUE(m.inverse()->equal({0.5, 0, 0, 0.5}));

	m = {0.5, 0, 0, 0.5};
	ASSERT_TRUE(m.inverse().has_value());
	ASSERT_TRUE(m.inverse()->equal({2, 0, 0, 2}));

	m = {0, 1, 1, 0};
	ASSERT_TRUE(m.inverse().has_value());
	ASSERT_TRUE(m.inverse()->equal({0, 1, 1, 0}));

	m = {1, 2, 3, 4};
	ASSERT_TRUE(m.inverse().has_value());
	ASSERT_TRUE(m.inverse()->equal({-2, 1, 1.5, -0.5}));

	ASSERT_TRUE((Matrix<double, 3>::identity()).inverse().has_value());
	ASSERT_TRUE((Matrix<double, 3>::identity()).inverse()->equal({1, 0, 0, 0, 1, 0, 0, 0, 1}));
}