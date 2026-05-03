#include <gtest/gtest.h>
#include "Vector.hpp"
#include <ranges>

TEST(VectorTests, BasicVectorInit) {
	int	source[5] = {8, 6, 4, 2, 5};
	Vector<int, 5>	v(source);

	for (size_t i = 0; i < 5; ++i) {
		ASSERT_EQ(source[i], v[i]);
	}
}

TEST(VectorTests, BasicZerosVectorInit) {
	Vector<int, 5>	v;

	for (size_t i = 0; i < 5; ++i) {
		ASSERT_EQ(0, v[i]);
	}
}

TEST(VectorTests, BasicVectorIte) {
	int	source[5] = {8, 6, 4, 2, 5};
	Vector<int, 5>	v(source);
	size_t	i = 0;

	for (auto value: v) {
		ASSERT_EQ(source[i], value);
		++i;
	}

	for (auto& value: v) {
		value = 42;
	}

	for (auto value: v) {
		ASSERT_EQ(42, value);
	}
}
