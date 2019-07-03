#pragma once
#include <iostream>

namespace imgutil {

//	Output values as little-endianed binary
	template <class First, class... Rests>
	void outputAsBinary(std::ostream& os, First first, Rests&&... rests)
	{
	//	Little endian compiler only
		os.write((char*)&first, sizeof(First));

		if constexpr(sizeof...(rests)) outputAsBinary(os, rests...); 
	}


//	Input values as little-endianed binary
	template <class First, class... Rests>
	void inputAsBinary(std::istream& is, First* first, Rests&&... rests)
	{

	//	Little endian compiler only
		if(first) {
			is.read((char*)first, sizeof(First));
		}else{
			is.ignore(sizeof(First));
		}

		if constexpr(sizeof...(rests)) inputAsBinary(is, rests...); 
	}

}