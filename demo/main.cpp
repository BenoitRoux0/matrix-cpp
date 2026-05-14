#include <print>
#include "Complex.hpp"

int	main() {
	Complex complexA(5./3., -10);
	Complex complexB(5./3., -10);

	std::print("{}\n", complexA != complexB);
}
