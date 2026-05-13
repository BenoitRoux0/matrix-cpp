#ifndef MATRIX_SUB_TPP
#define MATRIX_SUB_TPP

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::operator-(const Matrix &rhs) const {
	Matrix	m(*this);

	for (auto [lVal, rVal]: std::views::zip(m, rhs)) {
		lVal -= rVal;
	}

	return m;
}

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>& Matrix<T, M, N>::operator-=(const Matrix &rhs) {
	for (auto [lVal, rVal]: std::views::zip(this, rhs)) {
		lVal -= rVal;
	}

	return *this;
}

#endif // MATRIX_SUB_TPP
