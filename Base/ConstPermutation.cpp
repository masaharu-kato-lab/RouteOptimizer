#include "ConstPermutation.h"
using namespace ro;

ConstPermutation::ConstPermutation(Element* element)
	: element(element) {}

//	�l���擾����
auto ConstPermutation::get(Index index) const noexcept -> Element {
	return element[index];
}

//	�l���擾����
auto ConstPermutation::operator [](Index index) const noexcept -> Element {
	return element[index];
}

//	index �Ԗڂ��ݒ肳��Ă��邩�Ԃ�
bool ConstPermutation::isset(Index index) const {
	return get(index) == PERMUTATION_ELEMENT_DEFAULT;
}