#pragma once
#include "PermutationTypes.h"
#include <vector>

namespace ro {

//	既存の変更不可能な順列データを保持するクラス
	class ConstPermutation {
	public:
		using Element = PermutationElement;
		using Index = PermutationIndex;

	//	コンストラクタ
		ConstPermutation(Element*) noexcept;


	//	index 番目の値を取得する
		Element get(Index index) const noexcept;

	//	index 番目の値を取得
		Element operator [](Index index) const noexcept;

	//	index 番目が設定されているか返す
		bool isset(Index index) const;

	protected:
		Element* element;
	};

}