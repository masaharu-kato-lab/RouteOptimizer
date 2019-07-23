#pragma once
#include <random>
#include <ostream>

class InputGenerator {
public:
	using DataType = char;

	InputGenerator(std::ostream& os, unsigned int seed, size_t sx, size_t sy);
	~InputGenerator() noexcept;
	
	void generate(size_t sx, size_t sy, size_t max_area, size_t n_rects);
	void output() const noexcept;

private:
	DataType get(size_t x, size_t y) const noexcept;
	void set(size_t x, size_t y, DataType val) noexcept;

	void fill(DataType val) noexcept;
	void fill(size_t bx, size_t by, size_t ex, size_t ey, DataType val) noexcept;

	std::ostream& os;
	std::mt19937 mt;
	size_t sx;
	size_t sy;
	DataType* data;

};