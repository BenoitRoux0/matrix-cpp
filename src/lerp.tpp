#ifndef LERP_TPP
#define LERP_TPP

template<typename T>
T lerp(const T& v, const T& u, float t) {
	return v + t * (u - v);
}

#endif // LERP_TPP
