#include "ElementedPermutation.h"
using namespace ro;

//	コンストラクタ（すべて未設定で初期化）
ElementedPermutation::ElementedPermutation(const Elements& elements) noexcept :
	Permutation(elements.size()),
	unused_elements(elements.getElements()),
	empty_indexes(elements.getIndexes())
{}

//	コンストラクタ（既存の順列データから初期化）
ElementedPermutation::ElementedPermutation(const Elements& elements, const Element* _data) :
	ElementedPermutation(elements)
{
	set(_data);
}

//	もし index 番目が未設定で value が未使用なら、index 番目に value を設定する
//	設定された場合 true, されなかった場合 false を返す
bool ElementedPermutation::set_if_unused(Index index, Element value) {
	if(isset(index) || !unused_elements.exist(value)) return false; 
	get(index) = value;
	empty_indexes.erase(index);
	unused_elements.erase(value);
}

//	未設定の index 番目に未使用の value を設定する（index が設定されていたり value が使用されていれば例外を投げる） 
void ElementedPermutation::set_unused(Index index, Element value) {
	if(!set_if_unused(index, value)) throw std::runtime_error("Invalid index or value.");
}
		
//	index を未設定にする
void ElementedPermutation::reset(Index index) noexcept {
	unused_elements.insert(get(index));
	empty_indexes.insert(index);
	Permutation::reset(index);
}

//	すべて未設定にする
void ElementedPermutation::reset() noexcept {
	for(Index index = 0; index < size(); ++index) reset(index);
}

//	p と同じ値を持つ場所以外を未設定にする
void ElementedPermutation::reset_different_indexes(const Element* p) {
	for(Index index = 0; index < size(); ++index) {
		if(get(index) != p[index]) reset(index);
	}
}

//	関数 value_by_index の返す値に従って、未設定の場所を埋める
void ElementedPermutation::fill_empties_if_unused(std::function<Element(Index)> value_by_index) {
	for(Index index : empty_indexes) {
		set_if_unused(index, value_by_index(index));
	}
}

//	未設定のIndexについて、p1 または p2 のIndexの要素に設定する
void ElementedPermutation::fill_empties_with_2_permutations(const Element* p1, const Element* p2, std::function<bool()> rand) {
	return fill_empties_if_unused([&](Index index) -> Element {
		return rand() ? p1[index] : p2[index];
	});
}

//	未設定の場所を未使用の値で埋める（未設定の場所をシャッフルして返す関数 arrange_indexes を与える）
void ElementedPermutation::fill_empties_with_unused(std::function<std::vector<Index>(const Set<Index>&)> get_arranged_indexes) {
	std::vector<Index> arranged_indexes = get_arranged_indexes(empty_indexes);
	for(Index index : arranged_indexes) {
		set_unused(index, *unused_elements.begin());
	}
	if(unused_elements.size() || empty_indexes.size()) throw std::runtime_error("Invalid permutation.");
}

//	直接順列データを変更し、使用した要素・インデックスの記録を反映させる
void ElementedPermutation::set(const Element* _data) {
	for(Index index = 0; index < size(); ++index) {
		set_unused(index, _data[index]);
	}
}

//	正しい順列かどうか返す
bool ElementedPermutation::is_valid() const noexcept {
	return !unused_elements.size() && !empty_indexes.size();
}
