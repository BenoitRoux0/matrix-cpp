#ifndef MATRIX_TRANSPOSE_TPP
#define MATRIX_TRANSPOSE_TPP

namespace stackixx::mat {
	template <typename T, std::size_t M, std::size_t N>
	Matrix<T, N, M> Matrix<T, M, N>::transpose() const {
		Matrix<T, N, M> mat;

		for (std::size_t i = 0; i < M; ++i) {
			for (std::size_t j = 0; j < N; ++j) {
				mat[j][i] = (*this)[i][j];
			}
		}

		return mat;
	}
}

#endif // MATRIX_TRANSPOSE_TPP
