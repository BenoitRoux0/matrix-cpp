#include <print>
#include "Complex.hpp"
#include "Misc.hpp"

int main() {
	auto mat = stackixx::projection(90, 1, 1, 50);

	if (mat.has_value()) {
		std::println("{}", *mat);
	}

}
