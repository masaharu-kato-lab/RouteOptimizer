#include "ConstPermutation.h"
using namespace ro;

ConstPermutation::ConstPermutation(Element* element)
	: element(element) {}

//	’l‚ğæ“¾‚·‚é
auto ConstPermutation::get(Index index) const noexcept -> Element {
	return element[index];
}

//	’l‚ğæ“¾‚·‚é
auto ConstPermutation::operator [](Index index) const noexcept -> Element {
	return element[index];
}

//	index ”Ô–Ú‚ªİ’è‚³‚ê‚Ä‚¢‚é‚©•Ô‚·
bool ConstPermutation::isset(Index index) const {
	return get(index) == PERMUTATION_ELEMENT_DEFAULT;
}