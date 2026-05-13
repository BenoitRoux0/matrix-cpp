#ifndef MATRIX_ROW_ECHELON_WITH_DET_COEF_TPP
#define MATRIX_ROW_ECHELON_WITH_DET_COEF_TPP

template<typename T, std::size_t M, std::size_t N>
std::tuple<Matrix<T, M, N>, T> Matrix<T, M, N>::rowEchelonWithDetCoef() const {
	Matrix	mat(*this);
	T		detCoef = T(1);

	for (auto row = mat.begin(); row + 1 != mat.end(); ++row) {
		auto leftMost = mat.findLeftMost(row);
		if (leftMost != row) {
			mat.swapRows(row, leftMost);
			detCoef *= -1;
		}

		auto pivot = row->getPivot();

		if (pivot == 0)
			return mat, 0;

		*row *= 1 / pivot;
		detCoef *= pivot;

		auto shift = row->countZeros();

		for (auto underRow = row + 1; underRow != mat.end(); ++underRow) {
			auto coef = (*underRow)[shift];
			*underRow -= *row * coef;
		}
	}

	return mat, detCoef;
}

#endif // MATRIX_ROW_ECHELON_WITH_DET_COEF_TPP
