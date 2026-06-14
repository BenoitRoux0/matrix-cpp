#include "Misc.hpp"
#include "gtest/gtest.h"

using stackixx::mat::Vector;

TEST(LerpTests, BasicLerp) {
	ASSERT_EQ(stackixx::lerp(0., 1., 0.), 0.);
	ASSERT_EQ(stackixx::lerp(0., 1., 1.), 1.);
	ASSERT_EQ(stackixx::lerp(0., 42., 0.5), 21.);
	ASSERT_EQ(stackixx::lerp(-42., 42., 0.5), 0.);
	ASSERT_EQ(stackixx::lerp(Vector<double, 2>{-42, 42}, Vector<double, 2>{42, -42}, 0.5), (Vector<double, 2>{0, -0}));
}