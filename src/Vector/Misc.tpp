#ifndef VECTOR_MISC_TPP
#define VECTOR_MISC_TPP

template<typename T, std::size_t N>
std::size_t Vector<T, N>::countZeros() const requires(Equatable<T>) {
	std::size_t count = 0;
	T           zero = T();

	for (auto value: *this) {
		if (!(value == zero))
			return count;
		++count;
	}

	return count;
}

template<typename T, std::size_t N>
T Vector<T, N>::getPivot() const requires(Equatable<T>) {
	T zero = T();

	for (auto value: *this) {
		if (!(value == zero))
			return value;
	}

	return 0;
}

#endif // VECTOR_MISC_TPP
