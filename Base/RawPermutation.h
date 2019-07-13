#pragma once
#include "PermutationTypes.h"
#include <vector>

namespace ro {

//	生の順列データを保持するクラス
	class RawPermutation {
	public:
		using Element = PermutationElement;
		using Index = PermutationIndex;

	//	コンストラクタ
		RawPermutation(Element*) noexcept;


	//	index 番目の値を取得する
		Element get(Index index) const noexcept;

	//	index 番目の値を取得
		Element operator [](Index index) const noexcept;
		
	//	index 番目の変更可能な値を取得する
		Element& get(Index index) noexcept;

	//	index 番目の変更可能な値を取得する
		Element& operator [](Index index) noexcept;

	//	index 番目が設定されているか返す
		bool isset(Index index) const;

	//	直接（順列としての整合性を確認せずに）値を設定する
		void set_directly(Index index, Element value)  noexcept;

	//	index 番目を未設定にする
		void reset(Index index) noexcept;

	//	index1 と index2 を入れ替える
		void swap(Index index1, Index index2);

	protected:
		Element* element;
	};

}