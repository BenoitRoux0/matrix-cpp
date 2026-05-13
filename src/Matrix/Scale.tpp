#ifndef MATRIX_SCALE_TPP
#define MATRIX_SCALE_TPP

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::operator*(const T &scalar) const {
	Matrix	m(*this);

	for (auto& val: m) {
		val *= scalar;
	}

	return m;
}

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>& Matrix<T, M, N>::operator*=(const T &scalar) {
	for (auto& val: *this) {
		val *= scalar;
	}

	return *this;
}

#endif // MATRIX_SCALE_TPP
