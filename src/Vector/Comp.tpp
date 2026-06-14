#ifndef VECTOR_COMP_TPP
#define VECTOR_COMP_TPP
namespace stackixx::mat {
	template <typename T, std::size_t N>
	bool Vector<T, N>::equal(const Vector& rhs) const requires (Equatable<T>)
	{
		for (const auto& [lValue, rValue]: std::views::zip(*this, rhs)) {
			if (!(lValue == rValue))
				return false;
		}

		return true;
	}

	template <typename T, std::size_t N>
	bool Vector<T, N>::operator==(const Vector& rhs) const requires(Equatable<T>) {
		return equal(rhs);
	}
}

#endif // VECTOR_COMP_TPP
