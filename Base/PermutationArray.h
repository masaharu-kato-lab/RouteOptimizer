#pragma once
#include "PermutationElements.h"
#include "Permutation.h"
#include "PermutationHelper.h"
#include <memory>

namespace ro {

//	順列に使用する値の集合を表現し、順列の配列を保持するクラス
	class PermutationArray : /* public PermutationElements, */ public std::enable_shared_from_this<PermutationArray> {
	public:	
		using Index = uint_fast32_t;
		using Element = PermutationElement;

		PermutationArray(std::shared_ptr<const PermutationElements> origin, Index n_data) noexcept;
		PermutationArray(const PermutationArray&) noexcept;
		~PermutationArray();

	//	順列の数を取得
		Index size() const noexcept;

	//	1順列のサイズを取得
		PermutationIndex permutation_size() const noexcept;

		RawPermutation getRaw(Index index) const noexcept;	
			
		Permutation get(Index index) const noexcept;
		Permutation operator [](Index index) const noexcept;

		PermutationHelper getHelper(Index index) const noexcept;

		//	bool isArray() const noexcept override;

	private:
		std::shared_ptr<const PermutationElements> origin;	//	要素データ
		Index n_data;	//	データ数
		Element* data;	//	順列データ

		//	index 番目の順列データの先頭ポインタを取得
		Element* getElementPtr(Index index) const noexcept;

		//	データ数（順列の数×1順列のサイズ）を取得
		size_t data_size() const noexcept;
	
	};

}