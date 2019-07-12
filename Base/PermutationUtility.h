#pragma once
#include "Permutation.h"
#include <utility>
#include <functional>
#include <stdexcept>

namespace ro {

	template <class Type>
	class PermutationUtility : public Permutation<Type> {
	public:
		using _Base = Permutation<Type>;
		using Index = _Base::Index;

	private:
		Set<Type> unused_values;
		Set<Index> empty_indexes;
		
	public:
	//	�R���X�g���N�^�i���ׂĖ��ݒ�ŏ������j
		PermutationUtility(const std::shared_ptr<PermutationValues<Type>>& origin) noexcept :
			_Base(origin),
			unused_values(origin->getValues()),
			empty_indexes(origin->getIndexes())
		{
			for(Index index = 0; index < _Base::size(); ++index) reset(index);
		}
		
	//	�R���X�g���N�^�i�����̔z�񂩂珉�����j
		PermutationUtility(const std::shared_ptr<PermutationValues<Type>>& origin, Type* target_ptr) noexcept :
			_Base(origin, target_ptr),
			unused_values(origin->getValues()),
			empty_indexes(origin->getIndexes())
		{}

	//	���� index �Ԗڂ����ݒ�� value �����g�p�Ȃ�Aindex �Ԗڂ� value ��ݒ肷��
		bool set_if_unused(Index index, Type value) {
			if(isset(index) || !unused_values.exist(value)) return false; 
			get(index) = value;
			empty_indexes.erase(index);
			unused_values.erase(value);
		}

	//	���ݒ�� index �Ԗڂɖ��g�p�� value ��ݒ肷��iindex ���ݒ肳��Ă����� value ���g�p����Ă���Η�O�𓊂���j 
		void set_unused(Index index, Type value) {
			if(!set_if_unused(index, value)) throw std::runtime_error("Invalid index or value.");
		}

	//	p �Ɠ����l�����ꏊ�ȊO�𖢐ݒ�ɂ���
		void reset_different_indexes(const PermutationUtility& p) const {
			for(Index index = 0; index < _Base::size(); ++index) {
				if(get(index) != p.get(index)) reset(index);
			}
		}

	//	�֐� value_by_index �̕Ԃ��l�ɏ]���āA���ݒ�̏ꏊ�𖄂߂�
		void fill_empties_if_unused(std::function<Type(Index)> value_by_index) {
			for(Index index : empty_indexes) {
				set_if_unused(index, value_by_index(index));
			}
		}

	//	���ݒ�̏ꏊ�𖢎g�p�̒l�Ŗ��߂�i���ݒ�̏ꏊ���V���b�t�����ĕԂ��֐� arrange_indexes ��^����j
		void fill_empties_with_unused(std::function<std::vector<Index>(Set<Index>)> arrange_indexes) {
			std::vector<Index> arranged_indexes = arrange_indexes(empty_indexes);
			for(Index index : arranged_indexes) {
				set_unused(index, *unused_values.begin());
			}
			if(unused_values.size() || empty_indexes.size()) throw std::runtime_error("Invalid permutation.");
		}

	};

}