#pragma once
#include "Permutation.h"
#include <utility>
#include <functional>
#include <stdexcept>

namespace ro {

	class PermutationHelper : public Permutation {
	public:
	//	コンストラクタ（すべて未設定で初期化）
		PermutationHelper(const std::shared_ptr<PermutationElements>& origin) noexcept;
		
	//	コンストラクタ（既存の配列から初期化）
		PermutationHelper(const std::shared_ptr<PermutationElements>& origin, Element* target_ptr) noexcept;

	//	コンストラクタ（順列クラスで初期化）
		PermutationHelper(const Permutation&) noexcept;

	//	もし index 番目が未設定で value が未使用なら、index 番目に value を設定する
		bool set_if_unused(Index index, Element value);

	//	未設定の index 番目に未使用の value を設定する（index が設定されていたり value が使用されていれば例外を投げる） 
		void set_unused(Index index, Element value);

	//	p と同じ値を持つ場所以外を未設定にする
		void reset_different_indexes(const ConstPermutation& p);

	//	関数 value_by_index の返す要素に従って、未設定の場所を埋める
		void fill_empties_if_unused(std::function<Element(Index)> value_by_index);

	//	未設定のIndexについて、p1 または p2 のIndexの要素に設定する
	//	関数 rand が true を返せば p1 の要素、 false を返せば p2 の要素を設定する
	//	設定する要素が順列中でに使用済みであればスキップする（何もしない）
		void fill_empties_with_2_permutations(const ConstPermutation& p1, const ConstPermutation& p2, std::function<bool()> rand);

	//	未設定のIndexを未使用の値で埋める（未設定のインデックスをシャッフルして返す関数 arrange_indexes を与える）
		void fill_empties_with_unused(std::function<std::vector<Index>(const Set<Index>&)> get_arranged_indexes);
	
	private:
		Set<Element> unused_elements;
		Set<Index> empty_indexes;
	};

}