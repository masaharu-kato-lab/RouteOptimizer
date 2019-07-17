#pragma once
#include <cstdint>

namespace ro {
	
//	順列におけるインデックス型
	using PermutationIndex = uint_fast32_t;

//	順列における要素型
	using PermutationElement = uint_fast32_t;

//	順列における要素型の既定値
	constexpr PermutationElement PERMUTATION_ELEMENT_DEFAULT = 0;


	class Elements;
	class Permutation;
	class ElementedPermutation;
	class PermutationArray;

}