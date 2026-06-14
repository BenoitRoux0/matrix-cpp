#ifndef TRAITS_HPP
#define TRAITS_HPP
#include <cmath>

template <typename T>
concept Addable = requires(T a, const T b)
{
	{ a + b } -> std::same_as<T>;
	{ b + a } -> std::same_as<T>;
	{ a += b } -> std::same_as<T&>;
};

template <typename T>
concept Subtractable = requires(T a, const T b)
{
	{ a - b } -> std::same_as<T>;
	{ b - a } -> std::same_as<T>;
	{ a -= b } -> std::same_as<T&>;
};

template <typename T>
concept Multiplicable = requires(T a, const T b)
{
	{ a * b } -> std::same_as<T>;
	{ b * a } -> std::same_as<T>;
	{ a *= b } -> std::same_as<T&>;
};

template <typename T>
concept Divisible = requires(T a, const T b)
{
	{ a / b } -> std::same_as<T>;
	{ b / a } -> std::same_as<T>;
	{ a /= b } -> std::same_as<T&>;
};

template <typename T>
concept Equatable = requires(T a, const T b)
{
	{ a == b } -> std::same_as<bool>;
	{ b == a } -> std::same_as<bool>;
};

template <typename T>
concept Comparable =
		Equatable<T> and
		requires(T a, const T b)
		{
			{ a != b } -> std::same_as<bool>;
			{ b != a } -> std::same_as<bool>;
			{ a > b } -> std::same_as<bool>;
			{ b > a } -> std::same_as<bool>;
			{ a < b } -> std::same_as<bool>;
			{ b < a } -> std::same_as<bool>;
			{ a >= b } -> std::same_as<bool>;
			{ b >= a } -> std::same_as<bool>;
			{ a <= b } -> std::same_as<bool>;
			{ b <= a } -> std::same_as<bool>;
		};

template <typename T>
concept StdAbsolutable = requires(const T a)
                         {
	                         { std::abs(a) } -> std::same_as<T>;
                         } or requires(const T a)
                         {
	                         { std::abs(a) } -> std::floating_point;
                         };

template <typename T>
concept InnerAbsolutable = requires(const T a)
                           {
	                           { a.abs() } -> std::same_as<T>;
                           } or requires(const T a)
                           {
	                           { a.abs() } -> std::floating_point;
                           };

template <typename T>
concept Absolutable = StdAbsolutable<T> || InnerAbsolutable<T>;

template <typename T>
concept StdSquareRootable = requires(const T a)
                            {
	                            { std::sqrt(a) } -> std::same_as<T>;
                            } or requires(const T a)
                            {
	                            { std::sqrt(a) } -> std::floating_point;
                            };

template <typename T>
concept InnerSquareRootable = requires(const T a)
                              {
	                              { a.sqrt() } -> std::same_as<T>;
                              } or requires(const T a)
                              {
	                              { a.sqrt() } -> std::floating_point;
                              };

template <typename T>
concept SquareRootable = StdSquareRootable<T> || InnerSquareRootable<T>;

#endif // TRAITS_HPP
