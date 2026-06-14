#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <format>

#include "Vector.hpp"
#include "Misc.hpp"

namespace stackixx {
	class Complex {
	public:
		Complex();
		Complex(double a);
		Complex(double a, double b);

		static Complex fromCartesian(double x, double y);
		static Complex fromCartesian(const mat::Vector<double, 2>& vec);
		static Complex fromPolar(double r, double theta);

		std::tuple<double, double> toCartesian() const;
		std::tuple<double, double> toPolar() const;

		//cartesian
		double re() const;
		double im() const;

		//polar
		double abs() const;
		double theta() const;

		Complex sqrt() const;

		Complex conjugate() const;

		Complex  operator+(const Complex& rhs) const;
		Complex& operator+=(const Complex& rhs);
		Complex  operator-(const Complex& rhs) const;
		Complex& operator-=(const Complex& rhs);
		Complex  operator*(const Complex& rhs) const;
		Complex& operator*=(const Complex& rhs);
		Complex  operator/(const Complex& rhs) const;
		Complex& operator/=(const Complex& rhs);

		bool operator==(const Complex&) const;

	private:
		double _re;
		double _im;
	};

static_assert(
		Addable<Complex> && Subtractable<Complex> && Multiplicable<Complex> && Divisible<Complex> && Equatable<Complex>
		&& Absolutable<Complex> && SquareRootable<Complex>);
}

template <>
struct std::formatter<stackixx::Complex> {
	constexpr auto parse(std::format_parse_context& ctx) {
		return ctx.begin();
	}

	auto format(const stackixx::Complex& complex, std::format_context& ctx) const {
		return std::format_to(ctx.out(), "{}{:+}i", complex.re(), complex.im());
	}
};

// template<>
// inline stackixx::Complex stackixx::abs(const Complex& x) {
// 	return x.abs();
// }

#endif // COMPLEX_HPP
