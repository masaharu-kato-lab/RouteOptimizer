#pragma once
#include "PermutationValues.h"

namespace ro {

//	順列に使用する値の集合を表現し、順列の配列を保持するクラス
	template <class Type>
	class PermutationArray : public PermutationValues<Type> {
	private:
		using _Base = PermutationValues<Type>;
		using Index = _Base::Index;

		Index n_data;	//	データ数
		Type* data;		//	順列データ

	public:
	//	コンストラクタ
		PermutationArray(const _Base::_Base& values, Type default_value, Index n_data) noexcept :
			_Base(values, default_value),
			n_data(n_data),
			data(new Type[values.size() * n_data])
		{}

	//	index 番目の順列データを取得
		Type* operator [](Index index) noexcept {
			return data + _Base::size() * index;
		}

	//	
		
	//	配列かどうか返す（このクラスでは常にtrue)
		bool isArray() const noexcept override {
			return true;
		}

	};

}