#ifndef VECTOR_ADD_TPP
#define VECTOR_ADD_TPP
#include <ranges>

namespace stackixx::mat {
	template <typename T, std::size_t N>
	Vector<T, N> Vector<T, N>::operator+(const Vector& rhs) const requires(Addable<T>) {
		Vector v(*this);

		for (auto [lVal, rVal]: std::views::zip(v, rhs)) {
			lVal += rVal;
		}

		return v;
	}

	template <typename T, std::size_t N>
	Vector<T, N>& Vector<T, N>::operator+=(const Vector& rhs) requires(Addable<T>) {
		for (auto [lVal, rVal]: std::views::zip(*this, rhs)) {
			lVal += rVal;
		}

		return *this;
	}

	template <typename T, std::size_t N>
	Vector<T, N>& Vector<T, N>::addScalar(const Vector& other, const T& scalar) {
		for (auto [lVal, rVal]: std::views::zip(*this, other)) {
			lVal = std::fma(scalar, rVal, lVal);
		}

		return *this;
	}

	template <typename T, std::size_t N>
	Vector<T, N> Vector<T, N>::addScalar(const Vector& other, const T& scalar) const {
		Vector v(*this);

		for (auto [lVal, rVal]: std::views::zip(v, other)) {
			lVal = std::fma(scalar, rVal, lVal);
		}

		return v;
	}
}

#endif // VECTOR_ADD_TPP
