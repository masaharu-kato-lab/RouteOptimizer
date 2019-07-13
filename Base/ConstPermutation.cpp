#include "ConstPermutation.h"
using namespace ro;

ConstPermutation::ConstPermutation(Element* element)
	: element(element) {}

//	値を取得する
auto ConstPermutation::get(Index index) const noexcept -> Element {
	return element[index];
}

//	値を取得する
auto ConstPermutation::operator [](Index index) const noexcept -> Element {
	return element[index];
}

//	index 番目が設定されているか返す
bool ConstPermutation::isset(Index index) const {
	return get(index) == PERMUTATION_ELEMENT_DEFAULT;
}