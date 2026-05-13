#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include "Iterators.hpp"

template <typename T, std::size_t N>
class Vector {
public:
	using iterator = random_access_iterator<T>;
	static_assert(std::random_access_iterator<iterator>);

	using const_iterator = random_access_iterator<const T>;
	static_assert(std::random_access_iterator<const_iterator>);

	using reverse_iterator = reverse_bidirectional_iterator<T>;
	static_assert(std::bidirectional_iterator<reverse_iterator>);

	using reverse_const_iterator = reverse_bidirectional_iterator<const T>;
	static_assert(std::bidirectional_iterator<reverse_const_iterator>);

	Vector();
	Vector(const T& source);
	explicit Vector(const T[N]);

	T&			operator[](size_t i);
	const T&	operator[](size_t i) const;

	iterator	begin();
	iterator	end();

	const_iterator	begin() const;
	const_iterator	end() const;
private:
	T	_content[N];
};

#include "Vector.tpp"

#endif // VECTOR_HPP
