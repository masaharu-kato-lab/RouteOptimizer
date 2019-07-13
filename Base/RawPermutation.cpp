#include "RawPermutation.h"
using namespace ro;

RawPermutation::RawPermutation(Element* element)
	: element(element) {}

//	値を取得する
auto RawPermutation::get(Index index) const noexcept -> Element {
	return element[index];
}

//	値を取得する
auto RawPermutation::operator [](Index index) const noexcept -> Element {
	return element[index];
}

//	index 番目が設定されているか返す
bool RawPermutation::isset(Index index) const {
	return get(index) == PERMUTATION_ELEMENT_DEFAULT;
}

//	変更可能な値を取得する
auto RawPermutation::get(Index index) noexcept -> Element& {
	return element[index];
}

//	変更可能な値を取得する
auto RawPermutation::operator [](Index index) noexcept -> Element& {
	return element[index];
}

//	直接（順列としての整合性を確認せずに）値を設定する
void RawPermutation::set_directly(Index index, Element value)  noexcept {
	get(index) = value;
}

//	index 番目を未設定にする
void RawPermutation::reset(Index index) noexcept {
	get(index) = PERMUTATION_ELEMENT_DEFAULT;
}

//	index1 と index2 を入れ替える
void RawPermutation::swap(Index index1, Index index2) {
	std::swap(get(index1), get(index2));
}
