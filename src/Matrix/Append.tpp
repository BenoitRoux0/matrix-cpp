#ifndef MATRIX_APPEND_TPP
#define MATRIX_APPEND_TPP

namespace stackixx::mat {
	template <typename T, std::size_t M, std::size_t N>
	template <std::size_t P>
	Matrix<T, M, N + P> Matrix<T, M, N>::append(const Matrix<T, M, P>& right) const {
		Matrix<T, M, N + P> mat;

		for (std::size_t i = 0; i < M; ++i) {
			mat[i] = this->operator[](i).append(right[i]);
		}

		return mat;
	}

	template <typename T, std::size_t M, std::size_t N>
	template <std::size_t P>
	Matrix<T, M, N + P> Matrix<T, M, N>::operator|(const Matrix<T, M, P>& right) const {
		return this->append(right);
	}
}

#endif // MATRIX_APPEND_TPP
