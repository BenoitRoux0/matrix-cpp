#ifndef VECTOR_COSINE_TPP
#define VECTOR_COSINE_TPP

namespace stackixx::mat {
	template <typename T, std::size_t N>
	std::optional<T> Vector<T, N>::cosine(const Vector& rhs) const requires(
		Addable<T> && Multiplicable<T> && SquareRootable<T>) {
		auto normsProduct = this->norm() * rhs.norm();

		if (normsProduct == 0)
			return {};

		return this->dot(rhs) / normsProduct;
	}
}

#endif // VECTOR_COSINE_TPP
