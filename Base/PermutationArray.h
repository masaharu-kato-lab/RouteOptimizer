#pragma once
#include "Elements.h"
#include "Permutation.h"
#include "ElementedPermutation.h"
#include <memory>
#include <functional>

namespace ro {

//	順列の配列クラス
	class PermutationArray {
	public:	
		using Index = uint_fast32_t;
		using Element = PermutationElement;

		PermutationArray(std::shared_ptr<const Elements> elements, Index n_data) noexcept;
		PermutationArray(const PermutationArray&) noexcept;
		~PermutationArray();

	//	順列の数を取得
		Index size() const noexcept;

	//	1順列のサイズを取得
		PermutationIndex permutation_size() const noexcept;

		const Element* getRaw(Index index) const noexcept;				//	生データを取得
		Permutation get(Index index) const noexcept;					//	順列オブジェクトを取得
		Permutation operator [](Index index) const noexcept;			//	順列オブジェクトを取得
		ElementedPermutation getElemented(Index index) const noexcept;	//	要素付き順列オブジェクトを取得

	//	順列を設定
		void set(Index index, const Permutation perm) noexcept;

	//	すべての順列を変更する
		void set_all(std::function<Permutation(Index)> generate_perm) noexcept;

	//	順列が変更されたときに呼ばれる関数（既定では何もしない）
		virtual void onchange(Index index) noexcept;

	private:
		std::shared_ptr<const Elements> elements;	//	要素集合
		Index n_data;	//	データ数
		Element* data;	//	順列データ

		//	index 番目の順列データの先頭ポインタを取得
		Element* getElementPtr(Index index) const noexcept;

		//	データ数（順列の数×1順列のサイズ）を取得
		size_t data_size() const noexcept;
	
	};

}