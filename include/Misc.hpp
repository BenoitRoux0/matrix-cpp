#ifndef MISC_HPP
#define MISC_HPP

#include "Matrix.hpp"
#include <optional>

namespace stackixx {
	template <typename T>
	T lerp(const T& v, const T& u, float t);

	template <typename T, size_t N, std::input_iterator InputItFirstV, std::input_iterator InputItLastV, std::input_iterator InputItFirstS, std::input_iterator InputItLastS>
	mat::Vector<T, N> linearCombination(InputItFirstV vectorsFirst, InputItLastV vectorsLast, InputItFirstV scalarsFirst, InputItLastV scalarsLast) requires(Multiplicable<T> && Addable<T>);

	template <typename T, size_t N>
	mat::Vector<T, N> linearCombination(std::initializer_list<mat::Vector<T, N>> vectors, std::initializer_list<T> coefs) requires(Multiplicable<T> && Addable<T>);

	template <typename T, size_t N, std::ranges::forward_range Rv, std::ranges::forward_range Rs>
	mat::Vector<T, N> linearCombination(Rv&& vectors, Rs&& coefs) requires(Multiplicable<T> && Addable<T> && std::is_same_v<std::ranges::range_value_t<Rv>, mat::Vector<T, N>> && std::is_same_v<std::ranges::range_value_t<Rs>, T>);

	template<typename T>
	T abs(const T& x);

	std::optional<mat::Matrix<double, 4>> projection(double fov, double ratio, double near, double far);
}

#include "lerp.tpp"
#include "linearCombination.tpp"
#include "abs.tpp"

#endif // MISC_HPP
