#include "RawPermutation.h"
using namespace ro;

RawPermutation::RawPermutation(Element* element)
	: element(element) {}

//	�l���擾����
auto RawPermutation::get(Index index) const noexcept -> Element {
	return element[index];
}

//	�l���擾����
auto RawPermutation::operator [](Index index) const noexcept -> Element {
	return element[index];
}

//	index �Ԗڂ��ݒ肳��Ă��邩�Ԃ�
bool RawPermutation::isset(Index index) const {
	return get(index) == PERMUTATION_ELEMENT_DEFAULT;
}

//	�ύX�\�Ȓl���擾����
auto RawPermutation::get(Index index) noexcept -> Element& {
	return element[index];
}

//	�ύX�\�Ȓl���擾����
auto RawPermutation::operator [](Index index) noexcept -> Element& {
	return element[index];
}

//	���ځi����Ƃ��Ă̐��������m�F�����Ɂj�l��ݒ肷��
void RawPermutation::set_directly(Index index, Element value)  noexcept {
	get(index) = value;
}

//	index �Ԗڂ𖢐ݒ�ɂ���
void RawPermutation::reset(Index index) noexcept {
	get(index) = PERMUTATION_ELEMENT_DEFAULT;
}

//	index1 �� index2 �����ւ���
void RawPermutation::swap(Index index1, Index index2) {
	std::swap(get(index1), get(index2));
}
