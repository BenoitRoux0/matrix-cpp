#ifndef VECTOR_NORM_TPP
#define VECTOR_NORM_TPP
#include <cmath>

#include "abs.tpp"

namespace stackixx::mat {
	template <typename T, std::size_t N>
	T Vector<T, N>::norm1() const requires(Addable<T> && Absolutable<T>) {
		T norm = T();

		for (const auto& v: *this) {
			norm += stackixx::abs(v);
		}

		return norm;
	}

	template <typename T, std::size_t N>
	T Vector<T, N>::norm() const requires(Addable<T> && Multiplicable<T> && SquareRootable<T>) {
		T squaredNorm = this->dot(*this);

		if constexpr (StdSquareRootable<T>) {
			return std::pow(squaredNorm, .5);
		} else if constexpr (InnerSquareRootable<T>) {
			return squaredNorm.pow(.5);
		}
	}

	template <typename T, std::size_t N>
	T Vector<T, N>::normInf() const requires(Absolutable<T>) {
		T norm = T();

		for (const auto& v: *this) {
			if (norm < std::abs(v)) {
				norm = std::abs(v);
			}
		}

		return norm;
	}
}

#endif // VECTOR_NORM_TPP
