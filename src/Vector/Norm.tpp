#ifndef VECTOR_NORM_TPP
#define VECTOR_NORM_TPP
#include <cmath>

template<typename T, std::size_t N>
T Vector<T, N>::norm1() const requires(Addable<T> && Absolutable<T>) {
	T norm = T();

	for (const auto& v: *this) {
		if constexpr (StdAbsolutable<T>) {
			norm += std::abs(v);
		} else if constexpr (InnerAbsolutable<T>) {
			norm += v.abs();
		}
	}

	return norm;
}

template<typename T, std::size_t N>
T Vector<T, N>::norm() const requires(Addable<T> && Multiplicable<T> && SquareRootable<T>) {
	T squaredNorm = T();

	for (const auto& v: *this) {
		squaredNorm += v * v;
	}

	if constexpr (StdSquareRootable<T>) {
		return std::sqrt(squaredNorm);
	} else if constexpr (InnerSquareRootable<T>) {
		return squaredNorm.sqrt();
	}
}

template<typename T, std::size_t N>
T Vector<T, N>::normInf() const requires(Absolutable<T>) {
	T norm = T();

	for (const auto& v: *this) {
		if constexpr (StdAbsolutable<T>) {
			if (norm < std::abs(v)) {
				norm = std::abs(v);
			}
		} else if constexpr (InnerAbsolutable<T>) {
			if (norm < v.abs()) {
				norm = v.abs();
			}
		}
	}

	return norm;
}

#endif // VECTOR_NORM_TPP
