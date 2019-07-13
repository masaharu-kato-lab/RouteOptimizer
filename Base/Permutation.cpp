#include "Permutation.h"
#include "PermutationHelper.h"
#include <stdexcept>
using namespace ro;

//	������\������v�f�̐����擾����
auto Permutation::size() const noexcept -> Index {
	return origin->size();
}
		
//	�R���X�g���N�^�i���ׂĖ��ݒ�ŏ������j
Permutation::Permutation(const std::shared_ptr<const PermutationElements>& origin) noexcept :
	RawPermutation(new Element[size()]),
	origin(origin)
{
	reset();
}
		
//	�R���X�g���N�^�i�����̔z�񂩂珉�����j
Permutation::Permutation(const std::shared_ptr<const PermutationElements>& origin, Element* target_ptr) noexcept :
	RawPermutation(target_ptr),
	origin(origin)
{}

//	�f�X�g���N�^
Permutation::~Permutation() {
//	if(!origin->isArray()) delete element;
}

//	���ځi����Ƃ��Ă̐��������m�F�����Ɂj�l��ݒ肷��
void Permutation::set_directly(Index index, Element value) {
	if(index >= size()) throw std::out_of_range("index out of range.");
	RawPermutation::set_directly(index, value);
}

//	���ׂĖ��ݒ�ɂ���
void Permutation::reset() noexcept {
	for(Index index = 0; index < size(); ++index) reset(index);
}

//	���̏���f�[�^���擾����
RawPermutation Permutation::getRaw() const noexcept {
	return (RawPermutation)*this;
}

//	�w���p�[���擾����
PermutationHelper Permutation::getHelper() const noexcept {
	return {*this};
}