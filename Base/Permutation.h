#pragma once
#include "PermutationTypes.h"
#include <vector>

namespace ro {

//	���̏���f�[�^��ێ�����N���X
	class Permutation {
	public:
		using Element = PermutationElement;
		using Index = PermutationIndex;
	
		Permutation(Index size) noexcept;	//	�R���X�g���N�^�i���ׂĖ��ݒ�ŏ������j
		Permutation(const Element* _data, Index size) noexcept;		//	�R���X�g���N�^�i�����̏���f�[�^���珉�����j
		Permutation(const Permutation&) noexcept;		//	�R�s�[�R���X�g���N�^
		~Permutation() noexcept;		//	�f�X�g���N�^
		
		Index size() const noexcept;		//	������\������v�f�̐����擾����
		Element  get        (Index index) const noexcept;	//	index �̗v�f���擾����
		Element  operator [](Index index) const noexcept;	//	index �̗v�f���擾
		Element& get        (Index index) noexcept;			//	index �̕ύX�\�ȗv�f���擾����
		Element& operator [](Index index) noexcept;			//	index �̕ύX�\�ȗv�f���擾����
		Element*       begin() noexcept;		//	�J�n�|�C���^���擾����
		const Element* begin() const noexcept;	//	�J�nconst�|�C���^���擾����
		Element*       end  () noexcept;		//	�I���|�C���^���擾����
		const Element* end  () const noexcept;	//	�I��const�|�C���^���擾����

		bool isset(Index index) const;		//	index ���ݒ肳��Ă��邩�Ԃ�
		void reset(Index index) noexcept;		//	index �𖢐ݒ�ɂ���
		void reset() noexcept;		//	���ׂĖ��ݒ�ɂ���
		void set_directly(Index index, Element value)  noexcept;	//	���ځi����Ƃ��Ă̐��������m�F�����Ɂj�v�f��ݒ肷��
		void swap(Index index1, Index index2);		//	index1 �� index2 �̗v�f�����ւ���
		
		bool is_valid(const Elements& elements) const noexcept;	//	����Ƃ��Ă̐��������m�F����

		operator const Element*() const noexcept;	//	���f�[�^���擾����

	protected:
		Index data_size;
		Element* data;
	};

}