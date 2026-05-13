#ifndef VECTOR_APPEND_TPP
#define VECTOR_APPEND_TPP

template<typename T, std::size_t N>
template<std::size_t P>
Vector<T, N + P> Vector<T, N>::append(const Vector<T, P>& right) const {
	Vector<T, N + P> vec;

	for (std::size_t i = 0; i < N; ++i) {
		vec[i] = this->operator[](i);
	}

	for (std::size_t i = 0; i < P; ++i) {
		vec[N + i] = right[i];
	}

	return vec;
}

template<typename T, std::size_t N>
template<std::size_t P>
Vector<T, N + P> Vector<T, N>::operator|(const Vector<T, P>& right) const {
	return this->append(right);
}

#endif // VECTOR_APPEND_TPP
