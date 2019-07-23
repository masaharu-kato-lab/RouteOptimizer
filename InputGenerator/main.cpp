#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include "InputGenerator.h"
#include <fmt/format.h>

using namespace ro::ig;

int main(void) {
	
	unsigned int seed;
	size_t sx, sy, max_area, n_rects, n_input;
	std::cin >> seed >> sx >> sy >> max_area >> n_rects >> n_input;
	InputGenerator generator(seed, sx, sy);

	for(size_t i = 0; i < n_input; ++i) {
		generator.generate(max_area, n_rects);
		std::ofstream ofs(fmt::format("out/input{:04d}.txt", i));
		generator.output(ofs);
		std::cout << '.';
	}
	std::cout << '\n';

	return 0;
}
