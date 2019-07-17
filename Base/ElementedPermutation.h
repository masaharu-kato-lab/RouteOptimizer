#pragma once
#include "Set.h"
#include "Elements.h"
#include "Permutation.h"
#include <utility>
#include <functional>
#include <stdexcept>

namespace ro {

//	���G�ȑ�����s�����Ƃ��ł��鏇��N���X
	class ElementedPermutation : public Permutation {
	public:
	//	�R���X�g���N�^�i���ׂĖ��ݒ�ŏ������j
		ElementedPermutation(const Elements& elements) noexcept;

	//	�R���X�g���N�^�i�����̏���f�[�^���珉�����j
		ElementedPermutation(const Elements& elements, const Element* _data);

	//	���� index �Ԗڂ����ݒ�� value �����g�p�Ȃ�Aindex �Ԗڂ� value ��ݒ肷��
		bool set_if_unused(Index index, Element value);

	//	���ݒ�� index �Ԗڂɖ��g�p�� value ��ݒ肷��iindex ���ݒ肳��Ă����� value ���g�p����Ă���Η�O�𓊂���j 
		void set_unused(Index index, Element value);
		
	//	index �𖢐ݒ�ɂ���
		void reset(Index index) noexcept;

	//	���ׂĖ��ݒ�ɂ���
		void reset() noexcept;

	//	p �Ɠ����l�����ꏊ�ȊO�𖢐ݒ�ɂ���
		void reset_different_indexes(const Element* p);

	//	�֐� value_by_index �̕Ԃ��v�f�ɏ]���āA���ݒ�̏ꏊ�𖄂߂�
		void fill_empties_if_unused(std::function<Element(Index)> value_by_index);

	//	���ݒ��Index�ɂ��āAp1 �܂��� p2 ��Index�̗v�f�ɐݒ肷��
	//	�֐� rand �� true ��Ԃ��� p1 �̗v�f�A false ��Ԃ��� p2 �̗v�f��ݒ肷��
	//	�ݒ肷��v�f�����񒆂łɎg�p�ς݂ł���΃X�L�b�v����i�������Ȃ��j
		void fill_empties_with_2_permutations(const Element* p1, const Element* p2, std::function<bool()> rand);

	//	���ݒ��Index�𖢎g�p�̒l�Ŗ��߂�i���ݒ�̃C���f�b�N�X���V���b�t�����ĕԂ��֐� arrange_indexes ��^����j
		void fill_empties_with_unused(std::function<std::vector<Index>(const Set<Index>&)> get_arranged_indexes);
	
	//	���ڏ���f�[�^��ύX���A�g�p�����v�f�E�C���f�b�N�X�̋L�^�𔽉f������
		void set(const Element* _data);

	//	���������񂩂ǂ����Ԃ�
		bool is_valid() const noexcept;

	private:
		Set<Element> unused_elements;
		Set<Index> empty_indexes;
	};

}