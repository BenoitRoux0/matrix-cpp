#ifndef LINEAR_COMBINATION_TPP
#define LINEAR_COMBINATION_TPP

template<typename T, std::size_t N>
template<size_t K>
Vector<T, N> Vector<T, N>::linearCombination(Vector vectors[K], const T coefs[K]) requires(Multiplicable<T> && Addable<T>) {
	Vector v;

	for (size_t i = 0; i < K; ++i) {
		v += vectors[i] * coefs[i];
	}

	return v;
}

#endif // LINEAR_COMBINATION_TPP
