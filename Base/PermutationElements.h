#pragma once
#include "PermutationTypes.h"
#include "Set.h"
#include <numeric>

namespace ro {

	class PermutationElements : public Set<PermutationElement> {
	protected:
		using _Base = Set<PermutationElement>;	//	基底型（要素の集合）
		using Element = PermutationElement;		//	要素型
		using Index = PermutationIndex;			//	インデックス型
	
	public:
		constexpr static Element DEFAULT_ELEMENT = PERMUTATION_ELEMENT_DEFAULT;	//	既定値

	//	コンストラクタ
		PermutationElements(const _Base& values) noexcept;

	//	インデックスの集合を取得
		Set<Index> getIndexes() const noexcept;

	//	要素の集合を取得
		const _Base& getElements() const noexcept;

	////	既定値を取得
	//	Element getDefault() const noexcept;

	////	既定値に設定
	//	void setDefault(Element& target) noexcept;

	////	既定値かどうか返す
	//	bool isDefault(Element value) const noexcept;

	////	配列かどうか返す（このクラスでは常にfalse）
	//	virtual bool isArray() const noexcept;

	};

}