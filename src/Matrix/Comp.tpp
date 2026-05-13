#ifndef MATRIX_COMP_TPP
#define MATRIX_COMP_TPP

template<typename T, std::size_t M, std::size_t N>
bool Matrix<T, M, N>::operator==(const Matrix &rhs) const {
	for (const auto& [lValue, rValue]: std::views::zip(*this, rhs)) {
		if (lValue != rValue)
			return false;
	}

	return true;
}

#endif // MATRIX_COMP_TPP
