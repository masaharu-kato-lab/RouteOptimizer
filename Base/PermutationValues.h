#pragma once
#include "Set.h"
#include <numeric>

namespace ro {
	
//	順列に使用する値の集合を表現するクラス
	template <class Type>
	class PermutationValues : public Set<Type> {
	protected:
		using _Base = Set<Type>;

	public:
		using Index = size_t;

	private:
	//	既定値
		Type default_value;
	
	public:
	//	コンストラクタ
		PermutationValues(const _Base& values, Type default_value) noexcept
			: _Base(values), default_value(default_value) {}

	//	インデックスの集合を取得
		Set<Index> getIndexes() const noexcept {
			Set<Index> ret;
			for(Index i = 0; i < _Base::size(); ++i) {
				ret.insert(i);
			}
			return ret;
		};

	//	値の集合を取得
		const Set<Type>& getValues() const noexcept {
			return *this;
		}

	//	既定値を取得
		Type getDefault() const noexcept {
			return default_value;
		}

	//	既定値に設定
		void setDefault(Type& target) noexcept {
			target = default_value;
		}

	//	既定値かどうか返す
		bool isDefault(Type value) const noexcept {
			return value == default_value;
		}

	//	配列かどうか返す（このクラスでは常にfalse）
		virtual bool isArray() const noexcept {
			return false;
		}

	};

}