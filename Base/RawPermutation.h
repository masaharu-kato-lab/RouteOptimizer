#pragma once
#include "PermutationTypes.h"
#include <vector>

namespace ro {

//	生の順列データを保持するクラス
	class RawPermutation {
	public:
		using Element = PermutationElement;
		using Index = PermutationIndex;

		RawPermutation(Element*) noexcept;

	//	index の要素を取得する
		Element get(Index index) const noexcept;

	//	index の要素を取得
		Element operator [](Index index) const noexcept;
		
	//	index の変更可能な要素を取得する
		Element& get(Index index) noexcept;

	//	index の変更可能な要素を取得する
		Element& operator [](Index index) noexcept;

	//	index が設定されているか返す
		bool isset(Index index) const;

	//	直接（順列としての整合性を確認せずに）要素を設定する
		void set_directly(Index index, Element value)  noexcept;

	//	index を未設定にする
		void reset(Index index) noexcept;

	//	index1 と index2 の要素を入れ替える
		void swap(Index index1, Index index2);

	protected:
		Element* element;
	};

}