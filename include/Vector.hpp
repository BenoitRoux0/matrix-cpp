#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <format>
#include <functional>

#include "Iterators.hpp"
#include "Traits.hpp"

namespace stackixx::mat {
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

		template <typename U>
		using map_iterator = map_iterator<T, U>;

		Vector();
		Vector(std::initializer_list<T> initlist);
		Vector(const T [N]);
		template <typename InputIteFirst, typename InputIteLast>
		Vector(InputIteFirst first, InputIteLast last) requires(
			std::input_iterator<InputIteFirst> && std::input_iterator<InputIteLast>);
		explicit Vector(const T& source);

		Vector& operator=(const T [N]);

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

		Vector  operator+(const Vector& rhs) const requires(Addable<T>);
		Vector  operator-(const Vector& rhs) const requires(Subtractable<T>);
		Vector  operator*(const T& scalar) const requires(Multiplicable<T>);
		Vector& operator+=(const Vector& rhs) requires(Addable<T>);
		Vector& operator-=(const Vector& rhs) requires(Subtractable<T>);
		Vector& operator*=(const T& scalar) requires(Multiplicable<T>);
		bool    equal(const Vector& rhs) const requires(Equatable<T>);
		bool    operator==(const Vector& rhs) const requires(Equatable<T>);

		Vector& addScalar(const Vector& other, const T& scalar);
		Vector  addScalar(const Vector& other, const T& scalar) const;

		T dot(const Vector& rhs) const requires(Multiplicable<T> && Addable<T>);

		T norm1() const requires(Addable<T> && Absolutable<T>);
		T norm() const requires(Addable<T> && Multiplicable<T> && SquareRootable<T>);
		T normInf() const requires(Absolutable<T>);

		std::optional<T> cosine(const Vector& rhs) const requires(Addable<T> && Multiplicable<T> && SquareRootable<T>);

		Vector crossProduct(const Vector& rhs) const requires (N == 3 && Multiplicable<T> && Subtractable<T>);

		std::size_t countZeros() const requires(Equatable<T>);
		T           getPivot() const requires(Equatable<T>);

		template <std::size_t P>
		Vector<T, N + P> append(const Vector<T, P>& right) const;
		template <std::size_t P>
		Vector<T, N + P> operator|(const Vector<T, P>& right) const;

		template <std::size_t P>
		std::tuple<Vector<T, P>, Vector<T, N - P>> split() const requires(P <= N);

		template <typename U>
		map_iterator<U> map(std::function<U(T)>);

	private:
		T _content[N];
	};


	template <typename T, std::size_t N>
	Vector<T, N> operator*(const T& scalar, const Vector<T, N>& vec) requires(Multiplicable<T>);
}

template <typename T, std::size_t N>
struct std::formatter<stackixx::mat::Vector<T, N>>: std::formatter<string_view> {
	bool _projFormat{false};

	constexpr auto parse(std::format_parse_context& ctx) {
		auto pos = ctx.begin();
		for (; pos != ctx.end() && *pos != '}'; ++pos) {
			if (*pos == 'p' || *pos == 'P')
				_projFormat = true;
		}
		return pos;
	}

	auto format(const stackixx::mat::Vector<T, N>& vec, std::format_context& ctx) const {
		std::string tmp;

		if (_projFormat) {
			auto ite = vec.begin();
			std::format_to(std::back_inserter(tmp), "{}", *ite);
			++ite;
			for (; ite != vec.end(); ++ite) {
				std::format_to(std::back_inserter(tmp), ", {}", *ite);
			}

			return std::formatter<string_view>::format(tmp, ctx);
		}

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
#include "Vector/Comp.tpp"
#include "Vector/Dot.tpp"
#include "Vector/Norm.tpp"
#include "Vector/CrossProduct.tpp"
#include "Vector/Cosine.tpp"
#include "Vector/Misc.tpp"
#include "Vector/Append.tpp"
#include "Vector/Split.tpp"
#include "Vector/Map.tpp"

#endif // VECTOR_HPP
