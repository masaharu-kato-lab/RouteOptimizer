#pragma once
#include "RawPermutation.h"
#include "PermutationElements.h"
#include <memory>

namespace ro {

//	����̗v�f�������A�ҏW�\�ȏ���N���X
	class Permutation : public RawPermutation {
	public:
	//	������\������v�f�̐����擾����
		Index size() const noexcept;
		
	//	�R���X�g���N�^�i���ׂĖ��ݒ�ŏ������j
		Permutation(const std::shared_ptr<const PermutationElements>& origin) noexcept;
		
	//	�R���X�g���N�^�i�����̔z�񂩂珉�����j
		Permutation(const std::shared_ptr<const PermutationElements>& origin, Element* target_ptr) noexcept;

		~Permutation();

		using RawPermutation::reset;

	//	���ׂĖ��ݒ�ɂ���
		void reset() noexcept;

	//	���ځi����Ƃ��Ă̐��������m�F�����Ɂj�l��ݒ肷��
	//	index ���͈͊O�̏ꍇ�͗�O�𓊂���
		void set_directly(Index index, Element value);
		
	//	����Ƃ��Ă̐��������m�F����
		bool isValid() const noexcept;


	//	���̏���f�[�^���擾����
		RawPermutation getRaw() const noexcept;

	//	�w���p�[���擾����
		PermutationHelper getHelper() const noexcept;

	protected:
		std::shared_ptr<const PermutationElements> origin;
		
	};

}