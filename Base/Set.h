#pragma once
#include <unordered_set>

namespace ro {
	
	template <class Type, class _Base = std::unordered_set<Type>>
	class Set : public _Base {
	private:
		Type default_value;
	
	public:
		using _Base::_Base;

	//	íl value Ç™ë∂ç›Ç∑ÇÈÇ©ï‘Ç∑
		bool exist(Type value) const noexcept {
			return (bool)_Base::count(value);
		}

	};

}