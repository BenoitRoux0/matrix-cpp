#ifndef VECTOR_TEST_TPP
#define VECTOR_TEST_TPP

#include "Matrix.hpp"
#include "gtest/gtest.h"

using stackixx::mat::Matrix;
using stackixx::mat::Vector;

class MatrixTest: public testing::Test {
protected:
	Matrix<double, 2, 3> m0{
			1., 2., 3.,
			4., 5., 6.
	};
	Matrix<double, 2, 3> m1{
			2., -9., 4.,
			-11., 7., 8.
	};

	Matrix<double, 2> mA{
		0, 0,
		0, 0
	};

	Matrix<double, 2> mB{
		1, 0,
		0, 1
	};

	Matrix<double, 2> mC{
		1, 1,
		1, 1
	};

	Matrix<double, 2> mD{
		21, 21,
		21, 21
	};

	Matrix<double, 2> mE{
		1, 2,
		3, 4
	};

};

#endif // VECTOR_TEST_TPP
