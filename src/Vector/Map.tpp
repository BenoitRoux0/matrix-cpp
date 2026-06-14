#ifndef VECTOR_MAP_TPP
#define VECTOR_MAP_TPP

namespace stackixx::mat {
	template <typename T, std::size_t N>
	template <typename U>
	Vector<T, N>::template map_iterator<U> Vector<T, N>::map(std::function<U(T)> func) {
		return map_iterator<U>(_content, func);
	}
}

#endif // VECTOR_MAP_TPP
