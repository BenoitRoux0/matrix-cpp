#ifndef VECTOR_NORM_TPP
#define VECTOR_NORM_TPP
#include <cmath>

template<typename T, std::size_t N>
T Vector<T, N>::norm1() const {
	T	norm = T();

	for (const auto& v: *this) {
		norm = norm + std::abs(v);
	}

	return norm;
}

template<typename T, std::size_t N>
T Vector<T, N>::norm() const {
	T	squaredNorm = T();

	for (const auto& v: *this) {
		squaredNorm = squaredNorm + v * v;
	}

	return std::sqrt(squaredNorm);
}

template<typename T, std::size_t N>
T Vector<T, N>::normInf() const {
	T	norm = T();

	for (const auto& v: *this) {
		if (norm < std::abs(v)) {
			norm = std::abs(v);
		}
	}

	return norm;
}



#endif // VECTOR_NORM_TPP
