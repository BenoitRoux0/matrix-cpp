#ifndef VECTOR_COMP_TPP
#define VECTOR_COMP_TPP

template<typename T, std::size_t N>
bool Vector<T, N>::operator==(const Vector &rhs) const {
	for (const auto& [lValue, rValue]: std::views::zip(*this, rhs)) {
		if (lValue != rValue)
			return false;
	}

	return true;
}

#endif // VECTOR_COMP_TPP
