#ifndef LINEAR_COMBINATION_TPP
#define LINEAR_COMBINATION_TPP

#include <ranges>

namespace stackixx {
	template <typename T, size_t N>
	mat::Vector<T, N> linearCombination(std::initializer_list<mat::Vector<T, N>> vectors, std::initializer_list<T> coefs) requires
		(
			Multiplicable<T> && Addable<T>) {
		mat::Vector<T, N> v{};

		for (const auto& [vec, scalar]: std::views::zip(vectors, coefs)) {
			v.addScalar(vec, scalar);
		}

		return v;
	}

	template <typename T, size_t N, std::ranges::forward_range Rv>
	mat::Vector<T, N> linearCombination(Rv&& vectors, std::initializer_list<T> coefs) requires(
		Multiplicable<T> && Addable<T> && std::is_same_v<std::ranges::range_value_t<Rv>, mat::Vector<T, N>>) {
		mat::Vector<T, N> v{};

		for (const auto& [vec, scalar]: std::views::zip(vectors, coefs)) {
			v.addScalar(vec, scalar);
		}

		return v;
	}

	template <typename T, size_t N, std::ranges::forward_range Rs>
	mat::Vector<T, N> linearCombination(std::initializer_list<mat::Vector<T, N>> vectors, Rs coefs) requires(
		Multiplicable<T> && Addable<T> && std::is_same_v<std::ranges::range_value_t<Rs>, T>) {
		mat::Vector<T, N> v{};

		for (const auto& [vec, scalar]: std::views::zip(vectors, coefs)) {
			v.addScalar(vec, scalar);
		}

		return v;
	}

	template <typename T, size_t N, std::ranges::forward_range Rv, std::ranges::forward_range Rs>
	mat::Vector<T, N> linearCombination(Rv&& vectors, Rs&& coefs) requires(
		Multiplicable<T> &&
		Addable<T> &&
		std::is_same_v<std::ranges::range_value_t<Rv>, mat::Vector<T, N>> &&
		std::is_same_v<std::ranges::range_value_t<Rs>, T>) {
		mat::Vector<T, N> v{};

		for (const auto& [vec, scalar]: std::views::zip(vectors, coefs)) {
			v.addScalar(vec, scalar);
		}

		return v;
	}
}

#endif // LINEAR_COMBINATION_TPP
