#include "Complex.hpp"

Complex::Complex():
	_a(0), _b(0) {}

Complex::Complex(double a, double b):
	_a(a), _b(b) {}

Complex::Complex(double a):
	_a(a), _b(0) {}

double Complex::getA() const { return _a; }

double Complex::getB() const { return _b; }

bool Complex::operator==(const Complex& rhs) const {
	return _a == rhs._a && _b == rhs._b;
}
