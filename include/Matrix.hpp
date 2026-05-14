#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Traits.hpp"
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
	Matrix(const T source[M][N]);
	explicit Matrix(const T& source);

	Vector<T, N>&       operator[](size_t i);
	const Vector<T, N>& operator[](size_t i) const;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();

	reverse_const_iterator rbegin() const;
	reverse_const_iterator rend() const;

	Matrix  operator+(const Matrix& rhs) const requires(Addable<T>);
	Matrix  operator-(const Matrix& rhs) const requires(Subtractable<T>);
	Matrix  operator*(const T& scalar) const requires(Multiplicable<T>);
	Matrix& operator+=(const Matrix& rhs) requires(Addable<T>);
	Matrix& operator-=(const Matrix& rhs) requires(Subtractable<T>);
	Matrix& operator*=(const T& scalar) requires(Multiplicable<T>);
	template<std::size_t P>
	Matrix<T, M, P> operator*(const Matrix<T, N, P>&) const requires(Addable<T> && Multiplicable<T>);
	Vector<T, M>    operator*(const Vector<T, N>&) const;

	T trace() const requires(M == N && Addable<T>);

	Matrix<T, N, M> transpose() const;

	void           swapRows(iterator r1, iterator r2);
	iterator       findLeftMost(iterator start) requires(Equatable<T>);
	const_iterator findLeftMost(const_iterator start) const requires(Equatable<T>);

	Matrix rowEchelon() const requires(Equatable<T> && Multiplicable<T> && Divisible<T> && Subtractable<T>);

	std::tuple<Matrix, T> rowEchelonWithDetCoef() const requires(
		Equatable<T> && Multiplicable<T> && Divisible<T> && Subtractable<T>);

	T determinant() const requires(M == N && Equatable<T> && Multiplicable<T> && Divisible<T> && Subtractable<T>);

	Matrix inverse() const requires(M == N && Equatable<T> && Multiplicable<T> && Divisible<T> && Subtractable<T>);

	template<std::size_t P>
	Matrix<T, M, N + P> append(const Matrix<T, M, P>& right) const;
	template<std::size_t P>
	Matrix<T, M, N + P> operator|(const Matrix<T, M, P>& right) const;
	template<std::size_t P>
	std::tuple<Matrix<T, M, P>, Matrix<T, M, N - P>> split() const requires(P <= N);

	std::size_t rank() const requires(Equatable<T> && Multiplicable<T> && Divisible<T> && Subtractable<T>);

	static Matrix identity() requires(M == N);

	bool operator==(const Matrix& rhs) const requires(Equatable<T>);

private:
	Vector<T, N> _content[M];
};

template<typename T, std::size_t M, std::size_t N>
struct std::formatter<Matrix<T, M, N>>: std::formatter<string_view> {
	constexpr auto parse(std::format_parse_context& ctx) {
		return ctx.begin();
	}

	auto format(const Matrix<T, M, N>& mat, std::format_context& ctx) const {
		std::string	tmp;

		for (auto vec: mat) {
			std::format_to(std::back_inserter(tmp), "{}\n", vec);
		}

		return std::formatter<string_view>::format(tmp, ctx);
	}
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
