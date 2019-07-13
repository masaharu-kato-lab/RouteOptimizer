#include "PermutationElements.h"
using namespace ro;

//	�R���X�g���N�^
PermutationElements::PermutationElements(const _Base& values) noexcept
	: _Base(values) {}

//	�C���f�b�N�X�̏W�����擾
auto PermutationElements::getIndexes() const noexcept -> Set<Index> {
	Set<Index> ret;
	for(Index i = 0; i < _Base::size(); ++i) {
		ret.insert(i);
	}
	return ret;
};

//	�l�̏W�����擾
auto PermutationElements::getElements() const noexcept -> const _Base& {
	return *this;
}

////	����l���擾
//auto PermutationElements::getDefault() const noexcept -> Element {
//	return default_value;
//}
//
////	����l�ɐݒ�
//void PermutationElements::setDefault(Element& target) noexcept {
//	target = default_value;
//}
//
////	����l���ǂ����Ԃ�
//bool PermutationElements::isDefault(Element value) const noexcept {
//	return value == default_value;
//}

////	�z�񂩂ǂ����Ԃ��i���̃N���X�ł͏��false�j
//bool PermutationElements::isArray() const noexcept {
//	return false;
//}
