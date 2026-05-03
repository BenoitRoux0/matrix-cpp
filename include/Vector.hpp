#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>

template <typename T, std::size_t N>
class Vector {
public:
	using iterator = T*;
	using const_iterator = const T*;

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
