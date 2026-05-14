#ifndef MATRIX_INVERSE_TPP
#define MATRIX_INVERSE_TPP

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::inverse() const requires (M == N && Equatable<T> && Multiplicable<T> && Divisible<T> && Subtractable<T>) {
	Matrix<T, M, 2 * N> mat = this->append<N>(Matrix::identity());

	return std::get<1>(mat.rowEchelon().template split<N>());
}

#endif // MATRIX_INVERSE_TPP
