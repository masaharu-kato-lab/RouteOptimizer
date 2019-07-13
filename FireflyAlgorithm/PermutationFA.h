#pragma once
#include <vector>
#include <random>
#include "../Base/Point.h"
#include "../Base/PermutationHelper.h"
#include "../Base/PermutationArray.h"

namespace ro::fa {

	class PermutationFA {
	public:
		using Element = PermutationElement;
		using PermIndex = PermutationArray::Index;

		PermutationFA(const Set<Element>& elements, PermIndex n_perms) noexcept;



	private:
		PermutationArray perms;


	};

}