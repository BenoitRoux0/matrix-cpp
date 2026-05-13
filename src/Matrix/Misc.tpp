#ifndef MATRIX_MISC_TPP
#define MATRIX_MISC_TPP

template<typename T, std::size_t M, std::size_t N>
void Matrix<T, M, N>::swapRows(iterator r1, iterator r2) {
	iterator tmp = r1;

	*r1 = *r2;
	*r2 = *tmp;
}

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>::iterator Matrix<T, M, N>::findLeftMost(iterator start) {
	iterator	found = start;
	std::size_t	count = start->countZeros();

	for (auto ite = start; ite != this->end(); ++ite) {
		if (ite->countZeros() < count) {
			count = ite->countZeros();
			found = ite;
		}
	}

	return found;
}

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>::const_iterator Matrix<T, M, N>::findLeftMost(const const_iterator start) const {
	const_iterator	found = start;
	std::size_t		count = start->countZeros();

	for (auto ite = start; ite != this->end(); ++ite) {
		if (ite->countZeros() < count) {
			count = ite->countZeros();
			found = ite;
		}
	}

	return found;
}



#endif // MATRIX_MISC_TPP
