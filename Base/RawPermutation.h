#pragma once
#include "PermutationTypes.h"
#include <vector>

namespace ro {

//	���̏���f�[�^��ێ�����N���X
	class RawPermutation {
	public:
		using Element = PermutationElement;
		using Index = PermutationIndex;

		RawPermutation(Element*) noexcept;

	//	index �̗v�f���擾����
		Element get(Index index) const noexcept;

	//	index �̗v�f���擾
		Element operator [](Index index) const noexcept;
		
	//	index �̕ύX�\�ȗv�f���擾����
		Element& get(Index index) noexcept;

	//	index �̕ύX�\�ȗv�f���擾����
		Element& operator [](Index index) noexcept;

	//	index ���ݒ肳��Ă��邩�Ԃ�
		bool isset(Index index) const;

	//	���ځi����Ƃ��Ă̐��������m�F�����Ɂj�v�f��ݒ肷��
		void set_directly(Index index, Element value)  noexcept;

	//	index �𖢐ݒ�ɂ���
		void reset(Index index) noexcept;

	//	index1 �� index2 �̗v�f�����ւ���
		void swap(Index index1, Index index2);

	protected:
		Element* element;
	};

}