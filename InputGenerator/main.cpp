#include <iostream>
#include <vector>
#include <random>
#include <utility>

using DataType = char;

void generate(size_t sx, size_t sy, size_t max_area, size_t n_rects, std::mt19937& mt) {
	DataType** data = new DataType*[sy];

	for(size_t iy = 0; iy < sy; ++iy) {
		data[iy] = new DataType[sx];
		for(size_t ix = 0; ix < sx; ++ix) {
			data[iy][ix] = '#';
		}
	}

	std::uniform_int_distribution<size_t> rand_sx(1, sx - 2);
	std::uniform_int_distribution<size_t> rand_sy(1, sy - 2);

	for(size_t i = 0; i < n_rects; ++i) {

		size_t bx, by, ex, ey;
		do {
			do {
				bx = rand_sx(mt);
				by = rand_sy(mt);
				ex = rand_sx(mt);
				ey = rand_sy(mt);
			}while(i && data[by][bx] == '#' && data[ey][ex] == '#');

			if(bx > ex) std::swap(bx, ex);
			if(by > ey) std::swap(by, ey);

		}while((ex - bx) * (ey - by) > max_area);

		for(size_t iy = by; iy <= ey; ++iy) {
			for(size_t ix = bx; ix <= ex; ++ix) {
				data[iy][ix] = '.';
			}
		}

	}

	for(size_t iy = 0; iy < sy; ++iy) {
		for(size_t ix = 0; ix < sx; ++ix) {
			std::cout << data[iy][ix];
		}
		std::cout << "\n";
	}
	
	for(size_t iy = 0; iy < sy; ++iy) delete[] data[iy];
	delete[] data;

}

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
