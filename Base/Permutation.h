#pragma once
#include "ConstPermutation.h"
#include "PermutationElements.h"
#include <memory>

namespace ro {

//	順列の要素情報を持つ、編集可能な順列クラス
	class Permutation : public ConstPermutation {
	public:		
	//	index 番目の変更可能な値を取得する
		Element& get(Index index) noexcept;

	//	index 番目の変更可能な値を取得する
		Element& operator [](Index index) noexcept;

	//	順列を構成する要素の数を取得する
		Index size() const noexcept;
		
	//	コンストラクタ（すべて未設定で初期化）
		Permutation(const std::shared_ptr<PermutationElements>& origin) noexcept;
		
	//	コンストラクタ（既存の配列から初期化）
		Permutation(const std::shared_ptr<PermutationElements>& origin, Element* target_ptr) noexcept;

	//	デストラクタ
		~Permutation();

	//	順列としての整合性を確認する
		bool isValid() const noexcept;

	//	直接（順列としての整合性を確認せずに）値を設定する
		void set_directly(Index index, Element value)  noexcept;

	//	index 番目を未設定にする
		void reset(Index index) noexcept;

	//	すべて未設定にする
		void reset() noexcept;

	//	index1 と index2 を入れ替える
		void swap(Index index1, Index index2);

	protected:
		std::shared_ptr<PermutationElements> origin;
		
	};

}