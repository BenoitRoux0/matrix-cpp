#ifndef VECTOR_SPLIT_TPP
#define VECTOR_SPLIT_TPP

namespace stackixx::mat {
	template <typename T, std::size_t N>
	template <std::size_t P>
	std::tuple<Vector<T, P>, Vector<T, N - P>> Vector<T, N>::split() const requires (P <= N) {
		std::tuple<Vector<T, P>, Vector<T, N - P>> vecs;

		for (std::size_t i = 0; i < P; ++i) {
			std::get<0>(vecs)[i] = this->operator[](i);
		}

		for (std::size_t i = 0; i < N - P; ++i) {
			std::get<1>(vecs)[i] = this->operator[](P + i);
		}

		return vecs;
	}
}

#endif // VECTOR_SPLIT_TPP
