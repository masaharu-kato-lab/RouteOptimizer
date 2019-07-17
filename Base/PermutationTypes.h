#pragma once
#include <cstdint>

namespace ro {
	
//	����ɂ�����C���f�b�N�X�^
	using PermutationIndex = uint_fast32_t;

//	����ɂ�����v�f�^
	using PermutationElement = uint_fast32_t;

//	����ɂ�����v�f�^�̊���l
	constexpr PermutationElement PERMUTATION_ELEMENT_DEFAULT = 0;


	class Elements;
	class Permutation;
	class ElementedPermutation;
	class PermutationArray;

}