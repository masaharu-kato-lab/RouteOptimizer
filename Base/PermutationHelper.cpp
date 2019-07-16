#include "PermutationHelper.h"
using namespace ro;

//	�R���X�g���N�^�i���ׂĖ��ݒ�ŏ������j
PermutationHelper::PermutationHelper(const std::shared_ptr<const PermutationElements>& origin) noexcept
	: PermutationHelper(Permutation(origin))
{}

//	�R���X�g���N�^�i�����̔z�񂩂珉�����j
PermutationHelper::PermutationHelper(const std::shared_ptr<const PermutationElements>& origin, Element* target_ptr) noexcept
	: PermutationHelper(Permutation(origin, target_ptr))
{}
		
//	�R���X�g���N�^�i����N���X�ŏ������j
PermutationHelper::PermutationHelper(const Permutation& p) noexcept :
	Permutation(p),
	unused_elements(origin->getElements()),
	empty_indexes(origin->getIndexes())
{}

//	���� index �Ԗڂ����ݒ�� value �����g�p�Ȃ�Aindex �Ԗڂ� value ��ݒ肷��
//	�ݒ肳�ꂽ�ꍇ true, ����Ȃ������ꍇ false ��Ԃ�
bool PermutationHelper::set_if_unused(Index index, Element value) {
	if(isset(index) || !unused_elements.exist(value)) return false; 
	get(index) = value;
	empty_indexes.erase(index);
	unused_elements.erase(value);
}

//	���ݒ�� index �Ԗڂɖ��g�p�� value ��ݒ肷��iindex ���ݒ肳��Ă����� value ���g�p����Ă���Η�O�𓊂���j 
void PermutationHelper::set_unused(Index index, Element value) {
	if(!set_if_unused(index, value)) throw std::runtime_error("Invalid index or value.");
}

//	p �Ɠ����l�����ꏊ�ȊO�𖢐ݒ�ɂ���
void PermutationHelper::reset_different_indexes(const RawPermutation& p) {
	for(Index index = 0; index < size(); ++index) {
		if(get(index) != p[index]) reset(index);
	}
}

//	�֐� value_by_index �̕Ԃ��l�ɏ]���āA���ݒ�̏ꏊ�𖄂߂�
void PermutationHelper::fill_empties_if_unused(std::function<Element(Index)> value_by_index) {
	for(Index index : empty_indexes) {
		set_if_unused(index, value_by_index(index));
	}
}

//	���ݒ��Index�ɂ��āAp1 �܂��� p2 ��Index�̗v�f�ɐݒ肷��
void PermutationHelper::fill_empties_with_2_permutations(const RawPermutation& p1, const RawPermutation& p2, std::function<bool()> rand) {
	return fill_empties_if_unused([&](Index index) -> Element {
		return rand() ? p1[index] : p2[index];
	});
}

//	���ݒ�̏ꏊ�𖢎g�p�̒l�Ŗ��߂�i���ݒ�̏ꏊ���V���b�t�����ĕԂ��֐� arrange_indexes ��^����j
void PermutationHelper::fill_empties_with_unused(std::function<std::vector<Index>(const Set<Index>&)> get_arranged_indexes) {
	std::vector<Index> arranged_indexes = get_arranged_indexes(empty_indexes);
	for(Index index : arranged_indexes) {
		set_unused(index, *unused_elements.begin());
	}
	if(unused_elements.size() || empty_indexes.size()) throw std::runtime_error("Invalid permutation.");
}
