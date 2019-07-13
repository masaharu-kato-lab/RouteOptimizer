#include "Permutation.h"
using namespace ro;

//	�ύX�\�Ȓl���擾����
auto Permutation::get(Index index) noexcept -> Element& {
	return element[index];
}

//	�ύX�\�Ȓl���擾����
auto Permutation::operator [](Index index) noexcept -> Element& {
	return element[index];
}

//	������\������v�f�̐����擾����
auto Permutation::size() const noexcept -> Index {
	return origin->size();
}
		
//	�R���X�g���N�^�i���ׂĖ��ݒ�ŏ������j
Permutation::Permutation(const std::shared_ptr<PermutationElements>& origin) noexcept :
	ConstPermutation(new Element[size()]),
	origin(origin)
{
	reset();
}
		
//	�R���X�g���N�^�i�����̔z�񂩂珉�����j
Permutation::Permutation(const std::shared_ptr<PermutationElements>& origin, Element* target_ptr) noexcept :
	ConstPermutation(target_ptr),
	origin(origin)
{}

//	�f�X�g���N�^
Permutation::~Permutation() {
//	if(!origin->isArray()) delete element;
}

//	���ځi����Ƃ��Ă̐��������m�F�����Ɂj�l��ݒ肷��
void Permutation::set_directly(Index index, Element value)  noexcept {
	get(index) = value;
}

//	index �Ԗڂ𖢐ݒ�ɂ���
void Permutation::reset(Index index) noexcept {
	get(index) = PermutationElements::DEFAULT_ELEMENT;
}

//	���ׂĖ��ݒ�ɂ���
void Permutation::reset() noexcept {
	for(Index index = 0; index < size(); ++index) reset(index);
}

//	index1 �� index2 �����ւ���
void Permutation::swap(Index index1, Index index2) {
	std::swap(get(index1), get(index2));
}
