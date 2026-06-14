#ifndef ABS_TPP
#define ABS_TPP

namespace stackixx {
	template <typename T>
	T abs(const T& x) {
		if (x > 0)
			return x;

		return -x;
	}
}

#endif // ABS_TPP
