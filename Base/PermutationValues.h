#pragma once
#include "Set.h"
#include <numeric>

namespace base {
	
	template <class Type, class _Base = Set<Type>>
	class PermutationValues : public _Base {
	private:
		Type default_value;
	
	public:
		PermutationValues(const _Base& values, Type default_value) noexcept
			: _Base(values), default_value(default_value) {}

		Set<size_t> getIndexes() const noexcept {
			Set<size_t> ret;
			std::iota(ret.begin(), ret.end(), 0);
			return ret;
		};

		Type getDefault() const noexcept {
			return default_value;
		}

		bool isDefault(Type value) const {
			return value == default_value;
		}

		virtual bool isArray() const {
			return false;
		}
	};

}