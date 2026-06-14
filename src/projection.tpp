#ifndef PROJECTION_TPP
#define PROJECTION_TPP

#include <cstddef>
#include <math.h>
#include <optional>

namespace stackixx {
	std::optional<mat::Matrix<double, 4>> projection(
			double fov, double ratio, double near, double far) {
		const double radAngle = M_PI * fov / 180;

		if (near >= far || fov >= 180 || fov <= 0 || ratio <= 0 || near < 0 || far < 0) {
			return {};
		}

		double source[4][4] = {
				{1 / (ratio * std::tan(radAngle / 2)), 0, 0, 0},
				{0, 1 / std::tan(radAngle / 2), 0, 0},
				{0, 0, (near + far) / (near - far), 2 * near * far / (near - far)},
				{0, 0, -1, 0}
		};

		return mat::Matrix(source).transpose();
	}
}

#endif // PROJECTION_TPP
