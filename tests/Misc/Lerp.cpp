#include <gtest/gtest.h>
#include "Misc.hpp"
#include "Vector.hpp"

TEST(LerpTests, ReturnsFirstValueAtZero) {
	ASSERT_FLOAT_EQ(1.5f, lerp(1.5f, 4.5f, 0.0f));
}

TEST(LerpTests, ReturnsSecondValueAtOne) {
	ASSERT_FLOAT_EQ(4.5f, lerp(1.5f, 4.5f, 1.0f));
}

TEST(LerpTests, InterpolatesMidpoint) {
	ASSERT_FLOAT_EQ(3.0f, lerp(1.5f, 4.5f, 0.5f));
}

TEST(LerpTests, SupportsExtrapolation) {
	ASSERT_FLOAT_EQ(0.0f, lerp(1.0f, 3.0f, -0.5f));
}

TEST(LerpTests, ReturnsFirstVectorAtZero) {
	float a[3] = {1.5f, 2.5f, 3.5f};
	float b[3] = {4.5f, 5.5f, 6.5f};
	Vector<float, 3> va(a);
	Vector<float, 3> vb(b);
	Vector<float, 3> result = lerp(va, vb, 0.0f);

	for (size_t i = 0; i < 3; ++i) {
		ASSERT_FLOAT_EQ(a[i], result[i]);
	}
}

TEST(LerpTests, ReturnsSecondVectorAtOne) {
	float a[3] = {1.5f, 2.5f, 3.5f};
	float b[3] = {4.5f, 5.5f, 6.5f};
	Vector<float, 3> va(a);
	Vector<float, 3> vb(b);
	Vector<float, 3> result = lerp(va, vb, 1.0f);

	for (size_t i = 0; i < 3; ++i) {
		ASSERT_FLOAT_EQ(b[i], result[i]);
	}
}

TEST(LerpTests, InterpolatesVectorMidpoint) {
	float a[3] = {1.0f, 2.0f, 3.0f};
	float b[3] = {3.0f, 5.0f, 7.0f};
	Vector<float, 3> va(a);
	Vector<float, 3> vb(b);
	Vector<float, 3> result = lerp(va, vb, 0.5f);

	ASSERT_FLOAT_EQ(2.0f, result[0]);
	ASSERT_FLOAT_EQ(3.5f, result[1]);
	ASSERT_FLOAT_EQ(5.0f, result[2]);
}

TEST(LerpTests, SupportsVectorExtrapolation) {
	float a[3] = {1.0f, 2.0f, 3.0f};
	float b[3] = {3.0f, 5.0f, 7.0f};
	Vector<float, 3> va(a);
	Vector<float, 3> vb(b);
	Vector<float, 3> result = lerp(va, vb, -0.5f);

	ASSERT_FLOAT_EQ(0.0f, result[0]);
	ASSERT_FLOAT_EQ(0.5f, result[1]);
	ASSERT_FLOAT_EQ(1.0f, result[2]);
}

