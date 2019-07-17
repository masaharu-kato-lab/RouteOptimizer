#pragma once
#include "Set.h"
#include "Elements.h"
#include "Permutation.h"
#include <utility>
#include <functional>
#include <stdexcept>

namespace ro {

//	複雑な操作を行うことができる順列クラス
	class ElementedPermutation : public Permutation {
	public:
	//	コンストラクタ（すべて未設定で初期化）
		ElementedPermutation(const Elements& elements) noexcept;

	//	コンストラクタ（既存の順列データから初期化）
		ElementedPermutation(const Elements& elements, const Element* _data);

	//	もし index 番目が未設定で value が未使用なら、index 番目に value を設定する
		bool set_if_unused(Index index, Element value);

	//	未設定の index 番目に未使用の value を設定する（index が設定されていたり value が使用されていれば例外を投げる） 
		void set_unused(Index index, Element value);
		
	//	index を未設定にする
		void reset(Index index) noexcept;

	//	すべて未設定にする
		void reset() noexcept;

	//	p と同じ値を持つ場所以外を未設定にする
		void reset_different_indexes(const Element* p);

	//	関数 value_by_index の返す要素に従って、未設定の場所を埋める
		void fill_empties_if_unused(std::function<Element(Index)> value_by_index);

	//	未設定のIndexについて、p1 または p2 のIndexの要素に設定する
	//	関数 rand が true を返せば p1 の要素、 false を返せば p2 の要素を設定する
	//	設定する要素が順列中でに使用済みであればスキップする（何もしない）
		void fill_empties_with_2_permutations(const Element* p1, const Element* p2, std::function<bool()> rand);

	//	未設定のIndexを未使用の値で埋める（未設定のインデックスをシャッフルして返す関数 arrange_indexes を与える）
		void fill_empties_with_unused(std::function<std::vector<Index>(const Set<Index>&)> get_arranged_indexes);
	
	//	直接順列データを変更し、使用した要素・インデックスの記録を反映させる
		void set(const Element* _data);

	//	正しい順列かどうか返す
		bool is_valid() const noexcept;

	private:
		Set<Element> unused_elements;
		Set<Index> empty_indexes;
	};

}