#include "InputGenerator.h"
#include <xutility>

using namespace ro::ig;

InputGenerator::InputGenerator(unsigned int seed, size_t sx, size_t sy) :
	mt(seed),
	sx(sx),
	sy(sy),
	data(new DataType[sy * sx]),
	rand_sx(1, sx - 2),
	rand_sy(1, sy - 2)
{}

InputGenerator::~InputGenerator(){
	delete[] data;
}

void InputGenerator::fill(DataType val) noexcept {
	std::fill(data, data + sx * sy, val);
}

auto InputGenerator::get(size_t x, size_t y) const noexcept -> DataType {
	return *getPtr(x, y);
}

void InputGenerator::set(size_t x, size_t y, DataType val) noexcept {
	*getPtr(x, y) = val;
}

void InputGenerator::generate(size_t max_area, size_t n_rects) {
	fill('#');

	for(size_t i = 0; i < n_rects; ++i) {

		size_t bx, by, ex, ey;
		do {
			do {
				bx = rand_sx(mt);
				by = rand_sy(mt);
				ex = rand_sx(mt);
				ey = rand_sy(mt);
			}while(i && get(bx, by) == '#' && get(ex, ey) == '#');

			if(bx > ex) std::swap(bx, ex);
			if(by > ey) std::swap(by, ey);

		}while((ex - bx) * (ey - by) > max_area);

		fill(bx, by, ex, ey, '.');

	}

}

void InputGenerator::fill(size_t bx, size_t by, size_t ex, size_t ey, DataType val) noexcept {
	for(size_t iy = by; iy <= ey; ++iy) {
		std::fill(getPtr(bx, iy), getPtr(ex, iy) + 1, val);
	}
}

auto InputGenerator::getPtr(size_t x, size_t y) const noexcept -> const DataType* {
	return data + (y * sx + x);
}

auto InputGenerator::getPtr(size_t x, size_t y) noexcept -> DataType* {
	return data + (y * sx + x);
}

void InputGenerator::output(std::ostream& os) const noexcept {
	for(size_t iy = 0; iy < sy; ++iy) {
		for(size_t ix = 0; ix < sx; ++ix) {
			os << get(ix, iy);
		}
		os << "\n";
	}
}
