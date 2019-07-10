#pragma once
#include <unordered_set>

namespace base {
	
	template <class Type, class _Base = std::unordered_set<Type>>
	class Set : public _Base {
	private:
		Type default_value;
	
	public:
		using _Base::_Base;

		bool exist(Type value) const noexcept {
			return _Base::count(value);
		}

	};

}