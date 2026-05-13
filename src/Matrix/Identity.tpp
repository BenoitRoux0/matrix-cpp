#ifndef MATRIX_IDENTITY_TPP
#define MATRIX_IDENTITY_TPP

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::identity() requires(M == N) {
	Matrix mat;

	for (std::size_t i = 0; i < M; ++i) {
		mat[i][i] = 1;
	}

	return mat;
}

#endif // MATRIX_IDENTITY_TPP
