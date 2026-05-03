#ifndef VECTOR_TPP
#define VECTOR_TPP

template<typename T, std::size_t N>
Vector<T, N>::Vector(const T source[N]) {
	for (size_t i = 0; i < N; ++i) {
		_content[i] = source[i];
	}
}

template<typename T, std::size_t N>
Vector<T, N>::Vector() {
	for (size_t i = 0; i < N; ++i) {
		_content[i] = T();
	}
}

template<typename T, std::size_t N>
Vector<T, N>::Vector(const T &source) {
	for (size_t i = 0; i < N; ++i) {
		_content[i] = source;
	}
}

template<typename T, std::size_t N>
T&	Vector<T, N>::operator[](size_t i) {
	return _content[i];
}

template<typename T, std::size_t N>
const T&	Vector<T, N>::operator[](std::size_t i) const {
	return _content[i];
}

template<typename T, std::size_t N>
typename Vector<T, N>::iterator Vector<T, N>::begin() {
	return _content;
}

template<typename T, std::size_t N>
typename Vector<T, N>::iterator Vector<T, N>::end() {
	return _content + N;
}

template<typename T, std::size_t N>
typename Vector<T, N>::const_iterator Vector<T, N>::begin() const {
	return _content;
}

template<typename T, std::size_t N>
typename Vector<T, N>::const_iterator Vector<T, N>::end() const {
	return _content + N;
}

#endif // VECTOR_TPP
