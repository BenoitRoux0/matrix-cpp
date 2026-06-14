#ifndef VECTOR_TEST_TPP
#define VECTOR_TEST_TPP

#include "Vector.hpp"
#include "gtest/gtest.h"

using stackixx::mat::Vector;

class VectorTest: public testing::Test {
protected:
	Vector<double, 3> v0{0, 0, 0};
	Vector<double, 3> v1{1, 1, 1};
	Vector<double, 5> v2{1, 2, 3, 4, 5};
	Vector<double, 5> v3{6, 7, 8, 9, 10};
	Vector<double, 2> v4{2, -5};
	Vector<double, 2> v5{7, 3};
	Vector<double, 3> v6{2, -5, 8};
	Vector<double, 3> v7{7, 3, -9};

	Vector<double, 10> vA{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	Vector<double, 10> vB{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
};

#endif // VECTOR_TEST_TPP
