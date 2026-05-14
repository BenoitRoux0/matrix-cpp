#ifndef MATRIX_TPP
#define MATRIX_TPP

#include <print>

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>::Matrix() {
	for (size_t i = 0; i < M; i++) {
		for (size_t j = 0; j < N; j++) {
			_content[i][j] = T();
		}
	}
}

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>::Matrix(const T& source) {
	for (size_t i = 0; i < M; i++) {
		for (size_t j = 0; j < N; j++) {
			_content[i][j] = source;
		}
	}
}

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>::Matrix(const T source[M][N]) {
	for (size_t i = 0; i < M; i++) {
		for (size_t j = 0; j < N; j++) {
			_content[i][j] = source[i][j];
		}
	}
}

template<typename T, std::size_t M, std::size_t N>
Vector<T, N>& Matrix<T, M, N>::operator[](size_t i) {
	return _content[i];
}

template<typename T, std::size_t M, std::size_t N>
const Vector<T, N>& Matrix<T, M, N>::operator[](size_t i) const {
	return _content[i];
}

template<typename T, std::size_t M, std::size_t N>
typename Matrix<T, M, N>::iterator Matrix<T, M, N>::begin() {
	return _content;
}

template<typename T, std::size_t M, std::size_t N>
typename Matrix<T, M, N>::iterator Matrix<T, M, N>::end() {
	return _content + M;
}

template<typename T, std::size_t M, std::size_t N>
typename Matrix<T, M, N>::const_iterator Matrix<T, M, N>::begin() const {
	return _content;
}

template<typename T, std::size_t M, std::size_t N>
typename Matrix<T, M, N>::const_iterator Matrix<T, M, N>::end() const {
	return _content + M;
}

template<typename T, std::size_t M, std::size_t N>
typename Matrix<T, M, N>::reverse_iterator Matrix<T, M, N>::rbegin() {
	return _content + M - 1;
}

template<typename T, std::size_t M, std::size_t N>
typename Matrix<T, M, N>::reverse_iterator Matrix<T, M, N>::rend() {
	return _content - 1;
}

template<typename T, std::size_t M, std::size_t N>
typename Matrix<T, M, N>::reverse_const_iterator Matrix<T, M, N>::rbegin() const {
	return _content + M - 1;
}

template<typename T, std::size_t M, std::size_t N>
typename Matrix<T, M, N>::reverse_const_iterator Matrix<T, M, N>::rend() const {
	return _content - 1;
}

#endif // MATRIX_TPP
