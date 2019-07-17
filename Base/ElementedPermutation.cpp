#include "ElementedPermutation.h"
using namespace ro;

//	�R���X�g���N�^�i���ׂĖ��ݒ�ŏ������j
ElementedPermutation::ElementedPermutation(const Elements& elements) noexcept :
	Permutation(elements.size()),
	unused_elements(elements.getElements()),
	empty_indexes(elements.getIndexes())
{}

//	�R���X�g���N�^�i�����̏���f�[�^���珉�����j
ElementedPermutation::ElementedPermutation(const Elements& elements, const Element* _data) :
	ElementedPermutation(elements)
{
	set(_data);
}

//	���� index �Ԗڂ����ݒ�� value �����g�p�Ȃ�Aindex �Ԗڂ� value ��ݒ肷��
//	�ݒ肳�ꂽ�ꍇ true, ����Ȃ������ꍇ false ��Ԃ�
bool ElementedPermutation::set_if_unused(Index index, Element value) {
	if(isset(index) || !unused_elements.exist(value)) return false; 
	get(index) = value;
	empty_indexes.erase(index);
	unused_elements.erase(value);
}

//	���ݒ�� index �Ԗڂɖ��g�p�� value ��ݒ肷��iindex ���ݒ肳��Ă����� value ���g�p����Ă���Η�O�𓊂���j 
void ElementedPermutation::set_unused(Index index, Element value) {
	if(!set_if_unused(index, value)) throw std::runtime_error("Invalid index or value.");
}
		
//	index �𖢐ݒ�ɂ���
void ElementedPermutation::reset(Index index) noexcept {
	unused_elements.insert(get(index));
	empty_indexes.insert(index);
	Permutation::reset(index);
}

//	���ׂĖ��ݒ�ɂ���
void ElementedPermutation::reset() noexcept {
	for(Index index = 0; index < size(); ++index) reset(index);
}

//	p �Ɠ����l�����ꏊ�ȊO�𖢐ݒ�ɂ���
void ElementedPermutation::reset_different_indexes(const Element* p) {
	for(Index index = 0; index < size(); ++index) {
		if(get(index) != p[index]) reset(index);
	}
}

//	�֐� value_by_index �̕Ԃ��l�ɏ]���āA���ݒ�̏ꏊ�𖄂߂�
void ElementedPermutation::fill_empties_if_unused(std::function<Element(Index)> value_by_index) {
	for(Index index : empty_indexes) {
		set_if_unused(index, value_by_index(index));
	}
}

//	���ݒ��Index�ɂ��āAp1 �܂��� p2 ��Index�̗v�f�ɐݒ肷��
void ElementedPermutation::fill_empties_with_2_permutations(const Element* p1, const Element* p2, std::function<bool()> rand) {
	return fill_empties_if_unused([&](Index index) -> Element {
		return rand() ? p1[index] : p2[index];
	});
}

//	���ݒ�̏ꏊ�𖢎g�p�̒l�Ŗ��߂�i���ݒ�̏ꏊ���V���b�t�����ĕԂ��֐� arrange_indexes ��^����j
void ElementedPermutation::fill_empties_with_unused(std::function<std::vector<Index>(const Set<Index>&)> get_arranged_indexes) {
	std::vector<Index> arranged_indexes = get_arranged_indexes(empty_indexes);
	for(Index index : arranged_indexes) {
		set_unused(index, *unused_elements.begin());
	}
	if(unused_elements.size() || empty_indexes.size()) throw std::runtime_error("Invalid permutation.");
}

//	���ڏ���f�[�^��ύX���A�g�p�����v�f�E�C���f�b�N�X�̋L�^�𔽉f������
void ElementedPermutation::set(const Element* _data) {
	for(Index index = 0; index < size(); ++index) {
		set_unused(index, _data[index]);
	}
}

//	���������񂩂ǂ����Ԃ�
bool ElementedPermutation::is_valid() const noexcept {
	return !unused_elements.size() && !empty_indexes.size();
}
