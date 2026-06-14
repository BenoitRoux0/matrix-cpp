#ifndef MATRIX_INVERSE_TPP
#define MATRIX_INVERSE_TPP

namespace stackixx::mat {
	template <typename T, std::size_t M, std::size_t N>
	std::optional<Matrix<T, M, N>> Matrix<T, M, N>::inverse() const requires (
		M == N && Equatable<T> && Multiplicable<T> && Divisible<T> && Subtractable<T>) {
		Matrix<T, M, 2 * N> mat = this->append<N>(Matrix::identity());

		auto [identity, inverse] = mat.rowEchelon().template split<N>();

		if (identity != Matrix::identity())
			return {};

		return inverse;
	}
}

#endif // MATRIX_INVERSE_TPP
