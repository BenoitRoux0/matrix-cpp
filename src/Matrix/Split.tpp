#ifndef MATRIX_SPLIT_TPP
#define MATRIX_SPLIT_TPP

namespace stackixx::mat {
	template <typename T, std::size_t M, std::size_t N>
	template <std::size_t P>
	std::tuple<Matrix<T, M, P>, Matrix<T, M, N - P>> Matrix<T, M, N>::split() const requires (P <= N) {
		std::tuple<Matrix<T, M, P>, Matrix<T, M, N - P>> mats;

		for (std::size_t i = 0; i < M; ++i) {
			auto [first, second] = this->operator[](i).template split<P>();
			std::get<0>(mats)[i] = first;
			std::get<1>(mats)[i] = second;
		}

		return mats;
	}
}

#endif // MATRIX_SPLIT_TPP
