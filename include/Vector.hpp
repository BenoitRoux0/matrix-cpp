#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <format>
#include "Iterators.hpp"
#include "Traits.hpp"

template<typename T, std::size_t N>
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
	Vector(const T [N]);
	explicit Vector(const T& source);

	T&       operator[](std::size_t i);
	const T& operator[](std::size_t i) const;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();

	reverse_const_iterator rbegin() const;
	reverse_const_iterator rend() const;

	Vector operator+(const Vector& rhs) const requires(Addable<T>);
	Vector operator-(const Vector& rhs) const requires(Subtractable<T>);
	Vector operator*(const T& scalar) const requires(Multiplicable<T>);
	Vector operator+=(const Vector& rhs) requires(Addable<T>);
	Vector operator-=(const Vector& rhs) requires(Subtractable<T>);
	Vector operator*=(const T& scalar) requires(Multiplicable<T>);
	bool   operator==(const Vector& rhs) const requires(Equatable<T>);

	template<size_t K>
	static Vector linearCombination(Vector vectors[K], const T coefs[K]) requires(Multiplicable<T> && Addable<T>);

	T dot(const Vector& rhs) const requires(Multiplicable<T> && Addable<T>);

	T norm1() const requires(Addable<T> && Absolutable<T>);
	T norm() const requires(Addable<T> && Multiplicable<T> && SquareRootable<T>);
	T normInf() const requires(Absolutable<T>);

	T cosine(const Vector& rhs) const requires(Addable<T> && Multiplicable<T> && SquareRootable<T>);

	Vector crossProduct(const Vector& rhs) const requires (N == 3 && Multiplicable<T> && Subtractable<T>);

	std::size_t countZeros() const requires(Equatable<T>);
	T           getPivot() const requires(Equatable<T>);

	template<std::size_t P>
	Vector<T, N + P> append(const Vector<T, P>& right) const;
	template<std::size_t P>
	Vector<T, N + P> operator|(const Vector<T, P>& right) const;

	template<std::size_t P>
	std::tuple<Vector<T, P>, Vector<T, N - P>> split() const requires(P <= N);

private:
	T _content[N];
};

template<typename T, std::size_t N>
Vector<T, N> operator*(const T& scalar, const Vector<T, N>& vec) requires(Multiplicable<T>);

template<typename T, std::size_t N>
struct std::formatter<Vector<T, N>>: std::formatter<string_view> {
	constexpr auto parse(std::format_parse_context& ctx) {
		return ctx.begin();
	}

	auto format(const Vector<T, N>& vec, std::format_context& ctx) const {
		std::string	tmp;

		std::format_to(std::back_inserter(tmp), "{{ ");

		for (auto val: vec) {
			std::format_to(std::back_inserter(tmp), "{} ", val);
		}

		std::format_to(std::back_inserter(tmp), "}}");

		return std::formatter<string_view>::format(tmp, ctx);
	}
};

#include "Vector/Vector.tpp"
#include "Vector/Add.tpp"
#include "Vector/Sub.tpp"
#include "Vector/Scale.tpp"
#include "Vector/linearCombination.tpp"
#include "Vector/Comp.tpp"
#include "Vector/Dot.tpp"
#include "Vector/Norm.tpp"
#include "Vector/CrossProduct.tpp"
#include "Vector/Cosine.tpp"
#include "Vector/Misc.tpp"
#include "Vector/Append.tpp"
#include "Vector/Split.tpp"

#endif // VECTOR_HPP
