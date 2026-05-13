#ifndef VECTOR_MISC_TPP
#define VECTOR_MISC_TPP

template<typename T, std::size_t N>
std::size_t Vector<T, N>::countZeros() const {
	std::size_t count = 0;

	for (auto value: *this) {
		if (value != 0)
			return count;
		++count;
	}

	return count;
}

template<typename T, std::size_t N>
T Vector<T, N>::getPivot() const {
	for (auto value: *this) {
		if (value != 0)
			return value;
	}

	return 0;
}

#endif // VECTOR_MISC_TPP
