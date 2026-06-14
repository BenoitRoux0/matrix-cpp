#include "Complex.hpp"

namespace stackixx {
	Complex::Complex():
		_re(0), _im(0) {}

	Complex::Complex(double re, double im):
		_re(re), _im(im) {}

	Complex Complex::fromCartesian(double x, double y) {
		return {
				x,
				y
		};
	}

	Complex Complex::fromCartesian(const mat::Vector<double, 2>& vec) {
		return {
				vec[0],
				vec[1]
		};
	}

	Complex Complex::fromPolar(double r, double theta) {
		return {
				r * cos(theta),
				r * sin(theta)
		};
	}

	std::tuple<double, double> Complex::toCartesian() const {
		return {_re, _im};
	}

	std::tuple<double, double> Complex::toPolar() const {
		return {abs(), theta()};
	}

	Complex::Complex(double re):
		_re(re), _im(0) {}

	double Complex::re() const { return _re; }
	double Complex::im() const { return _im; }

	double Complex::abs() const {
		return std::sqrt(_re * _re + _im * _im);
	}

	double Complex::theta() const {
		if (_re > 0) {
			if (_im >= 0) {
				return atan(_im / _re);
			}
			return atan(_im / _re) + 2 * M_PI;
		}
		if (_re < 0) {
			return atan(_im / _re) + M_PI;
		}
		if (_re == 0) {
			if (_im > 0) {
				return M_PI_2;
			}
			if (_im < 0) {
				return 3 * M_PI_2;
			}
		}
		return 0;
	}

	Complex Complex::sqrt() const {
		const auto x = std::sqrt(abs());

		return {
				x * cos(theta() / 2),
				x * sin(theta() / 2)
		};
	}

	Complex Complex::conjugate() const {
		return {
				_re,
				-_im
		};
	}

	Complex Complex::operator+(const Complex& rhs) const {
		return {
				_re + rhs._re,
				_im + rhs._im
		};
	}

	Complex& Complex::operator+=(const Complex& rhs) {
		_re += rhs._re;
		_im += rhs._im;

		return *this;
	}

	Complex Complex::operator-(const Complex& rhs) const {
		return {
				_re - rhs._re,
				_im - rhs._im
		};
	}

	Complex& Complex::operator-=(const Complex& rhs) {
		_re -= rhs._re;
		_im -= rhs._im;

		return *this;
	}

	Complex Complex::operator*(const Complex& rhs) const {
		return {
				_re * rhs._re - _im * rhs._im,
				_re * rhs._im + _im * rhs._re
		};
	}

	Complex& Complex::operator*=(const Complex& rhs) {
		_re = _re * rhs._re - _im * rhs._im;
		_im = _re * rhs._im + _im * rhs._re;

		return *this;
	}

	Complex Complex::operator/(const Complex& rhs) const {
		const double x = rhs._re * rhs._re + rhs._im * rhs._im;

		return {
				(_re * rhs._re + _im * rhs._im) / x,
				(_im * rhs._re - _re * rhs._im) / x
		};
	}

	Complex& Complex::operator/=(const Complex& rhs) {
		const double x = rhs._re * rhs._re + rhs._im * rhs._im;

		_re = (_re * rhs._re + _im * rhs._im) / x;
		_im = (_im * rhs._re - _re * rhs._im) / x;

		return *this;
	}

	bool Complex::operator==(const Complex& rhs) const {
		return _re == rhs._re && _im == rhs._im;
	}
}
