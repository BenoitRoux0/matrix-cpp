#ifndef VECTOR_SCALE_TPP
#define VECTOR_SCALE_TPP
#include <ranges>

namespace stackixx::mat {
	template <typename T, std::size_t N>
	Vector<T, N> Vector<T, N>::operator*(const T& scalar) const requires(Multiplicable<T>) {
		Vector v(*this);

		for (auto& val: v) {
			val *= scalar;
		}

		return v;
	}

	template <typename T, std::size_t N>
	Vector<T, N> operator*(const T& scalar, const Vector<T, N>& vec) requires(Multiplicable<T>) {
		return vec * scalar;
	}

	template <typename T, std::size_t N>
	Vector<T, N>& Vector<T, N>::operator*=(const T& scalar) requires(Multiplicable<T>) {
		for (auto& val: *this) {
			val *= scalar;
		}

		return *this;
	}
}

#endif // VECTOR_SCALE_TPP
