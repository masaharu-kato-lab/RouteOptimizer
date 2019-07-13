#pragma once
#include "PermutationTypes.h"
#include "Set.h"
#include <numeric>

namespace ro {

	class PermutationElements : public Set<PermutationElement> {
	protected:
		using _Base = Set<PermutationElement>;	//	���^�i�v�f�̏W���j
		using Element = PermutationElement;		//	�v�f�^
		using Index = PermutationIndex;			//	�C���f�b�N�X�^
	
	public:
		constexpr static Element DEFAULT_ELEMENT = PERMUTATION_ELEMENT_DEFAULT;	//	����l

	//	�R���X�g���N�^
		PermutationElements(const _Base& values) noexcept;

	//	�C���f�b�N�X�̏W�����擾
		Set<Index> getIndexes() const noexcept;

	//	�v�f�̏W�����擾
		const _Base& getElements() const noexcept;

	////	����l���擾
	//	Element getDefault() const noexcept;

	////	����l�ɐݒ�
	//	void setDefault(Element& target) noexcept;

	////	����l���ǂ����Ԃ�
	//	bool isDefault(Element value) const noexcept;

	////	�z�񂩂ǂ����Ԃ��i���̃N���X�ł͏��false�j
	//	virtual bool isArray() const noexcept;

	};

}