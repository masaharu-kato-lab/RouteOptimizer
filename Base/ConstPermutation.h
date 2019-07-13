#pragma once
#include "PermutationTypes.h"
#include <vector>

namespace ro {

//	�����̕ύX�s�\�ȏ���f�[�^��ێ�����N���X
	class ConstPermutation {
	public:
		using Element = PermutationElement;
		using Index = PermutationIndex;

	//	�R���X�g���N�^
		ConstPermutation(Element*) noexcept;


	//	index �Ԗڂ̒l���擾����
		Element get(Index index) const noexcept;

	//	index �Ԗڂ̒l���擾
		Element operator [](Index index) const noexcept;

	//	index �Ԗڂ��ݒ肳��Ă��邩�Ԃ�
		bool isset(Index index) const;

	protected:
		Element* element;
	};

}