#pragma once
#include "PermutationTypes.h"
#include "Set.h"
#include <numeric>

namespace ro {

//	順列に含まれる要素を保持するクラス
	class Elements : public Set<PermutationElement> {
	protected:
		using _Base = Set<PermutationElement>;	//	基底型（要素の集合）
		using Element = PermutationElement;		//	要素型
		using Index = PermutationIndex;			//	インデックス型
	
	public:
		constexpr static Element DEFAULT_ELEMENT = PERMUTATION_ELEMENT_DEFAULT;	//	既定値

	//	コンストラクタ
		Elements(const _Base& values) noexcept;

	//	インデックスの集合を取得
		Set<Index> getIndexes() const noexcept;

	//	要素の集合を取得
		const _Base& getElements() const noexcept;

	};

}