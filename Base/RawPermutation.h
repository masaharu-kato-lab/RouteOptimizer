#pragma once
#include "PermutationTypes.h"
#include <vector>

namespace ro {

//	���̏���f�[�^��ێ�����N���X
	class RawPermutation {
	public:
		using Element = PermutationElement;
		using Index = PermutationIndex;

	//	�R���X�g���N�^
		RawPermutation(Element*) noexcept;


	//	index �Ԗڂ̒l���擾����
		Element get(Index index) const noexcept;

	//	index �Ԗڂ̒l���擾
		Element operator [](Index index) const noexcept;
		
	//	index �Ԗڂ̕ύX�\�Ȓl���擾����
		Element& get(Index index) noexcept;

	//	index �Ԗڂ̕ύX�\�Ȓl���擾����
		Element& operator [](Index index) noexcept;

	//	index �Ԗڂ��ݒ肳��Ă��邩�Ԃ�
		bool isset(Index index) const;

	//	���ځi����Ƃ��Ă̐��������m�F�����Ɂj�l��ݒ肷��
		void set_directly(Index index, Element value)  noexcept;

	//	index �Ԗڂ𖢐ݒ�ɂ���
		void reset(Index index) noexcept;

	//	index1 �� index2 �����ւ���
		void swap(Index index1, Index index2);

	protected:
		Element* element;
	};

}