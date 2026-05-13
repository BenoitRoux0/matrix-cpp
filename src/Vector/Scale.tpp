#ifndef VECTOR_SCALE_TPP
#define VECTOR_SCALE_TPP
#include <ranges>

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator*(const T &scalar) const {
	Vector	v(*this);

	for (auto& val: v) {
		val *= scalar;
	}

	return v;
}

template<typename T, std::size_t N>
Vector<T, N> operator*(const T &scalar, const Vector<T, N> &vec) {
	return vec * scalar;
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator*=(const T &scalar) {
	for (auto& val: *this) {
		val *= scalar;
	}

	return *this;
}

#endif // VECTOR_SCALE_TPP
