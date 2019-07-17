#include "Permutation.h"
#include <xutility>
using namespace ro;

//	������\������v�f�̐����擾����
auto Permutation::size() const noexcept -> Index {
	return data_size;
}
		
//	�R���X�g���N�^�i���ׂĖ��ݒ�ŏ������j
Permutation::Permutation(Index size) noexcept :
	data_size(size),
	data(new Element[size])
{
	reset();
}

//	�R���X�g���N�^�i���ׂĖ��ݒ�ŏ������j
Permutation::Permutation(const Element* _data, Index size) noexcept :
	data_size(size),
	data(new Element[size])
{
	std::copy(_data, _data + size, data);
}

//	�R�s�[�R���X�g���N�^
Permutation::Permutation(const Permutation& p) noexcept :
	data_size(p.data_size),
	data(new Element[p.data_size])
{
	std::copy(p.begin(), p.end(), data);
}

//	�f�X�g���N�^
Permutation::~Permutation() {
	delete[] data;
}

//	�l���擾����
auto Permutation::get(Index index) const noexcept -> Element {
	return data[index];
}

//	�l���擾����
auto Permutation::operator [](Index index) const noexcept -> Element {
	return data[index];
}

//	index �Ԗڂ��ݒ肳��Ă��邩�Ԃ�
bool Permutation::isset(Index index) const {
	return get(index) == PERMUTATION_ELEMENT_DEFAULT;
}

//	�ύX�\�Ȓl���擾����
auto Permutation::get(Index index) noexcept -> Element& {
	return data[index];
}

//	�ύX�\�Ȓl���擾����
auto Permutation::operator [](Index index) noexcept -> Element& {
	return data[index];
}

//	�J�n�|�C���^���擾����
auto Permutation::begin() noexcept -> Element* {
	return data;
}

//	�J�nconst�|�C���^���擾����
auto Permutation::begin() const noexcept -> const Element* {
	return data;
}

//	�I���|�C���^���擾����
auto Permutation::end() noexcept -> Element* {
	return data + data_size;
}

//	�I��const�|�C���^���擾����
auto Permutation::end() const noexcept -> const Element* {
	return data + data_size;
}

//	���ځi����Ƃ��Ă̐��������m�F�����Ɂj�l��ݒ肷��
void Permutation::set_directly(Index index, Element value)  noexcept {
	get(index) = value;
}

//	index �Ԗڂ𖢐ݒ�ɂ���
void Permutation::reset(Index index) noexcept {
	get(index) = PERMUTATION_ELEMENT_DEFAULT;
}

//	index1 �� index2 �����ւ���
void Permutation::swap(Index index1, Index index2) {
	std::swap(get(index1), get(index2));
}

//	���ׂĖ��ݒ�ɂ���
void Permutation::reset() noexcept {
	for(Index index = 0; index < size(); ++index) reset(index);
}

//	���f�[�^���擾����
Permutation::operator const Element*() const noexcept {
	return data;
}

