#pragma once
#include "ConstPermutation.h"
#include "PermutationElements.h"
#include <memory>

namespace ro {

//	����̗v�f�������A�ҏW�\�ȏ���N���X
	class Permutation : public ConstPermutation {
	public:		
	//	index �Ԗڂ̕ύX�\�Ȓl���擾����
		Element& get(Index index) noexcept;

	//	index �Ԗڂ̕ύX�\�Ȓl���擾����
		Element& operator [](Index index) noexcept;

	//	������\������v�f�̐����擾����
		Index size() const noexcept;
		
	//	�R���X�g���N�^�i���ׂĖ��ݒ�ŏ������j
		Permutation(const std::shared_ptr<PermutationElements>& origin) noexcept;
		
	//	�R���X�g���N�^�i�����̔z�񂩂珉�����j
		Permutation(const std::shared_ptr<PermutationElements>& origin, Element* target_ptr) noexcept;

	//	�f�X�g���N�^
		~Permutation();

	//	����Ƃ��Ă̐��������m�F����
		bool isValid() const noexcept;

	//	���ځi����Ƃ��Ă̐��������m�F�����Ɂj�l��ݒ肷��
		void set_directly(Index index, Element value)  noexcept;

	//	index �Ԗڂ𖢐ݒ�ɂ���
		void reset(Index index) noexcept;

	//	���ׂĖ��ݒ�ɂ���
		void reset() noexcept;

	//	index1 �� index2 �����ւ���
		void swap(Index index1, Index index2);

	protected:
		std::shared_ptr<PermutationElements> origin;
		
	};

}