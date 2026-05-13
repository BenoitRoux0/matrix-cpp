#ifndef VECTOR_COSINE_TPP
#define VECTOR_COSINE_TPP

template<typename T, std::size_t N>
T Vector<T, N>::cosine(const Vector& rhs) const {
	return this->dot(rhs) / (this->norm() * rhs.norm());
}

#endif // VECTOR_COSINE_TPP
