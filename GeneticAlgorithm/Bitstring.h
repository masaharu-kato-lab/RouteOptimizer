#pragma once
#include <memory>

namespace ro::ga {

	//	Bitstring class
	class Bitstring {
	public:
		using BitIndex = uint32_t;
		using Unit = uint_fast32_t;	//	Data unit type

		class Iterator;
		class Reference;

		explicit Bitstring(BitIndex length) noexcept;

		Reference begin() const noexcept;			//	Access first bit
		Reference end() const noexcept;				//	Access terminal (last + 1) bit
		BitIndex length() const noexcept;			//	Get length
		BitIndex size() const noexcept;				//	Alias of length()

		bool operator [](BitIndex index) const;		//	Get bit on index
		bool get(BitIndex index) const;				//	Get bit on index

		Reference operator [](BitIndex index);		//	Get editable bit on index
		Reference get(BitIndex index);				//	Get editable bit on index

		void set(BitIndex index, bool value);		//	Set bit on index

		//	Copy bits [beg, end) of self to dest_beg index of dest
		Bitstring& copyBits(BitIndex beg, BitIndex end, Bitstring& dest, BitIndex dest_beg) const;

		void flip() noexcept;	//	Flip all bits
		void randomize();		//	Randomize all bits;

		bool operator !=(const Iterator&) const;
		bool operator ==(const Iterator&) const;

	private:
		std::unique_ptr<Unit[]> data;
	};


//	Reference Utility class for Iterator
	class Bitstring::Reference {
		friend Iterator;

		Reference(Unit* c_unit, size_t index);

	public:
		const Iterator& operator *() const noexcept;	//	Get self (for Range-based for-loop)
		Iterator& operator *() noexcept;	//	Get self (for Range-based for-loop)

		Reference& operator =(bool x) noexcept;				//	Set value 
		Reference& operator =(const Reference&) noexcept;	//	Set value from reference

		bool operator ~() const noexcept;	//	Get flipped value
		operator bool() const noexcept;		//	Get value
		Reference& flip() noexcept;			//	Flip this value

		bool operator !=(const Iterator&) const;
		bool operator ==(const Iterator&) const;

	private:
		Unit* c_unit;	//	Pointer to target unit (includes target bit)
		size_t index;	//	Index of target bit (from c_unit)
	};

	
//	Iterator of Bitstring
	class Bitstring::Iterator {
		friend Bitstring;

		Iterator(Unit* target);
			
	public:
		const Iterator& operator *() const;			//	Get self (for Range-based for-loop)
		Iterator& operator *();						//	Get self (for Range-based for-loop)

		Iterator& operator --();					//	Change to previous bitstring
		Iterator& operator ++();					//	Change to next bitstring

		bool operator !=(const Iterator&) const;
		bool operator ==(const Iterator&) const;

	private:
		Unit* target;	//	Pointer to target bitstring
	};

}