#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "Vector.hpp"

template <typename T, std::size_t M, std::size_t N>
class Matrix {
public:
	using iterator = Vector<T, N>*;
	using const_iterator = const Vector<T, N>*;

	Matrix();
	Matrix(const T& source);
	explicit Matrix(const T source[M][N]);

	Vector<T, N>&		operator[](size_t i);
	const Vector<T, N>&	operator[](size_t i) const;

	iterator	begin();
	iterator	end();

	const_iterator	begin() const;
	const_iterator	end() const;
private:
	Vector<T, N> 	_content[M];
};

#include "Matrix.tpp"

#endif // MATRIX_HPP
