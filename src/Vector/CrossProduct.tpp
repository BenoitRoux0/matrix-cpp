#ifndef VECTOR_CROSS_PRODUCT_TPP
#define VECTOR_CROSS_PRODUCT_TPP
namespace stackixx::mat {
	template <typename T, std::size_t N>
	Vector<T, N> Vector<T, N>::crossProduct(const Vector& rhs) const requires (
		N == 3 && Multiplicable<T> && Subtractable<T>) {
		Vector product;

		product[0] = (*this)[1] * rhs[2] - (*this)[2] * rhs[1];
		product[1] = (*this)[2] * rhs[0] - (*this)[0] * rhs[2];
		product[2] = (*this)[0] * rhs[1] - (*this)[1] * rhs[0];

		return product;
		}
}

#endif // VECTOR_CROSS_PRODUCT_TPP
