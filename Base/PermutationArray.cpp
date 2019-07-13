#include "PermutationArray.h"
#include <xutility>
using namespace ro;

//	�R���X�g���N�^
PermutationArray::PermutationArray(std::shared_ptr<const PermutationElements> origin, Index n_data) noexcept :
	origin(origin),
	n_data(n_data),
	data(new Element[data_size()])
{}

PermutationArray::PermutationArray(const PermutationArray& self) noexcept : 
	origin(origin),
	n_data(self.n_data),
	data(new Element[data_size()])
{
	std::copy(self.data, self.data + data_size(), data);
}

//	�f�X�g���N�^
PermutationArray::~PermutationArray() {
	delete[] data;
}

//	�f�[�^���̎擾
auto PermutationArray::size() const noexcept -> Index {
	return n_data;
}

auto PermutationArray::permutation_size() const noexcept -> PermutationIndex {
	return origin->size();
}

size_t PermutationArray::data_size() const noexcept {
	return permutation_size() * n_data;
}

RawPermutation PermutationArray::getRaw(Index index) const noexcept {
	return {getElementPtr(index)};
}

//	index �Ԗڂ̏���I�u�W�F�N�g���擾
Permutation PermutationArray::get(Index index) const noexcept {
	return {origin, getElementPtr(index)};
}

//	index �Ԗڂ̏���I�u�W�F�N�g���擾
Permutation PermutationArray::operator [](Index index) const noexcept {
	return get(index);
}

//	index �Ԗڂ̏���I�u�W�F�N�g���擾
PermutationHelper PermutationArray::getHelper(Index index) const noexcept {
	return {origin, getElementPtr(index)};
}
//		
////	�z�񂩂ǂ����Ԃ��i���̃N���X�ł͏��true)
//bool PermutationArray::isArray() const noexcept {
//	return true;
//}

auto PermutationArray::getElementPtr(Index index) const noexcept -> Element* {
	return data + permutation_size() * index;
}
