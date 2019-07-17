#pragma once
#include "Elements.h"
#include "Permutation.h"
#include "ElementedPermutation.h"
#include <memory>
#include <functional>

namespace ro {

//	����̔z��N���X
	class PermutationArray {
	public:	
		using Index = uint_fast32_t;
		using Element = PermutationElement;

		PermutationArray(std::shared_ptr<const Elements> elements, Index n_data) noexcept;
		PermutationArray(const PermutationArray&) noexcept;
		~PermutationArray();

	//	����̐����擾
		Index size() const noexcept;

	//	1����̃T�C�Y���擾
		PermutationIndex permutation_size() const noexcept;

		const Element* getRaw(Index index) const noexcept;				//	���f�[�^���擾
		Permutation get(Index index) const noexcept;					//	����I�u�W�F�N�g���擾
		Permutation operator [](Index index) const noexcept;			//	����I�u�W�F�N�g���擾
		ElementedPermutation getElemented(Index index) const noexcept;	//	�v�f�t������I�u�W�F�N�g���擾

	//	�����ݒ�
		void set(Index index, const Permutation perm) noexcept;

	//	���ׂĂ̏����ύX����
		void set_all(std::function<Permutation(Index)> generate_perm) noexcept;

	//	���񂪕ύX���ꂽ�Ƃ��ɌĂ΂��֐��i����ł͉������Ȃ��j
		virtual void onchange(Index index) noexcept;

	private:
		std::shared_ptr<const Elements> elements;	//	�v�f�W��
		Index n_data;	//	�f�[�^��
		Element* data;	//	����f�[�^

		//	index �Ԗڂ̏���f�[�^�̐擪�|�C���^���擾
		Element* getElementPtr(Index index) const noexcept;

		//	�f�[�^���i����̐��~1����̃T�C�Y�j���擾
		size_t data_size() const noexcept;
	
	};

}