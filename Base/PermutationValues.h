#pragma once
#include "Set.h"
#include <numeric>

namespace ro {
	
//	����Ɏg�p����l�̏W����\������N���X
	template <class Type>
	class PermutationValues : public Set<Type> {
	protected:
		using _Base = Set<Type>;

	public:
		using Index = size_t;

	private:
	//	����l
		Type default_value;
	
	public:
	//	�R���X�g���N�^
		PermutationValues(const _Base& values, Type default_value) noexcept
			: _Base(values), default_value(default_value) {}

	//	�C���f�b�N�X�̏W�����擾
		Set<Index> getIndexes() const noexcept {
			Set<Index> ret;
			for(Index i = 0; i < _Base::size(); ++i) {
				ret.insert(i);
			}
			return ret;
		};

	//	�l�̏W�����擾
		const Set<Type>& getValues() const noexcept {
			return *this;
		}

	//	����l���擾
		Type getDefault() const noexcept {
			return default_value;
		}

	//	����l�ɐݒ�
		void setDefault(Type& target) noexcept {
			target = default_value;
		}

	//	����l���ǂ����Ԃ�
		bool isDefault(Type value) const noexcept {
			return value == default_value;
		}

	//	�z�񂩂ǂ����Ԃ��i���̃N���X�ł͏��false�j
		virtual bool isArray() const noexcept {
			return false;
		}

	};

}