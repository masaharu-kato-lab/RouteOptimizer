#pragma once
#include <memory>

namespace ga {

//	Fixed size array of fixed length bitstring 
	class BitstrArray {
		
	//	Bitstring class (only for BitstrArray use)
		class Bitstr;
		
	public:
		BitstrArray(BitIndex bit_length, StrIndex str_count);

	//	Get bitstring (iterator) of index
		Iterator operator [](StrIndex) const;

	//	Get first bitstring (iterator)
		Iterator begin() const;

	//	Get terminal (last + 1) bitstring (iterator)
		Iterator end() const;

	private:
		std::unique_ptr<Unit[]> data;	//	main data
	};




}