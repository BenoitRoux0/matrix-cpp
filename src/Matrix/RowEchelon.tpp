#ifndef MATRIX_ROW_ECHELON_TPP
#define MATRIX_ROW_ECHELON_TPP

namespace stackixx::mat {
	template <typename T, std::size_t M, std::size_t N>
	Matrix<T, M, N> Matrix<T, M, N>::rowEchelon() const requires(
		Equatable<T> && Multiplicable<T> && Divisible<T> && Subtractable<T>) {
		Matrix mat(*this);
		T      zero = T();

		for (auto row = mat.begin(); row != mat.end(); ++row) {
			auto leftMost = mat.findLeftMost(row);
			if (leftMost != row)
				mat.swapRows(row, leftMost);

			auto pivot = row->getPivot();

			if (pivot == zero)
				return mat;

			*row *= 1 / pivot;

			auto shift = row->countZeros();

			if (shift == N)
				continue;

			for (auto underRow = row + 1; underRow != mat.end(); ++underRow) {
				auto coef = (*underRow)[shift];
				*underRow -= *row * coef;
			}
		}

		for (auto row = mat.rbegin(); row != mat.rend(); ++row) {
			auto shift = row->countZeros();

			if (shift == N)
				continue;

			for (auto upperRow = mat.begin(); upperRow != row; ++upperRow) {
				auto coef = (*upperRow)[shift];
				*upperRow -= *row * coef;
			}
		}

		return mat;
	}
}


#endif // MATRIX_ROW_ECHELON_TPP
