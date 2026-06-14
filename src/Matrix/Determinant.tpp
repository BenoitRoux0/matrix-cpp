#ifndef MATRIX_DETERMINANT_TPP
#define MATRIX_DETERMINANT_TPP

namespace stackixx::mat {
	template <typename T, std::size_t M, std::size_t N>
	T Matrix<T, M, N>::determinant() const requires(M == N && Equatable<T> && Multiplicable<T> && Divisible<T> &&
	                                                Subtractable<T>) {
		const auto [ref, coef] = this->rowEchelonWithDetCoef();
		T          det = coef;

		if (det == 0)
			return 0;

		for (std::size_t i = 0; i < M; ++i) {
			det *= ref[i][i];
		}

		return det;
	}
}

#endif // MATRIX_DETERMINANT_TPP
