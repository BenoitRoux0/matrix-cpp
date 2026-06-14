#include "VectorTest.tpp"
#include "Misc.hpp"

TEST_F(VectorTest, BasicLinearCombination) {
	std::vector<stackixx::mat::Vector<double, 3>> vecs{
			{1., 0., 0.},
			{0., 1., 0.},
			{0., 0., 1.}
	};

	std::vector scalars{5., -7., 0.5};

	auto comb3 = stackixx::linearCombination<double, 3>(
			vecs,
			scalars);

	stackixx::mat::Vector<double, 3> exp3 = {5., -7., 0.5};

	ASSERT_EQ(comb3, exp3);

	comb3 = stackixx::linearCombination<double, 3>(
			std::initializer_list<stackixx::mat::Vector<double, 3>>{
					{1., 2., 3.},
					{0., 10., -100.},
			},
			std::array{10., -2.});

	exp3 = {10., 0., 230.};

	ASSERT_EQ(comb3, exp3);

	stackixx::mat::Vector<double, 2> comb2 = stackixx::linearCombination<double, 2>(
			{
					{1., 2.},
			},
			{-1.});

	stackixx::mat::Vector<double, 2> exp2 = {-1., -2.};

	ASSERT_EQ(comb2, exp2);

	auto comb1 = stackixx::linearCombination<double, 1>(
			{
					{-42.},
					{-42.},
					{-42.},
			},
			{-1., 1, 0}
			);

	stackixx::mat::Vector<double, 1> exp1 = {0.};

	ASSERT_EQ(comb1, exp1);
}
