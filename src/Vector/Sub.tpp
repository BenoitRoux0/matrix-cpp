#ifndef VECTOR_SUB_TPP
#define VECTOR_SUB_TPP
#include <ranges>

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator-(const Vector& rhs) const requires(Subtractable<T>) {
	Vector v(*this);

	for (auto [lVal, rVal]: std::views::zip(v, rhs)) {
		lVal -= rVal;
	}

	return v;
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator-=(const Vector& rhs) requires(Subtractable<T>) {
	for (auto [lVal, rVal]: std::views::zip(*this, rhs)) {
		lVal -= rVal;
	}

	return *this;
}

#endif // VECTOR_SUB_TPP
