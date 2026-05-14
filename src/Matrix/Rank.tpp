#ifndef MATRIX_RANK_TPP
#define MATRIX_RANK_TPP

template<typename T, std::size_t M, std::size_t N>
std::size_t Matrix<T, M, N>::rank() const requires(Equatable<T> && Multiplicable<T> && Divisible<T> && Subtractable<T>) {
	auto        mat = rowEchelon();
	std::size_t rank = 0;

	for (auto row: mat) {
		if (row.countZeros() != N) {
			++rank;
		}
	}

	return rank;
}

#endif // MATRIX_RANK_TPP
