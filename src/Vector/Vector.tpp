#ifndef VECTOR_TPP
#define VECTOR_TPP
#include <ranges>

namespace stackixx::mat {
	template <typename T, std::size_t N>
	Vector<T, N>::Vector(const T source[N]) {
		for (size_t i = 0; i < N; ++i) {
			_content[i] = source[i];
		}
	}

	template <typename T, std::size_t N>
	template <typename InputIteFirst, typename InputIteLast>
	Vector<T, N>::Vector(InputIteFirst first, InputIteLast last) requires(
		std::input_iterator<InputIteFirst> && std::input_iterator<InputIteLast>) {
		size_t i = 0;

		for (auto ite = first; ite != last && i != N; ++ite, ++i) {
			(*this)[i] = *ite;
		}
	}

	template <typename T, std::size_t N>
	Vector<T, N>::Vector() {
		for (size_t i = 0; i < N; ++i) {
			_content[i] = T();
		}
	}

	template <typename T, std::size_t N>
	Vector<T, N>::Vector(std::initializer_list<T> initlist) {
		for (auto [dst, src]: std::views::zip(*this, initlist)) {
			dst = src;
		}
	}

	template <typename T, std::size_t N>
	Vector<T, N>::Vector(const T& source) {
		for (size_t i = 0; i < N; ++i) {
			_content[i] = source;
		}
	}

	template <typename T, std::size_t N>
	Vector<T, N>& Vector<T, N>::operator=(const T source[N]) {
		*this = Vector(source);

		return *this;
	}

	template <typename T, std::size_t N>
	T& Vector<T, N>::operator[](size_t i) {
		return _content[i];
	}

	template <typename T, std::size_t N>
	const T& Vector<T, N>::operator[](std::size_t i) const {
		return _content[i];
	}

	template <typename T, std::size_t N>
	typename Vector<T, N>::iterator Vector<T, N>::begin() {
		return _content;
	}

	template <typename T, std::size_t N>
	typename Vector<T, N>::iterator Vector<T, N>::end() {
		return _content + N;
	}

	template <typename T, std::size_t N>
	typename Vector<T, N>::const_iterator Vector<T, N>::begin() const {
		return _content;
	}

	template <typename T, std::size_t N>
	typename Vector<T, N>::const_iterator Vector<T, N>::end() const {
		return _content + N;
	}

	template <typename T, std::size_t N>
	typename Vector<T, N>::reverse_iterator Vector<T, N>::rbegin() {
		return _content + N - 1;
	}

	template <typename T, std::size_t N>
	typename Vector<T, N>::reverse_iterator Vector<T, N>::rend() {
		return _content - 1;
	}

	template <typename T, std::size_t N>
	typename Vector<T, N>::reverse_const_iterator Vector<T, N>::rbegin() const {
		return _content + N - 1;
	}

	template <typename T, std::size_t N>
	typename Vector<T, N>::reverse_const_iterator Vector<T, N>::rend() const {
		return _content - 1;
	}
}

#endif // VECTOR_TPP
