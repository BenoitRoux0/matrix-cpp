#ifndef MATRIX_MUL_TPP
#define MATRIX_MUL_TPP

namespace stackixx::mat {
	template <typename T, std::size_t M, std::size_t N>
	template <std::size_t P>
	Matrix<T, M, P> Matrix<T, M, N>::operator*(const Matrix<T, N, P>& rhs) const requires(
		Addable<T> && Multiplicable<T>) {
		Matrix<T, M, P> mat{T()};

		for (std::size_t i = 0; i < M; ++i) {
			for (std::size_t j = 0; j < N; ++j) {
				for (std::size_t k = 0; k < P; ++k) {
					mat[i][k] += (*this)[i][j] * rhs[j][k];
				}
			}
		}

		return mat;
	}

	template <typename T, std::size_t M, std::size_t N>
	Vector<T, M> Matrix<T, M, N>::operator*(const Vector<T, N>& rhs) const {
		Vector<T, M> vec;

		for (std::size_t i = 0; i < M; ++i) {
			vec[i] = (*this)[i].dot(rhs);
		}

		return vec;
	}
}

#endif // MATRIX_MUL_TPP
