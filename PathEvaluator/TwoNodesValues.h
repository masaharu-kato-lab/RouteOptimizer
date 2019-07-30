#pragma once
#include <vector>
#include <memory>
#include <limits>

namespace ro::pe {

	class TwoNodesValues {
	public:
		using Value = double;
		using Index = size_t;
		constexpr static Value default_value = std::numeric_limits<float>::quiet_NaN();

		TwoNodesValues(Index n);

		void set(Index i1, Index i2, Value val) noexcept;
		void get(Index i1, Index i2) const noexcept;

		void calc_value(Index i1, Index i2) noexcept;


	private:
		std::unique_ptr<Value[]> values;

		Index value_size() const noexcept;

	};

}
