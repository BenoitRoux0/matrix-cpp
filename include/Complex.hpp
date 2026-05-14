#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <format>
#include "Traits.hpp"

// a+bi
class Complex {
public:
	Complex();
	Complex(double a, double b);
	Complex(double a);

	double	getA() const;
	double	getB() const;

	bool	operator==(const Complex&) const;
private:
	double	_a;
	double	_b;
};

template<>
struct std::formatter<Complex> {
	constexpr auto parse(std::format_parse_context& ctx) {
		return ctx.begin();
	}

	auto format(const Complex& complex, std::format_context& ctx) const {
		return std::format_to(ctx.out(), "{}{:+}i", complex.getA(), complex.getB());
	}
};

#endif // COMPLEX_HPP
