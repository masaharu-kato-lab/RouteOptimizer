#pragma once
#include "PermutationElements.h"
#include "Permutation.h"
#include "PermutationHelper.h"
#include <memory>

namespace ro {

//	����Ɏg�p����l�̏W����\�����A����̔z���ێ�����N���X
	class PermutationArray : /* public PermutationElements, */ public std::enable_shared_from_this<PermutationArray> {
	public:	
		using Index = uint_fast32_t;
		using Element = PermutationElement;

		PermutationArray(std::shared_ptr<const PermutationElements> origin, Index n_data) noexcept;
		PermutationArray(const PermutationArray&) noexcept;
		~PermutationArray();

	//	����̐����擾
		Index size() const noexcept;

	//	1����̃T�C�Y���擾
		PermutationIndex permutation_size() const noexcept;

		RawPermutation getRaw(Index index) const noexcept;	
			
		Permutation get(Index index) const noexcept;
		Permutation operator [](Index index) const noexcept;

		PermutationHelper getHelper(Index index) const noexcept;

		//	bool isArray() const noexcept override;

	private:
		std::shared_ptr<const PermutationElements> origin;	//	�v�f�f�[�^
		Index n_data;	//	�f�[�^��
		Element* data;	//	����f�[�^

		//	index �Ԗڂ̏���f�[�^�̐擪�|�C���^���擾
		Element* getElementPtr(Index index) const noexcept;

		//	�f�[�^���i����̐��~1����̃T�C�Y�j���擾
		size_t data_size() const noexcept;
	
	};

}