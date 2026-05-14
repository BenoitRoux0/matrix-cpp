#ifndef VECTOR_DOT_TPP
#define VECTOR_DOT_TPP

template<typename T, std::size_t N>
T Vector<T, N>::dot(const Vector& rhs) const requires(Multiplicable<T> && Addable<T>) {
	T val = T();

	for (auto [lValue, rValue]: std::views::zip(*this, rhs)) {
		val += lValue * rValue;
	}

	return val;
}

#endif // VECTOR_DOT_TPP
