#pragma once
#include "PermutationValues.h"
#include <memory>
#include <vector>

namespace ro {

	template <class Type>
	class Permutation {
	public:
		using Index = PermutationValues<Type>::Index;

	protected:
		std::shared_ptr<PermutationValues<Type>> origin;
		Type* target;
		
	public:
	//	�l���擾����
		Type get(Index index) const noexcept {
			return target[index];
		}
		
	//	�ύX�\�Ȓl���擾����
		Type& get(Index index) noexcept {
			return target[index];
		}
		
	//	�R���X�g���N�^�i���ׂĖ��ݒ�ŏ������j
		Permutation(const std::shared_ptr<PermutationValues<Type>>& origin) noexcept :
			origin(origin),
			target(new Type[origin->size()])
		{
			for(Index index = 0; index < _Base::size(); ++index) reset(index);
		}
		
	//	�R���X�g���N�^�i�����̔z�񂩂珉�����j
		Permutation(const std::shared_ptr<PermutationValues<Type>>& origin, Type* target_ptr) noexcept :
			origin(origin),
			target(target_ptr)
		{}

	//	���ځi����Ƃ��Ă̐��������m�F�����Ɂj�l��ݒ肷��
		void set_directly(Index index, Type value)  noexcept {
			get(index) = value;
		}

	//	index �Ԗڂ𖢐ݒ�ɂ���
		void reset(Index index) noexcept {
			origin->setDefault(get(index));
		}

	//	index �Ԗڂ��ݒ肳��Ă��邩�Ԃ�
		bool isset(Index index) const {
			return !origin->isDefault(get(index));
		}

	//	index1 �� index2 �����ւ���
		void swap(Index index1, Index index2) {
			std::swap(get(index1), get(index2));
		}

	};

}