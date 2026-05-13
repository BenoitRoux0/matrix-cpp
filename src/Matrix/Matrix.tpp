#ifndef MATRIX_TPP
#define MATRIX_TPP

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>::Matrix() {
	for (size_t i = 0; i < M; i++) {
		for (size_t j = 0; j < N; j++) {
			_content[i][j] = T();
		}
	}
}

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>::Matrix(const T &source) {
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
Vector<T, N> & Matrix<T, M, N>::operator[](size_t i) {
	return _content[i];
}

template<typename T, std::size_t M, std::size_t N>
const Vector<T, N> & Matrix<T, M, N>::operator[](size_t i) const {
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
void Matrix<T, M, N>::print() const {
	for (auto vec: *this) {
		std::print("| {}|\n", vec);
	}
}

#endif // MATRIX_TPP
