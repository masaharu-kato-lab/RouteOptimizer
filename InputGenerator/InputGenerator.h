#pragma once
#include <random>
#include <ostream>

namespace ro::ig {

	class InputGenerator {
	public:
		using DataType = char;

		InputGenerator(unsigned int seed, size_t sx, size_t sy);
		~InputGenerator() noexcept;
	
		void generate(size_t max_area, size_t n_rects);
		void output(std::ostream& os) const noexcept;

	private:
		DataType get(size_t x, size_t y) const noexcept;
		void set(size_t x, size_t y, DataType val) noexcept;

		const DataType* getPtr(size_t x, size_t y) const noexcept;
		DataType* getPtr(size_t x, size_t y) noexcept;

		void fill(DataType val) noexcept;
		void fill(size_t bx, size_t by, size_t ex, size_t ey, DataType val) noexcept;

		std::mt19937 mt;
		size_t sx;
		size_t sy;
		DataType* data;
	
		std::uniform_int_distribution<size_t> rand_sx;
		std::uniform_int_distribution<size_t> rand_sy;

	};

}