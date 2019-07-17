#include "Elements.h"
using namespace ro;

//	�R���X�g���N�^
Elements::Elements(const _Base& values) noexcept
	: _Base(values) {}

//	�C���f�b�N�X�̏W�����擾
auto Elements::getIndexes() const noexcept -> Set<Index> {
	Set<Index> ret;
	for(Index i = 0; i < _Base::size(); ++i) {
		ret.insert(i);
	}
	return ret;
};

//	�l�̏W�����擾
auto Elements::getElements() const noexcept -> const _Base& {
	return *this;
}
