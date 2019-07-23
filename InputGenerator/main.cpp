#include <iostream>
#include <vector>
#include <utility>

int main(void) {
	
	
	unsigned int seed;
	std::cin >> seed;
	
	std::mt19937 mt(seed);

	while(true) {
		size_t sx, sy, max_area, n_rects;
		std::cin >> sx >> sy >> max_area >> n_rects;
		generate(sx, sy, max_area, n_rects, mt);
	}

	return 0;
}
