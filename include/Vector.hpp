#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include "Iterators.hpp"

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

	explicit Vector(const T& source);

	Vector(const T [N]);

	T& operator[](size_t i);

	const T& operator[](size_t i) const;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();

	reverse_const_iterator rbegin() const;
	reverse_const_iterator rend() const;

	Vector operator+(const Vector& rhs) const;

	Vector operator-(const Vector& rhs) const;

	Vector operator*(const T& scalar) const;

	Vector operator+=(const Vector& rhs);

	Vector operator-=(const Vector& rhs);

	Vector operator*=(const T& scalar);

	bool operator==(const Vector& rhs) const;

	template<size_t K>
	static Vector linearCombination(Vector vectors[K], const T coefs[K]);

	T dot(const Vector& rhs) const;

	T norm1() const;

	T norm() const;

	T normInf() const;

	T cosine(const Vector& rhs) const;

	Vector crossProduct(const Vector& rhs) const requires (N == 3);

	std::size_t countZeros() const;

	T getPivot() const;

	template<std::size_t P>
	Vector<T, N + P> append(const Vector<T, P>& right) const;

	template<std::size_t P>
	Vector<T, N + P> operator|(const Vector<T, P>& right) const;

	template<std::size_t P>
	std::tuple<Vector<T, P>, Vector<T, N - P>> split() const requires(P <= N);

	void print() const;

private:
	T _content[N];
};

template<typename T, std::size_t N>
Vector<T, N> operator*(const T& scalar, const Vector<T, N>& vec);

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
