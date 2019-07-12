#pragma once
#include "PermutationValues.h"

namespace ro {

//	����Ɏg�p����l�̏W����\�����A����̔z���ێ�����N���X
	template <class Type>
	class PermutationArray : public PermutationValues<Type> {
	private:
		using _Base = PermutationValues<Type>;
		using Index = _Base::Index;

		Index n_data;	//	�f�[�^��
		Type* data;		//	����f�[�^

	public:
	//	�R���X�g���N�^
		PermutationArray(const _Base::_Base& values, Type default_value, Index n_data) noexcept :
			_Base(values, default_value),
			n_data(n_data),
			data(new Type[values.size() * n_data])
		{}

	//	index �Ԗڂ̏���f�[�^���擾
		Type* operator [](Index index) noexcept {
			return data + _Base::size() * index;
		}

	//	
		
	//	�z�񂩂ǂ����Ԃ��i���̃N���X�ł͏��true)
		bool isArray() const noexcept override {
			return true;
		}

	};

}