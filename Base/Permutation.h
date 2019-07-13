#pragma once
#include "RawPermutation.h"
#include "PermutationElements.h"
#include <memory>

namespace ro {

//	順列の要素情報を持つ、編集可能な順列クラス
	class Permutation : public RawPermutation {
	public:
	//	順列を構成する要素の数を取得する
		Index size() const noexcept;
		
	//	コンストラクタ（すべて未設定で初期化）
		Permutation(const std::shared_ptr<const PermutationElements>& origin) noexcept;
		
	//	コンストラクタ（既存の配列から初期化）
		Permutation(const std::shared_ptr<const PermutationElements>& origin, Element* target_ptr) noexcept;

		~Permutation();

		using RawPermutation::reset;

	//	すべて未設定にする
		void reset() noexcept;

	//	直接（順列としての整合性を確認せずに）値を設定する
	//	index が範囲外の場合は例外を投げる
		void set_directly(Index index, Element value);
		
	//	順列としての整合性を確認する
		bool isValid() const noexcept;


	//	生の順列データを取得する
		RawPermutation getRaw() const noexcept;

	//	ヘルパーを取得する
		PermutationHelper getHelper() const noexcept;

	protected:
		std::shared_ptr<const PermutationElements> origin;
		
	};

}