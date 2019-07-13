#include "PermutationArray.h"
#include <xutility>
using namespace ro;

//	コンストラクタ
PermutationArray::PermutationArray(std::shared_ptr<PermutationElements> origin, Index n_data) noexcept :
	origin(origin),
	n_data(n_data),
	data(new Element[data_size()])
{}

PermutationArray::PermutationArray(const PermutationArray& self) noexcept : 
	origin(origin),
	n_data(self.n_data),
	data(new Element[data_size()])
{
	std::copy(self.data, self.data + data_size(), data);
}

//	デストラクタ
PermutationArray::~PermutationArray() {
	delete[] data;
}

//	データ数の取得
auto PermutationArray::size() const noexcept -> Index {
	return n_data;
}

auto PermutationArray::permutation_size() const noexcept -> PermutationIndex {
	return origin->size();
}

size_t PermutationArray::data_size() const noexcept {
	return permutation_size() * n_data;
}

auto PermutationArray::getConst(Index index) const noexcept -> ConstPermutation {
	return {getElementPtr(index)};
}

auto PermutationArray::get(Index index) const noexcept -> ConstPermutation {
	return getConst(index);
}

auto PermutationArray::operator [](Index index) const noexcept -> ConstPermutation {
	return getConst(index);
}

//	index 番目の順列オブジェクトを取得
auto PermutationArray::get(Index index) noexcept -> Permutation {
	return {shared_from_this(), getElementPtr(index)};
}

//	index 番目の順列オブジェクトを取得
auto PermutationArray::operator [](Index index) noexcept -> Permutation {
	return get(index);
}

//	index 番目の順列オブジェクトを取得
auto PermutationArray::getHelper(Index index) noexcept -> PermutationHelper {
	return {shared_from_this(), getElementPtr(index)};
}
		
//	配列かどうか返す（このクラスでは常にtrue)
bool PermutationArray::isArray() const noexcept {
	return true;
}

auto PermutationArray::getElementPtr(Index index) const noexcept -> Element* {
	return data + _Base::size() * index;
}
