#ifndef LERP_TPP
#define LERP_TPP
#include <cmath>

namespace stackixx {
	template <typename T, typename S>
	T lerp(const T& v, const T& u, S t) {
		if constexpr (std::is_arithmetic_v<T>)
			return std::fma(t, u - v, v);
		else
			return t * (u - v) + v;
	}
}

#endif // LERP_TPP
