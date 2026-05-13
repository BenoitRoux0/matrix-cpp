#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "Vector.hpp"
#include "Iterators.hpp"

template<typename T, std::size_t M, std::size_t N>
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

	explicit Matrix(const T& source);

	Matrix(const T source[M][N]);

	Vector<T, N>& operator[](size_t i);

	const Vector<T, N>& operator[](size_t i) const;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();

	reverse_const_iterator rbegin() const;
	reverse_const_iterator rend() const;

	Matrix operator+(const Matrix& rhs) const;

	Matrix operator-(const Matrix& rhs) const;

	Matrix operator*(const T& scalar) const;

	Matrix& operator+=(const Matrix& rhs);

	Matrix& operator-=(const Matrix& rhs);

	Matrix& operator*=(const T& scalar);

	template<std::size_t P>
	Matrix<T, M, P> operator*(const Matrix<T, N, P>&) const;

	Vector<T, M> operator*(const Vector<T, N>&) const;

	T trace() const requires(M == N);

	Matrix<T, N, M> transpose() const;

	void swapRows(iterator r1, iterator r2);

	iterator findLeftMost(iterator start);

	const_iterator findLeftMost(const_iterator start) const;

	Matrix rowEchelon() const;

	std::tuple<Matrix, T> rowEchelonWithDetCoef() const;

	T determinant() const requires(M == N);

	Matrix inverse() const requires(M == N);

	template<std::size_t P>
	Matrix<T, M, N + P> append(const Matrix<T, M, P>& right) const;

	template<std::size_t P>
	Matrix<T, M, N + P> operator|(const Matrix<T, M, P>& right) const;

	template<std::size_t P>
	std::tuple<Matrix<T, M, P>, Matrix<T, M, N - P>> split() const requires(P <= N);

	std::size_t	rank();

	static Matrix identity() requires(M == N);

	bool operator==(const Matrix& rhs) const;

	void print() const;
private:
	Vector<T, N> _content[M];
};

#include "Matrix/Matrix.tpp"
#include "Matrix/Add.tpp"
#include "Matrix/Sub.tpp"
#include "Matrix/Scale.tpp"
#include "Matrix/Comp.tpp"
#include "Matrix/Mul.tpp"
#include "Matrix/Trace.tpp"
#include "Matrix/Transpose.tpp"
#include "Matrix/RowEchelon.tpp"
#include "Matrix/Misc.tpp"
#include "Matrix/RowEchelonWithDetCoef.tpp"
#include "Matrix/Determinant.tpp"
#include "Matrix/Inverse.tpp"
#include "Matrix/Identity.tpp"
#include "Matrix/Append.tpp"
#include "Matrix/Split.tpp"
#include "Matrix/Rank.tpp"

#endif // MATRIX_HPP
