#ifndef MATRIX_COMP_TPP
#define MATRIX_COMP_TPP

namespace stackixx::mat {
	template <typename T, std::size_t M, std::size_t N>
	bool Matrix<T, M, N>::equal(const Matrix& rhs) const requires (Equatable<T>) {
		for (const auto& [lValue, rValue]: std::views::zip(*this, rhs)) {
			if (lValue != rValue)
				return false;
		}

		return true;
	}

	template <typename T, std::size_t M, std::size_t N>
	bool Matrix<T, M, N>::operator==(const Matrix& rhs) const requires(Equatable<T>) {
		return equal(rhs);
	}
}

#endif // MATRIX_COMP_TPP
