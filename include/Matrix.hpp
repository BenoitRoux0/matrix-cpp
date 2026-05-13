#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "Vector.hpp"
#include "Iterators.hpp"

template <typename T, std::size_t M, std::size_t N>
class Matrix {
public:
	using iterator = random_access_iterator<Vector<T, N>>;
	static_assert(std::random_access_iterator<iterator>);

	using const_iterator = random_access_iterator<const Vector<T, N>>;
	static_assert(std::random_access_iterator<const_iterator>);

	using reverse_iterator = reverse_bidirectional_iterator<Vector<T, N>>;
	static_assert(std::bidirectional_iterator<reverse_iterator>);

	using reverse_const_iterator = reverse_bidirectional_iterator<const Vector<T, N>>;
	static_assert(std::bidirectional_iterator<reverse_const_iterator>);

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
