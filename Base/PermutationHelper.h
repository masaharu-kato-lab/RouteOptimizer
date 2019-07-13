#pragma once
#include "Permutation.h"
#include <utility>
#include <functional>
#include <stdexcept>

namespace ro {

	class PermutationHelper : public Permutation {
	public:
	//	�R���X�g���N�^�i���ׂĖ��ݒ�ŏ������j
		PermutationHelper(const std::shared_ptr<PermutationElements>& origin) noexcept;
		
	//	�R���X�g���N�^�i�����̔z�񂩂珉�����j
		PermutationHelper(const std::shared_ptr<PermutationElements>& origin, Element* target_ptr) noexcept;

	//	�R���X�g���N�^�i����N���X�ŏ������j
		PermutationHelper(const Permutation&) noexcept;

	//	���� index �Ԗڂ����ݒ�� value �����g�p�Ȃ�Aindex �Ԗڂ� value ��ݒ肷��
		bool set_if_unused(Index index, Element value);

	//	���ݒ�� index �Ԗڂɖ��g�p�� value ��ݒ肷��iindex ���ݒ肳��Ă����� value ���g�p����Ă���Η�O�𓊂���j 
		void set_unused(Index index, Element value);

	//	p �Ɠ����l�����ꏊ�ȊO�𖢐ݒ�ɂ���
		void reset_different_indexes(const ConstPermutation& p);

	//	�֐� value_by_index �̕Ԃ��v�f�ɏ]���āA���ݒ�̏ꏊ�𖄂߂�
		void fill_empties_if_unused(std::function<Element(Index)> value_by_index);

	//	���ݒ��Index�ɂ��āAp1 �܂��� p2 ��Index�̗v�f�ɐݒ肷��
	//	�֐� rand �� true ��Ԃ��� p1 �̗v�f�A false ��Ԃ��� p2 �̗v�f��ݒ肷��
	//	�ݒ肷��v�f�����񒆂łɎg�p�ς݂ł���΃X�L�b�v����i�������Ȃ��j
		void fill_empties_with_2_permutations(const ConstPermutation& p1, const ConstPermutation& p2, std::function<bool()> rand);

	//	���ݒ��Index�𖢎g�p�̒l�Ŗ��߂�i���ݒ�̃C���f�b�N�X���V���b�t�����ĕԂ��֐� arrange_indexes ��^����j
		void fill_empties_with_unused(std::function<std::vector<Index>(const Set<Index>&)> get_arranged_indexes);
	
	private:
		Set<Element> unused_elements;
		Set<Index> empty_indexes;
	};

}