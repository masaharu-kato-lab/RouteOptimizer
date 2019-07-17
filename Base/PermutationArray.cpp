#include "PermutationArray.h"
#include <xutility>
using namespace ro;

//	コンストラクタ
PermutationArray::PermutationArray(std::shared_ptr<const Elements> elements, Index n_data) noexcept :
	elements(elements),
	n_data(n_data),
	data(new Element[data_size()])
{}

PermutationArray::PermutationArray(const PermutationArray& self) noexcept : 
	elements(self.elements),
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
	return elements->size();
}

size_t PermutationArray::data_size() const noexcept {
	return permutation_size() * n_data;
}

auto PermutationArray::getRaw(Index index) const noexcept -> const Element* {
	return getElementPtr(index);
}

//	index 番目の順列オブジェクトを取得
Permutation PermutationArray::get(Index index) const noexcept {
	return {getElementPtr(index), permutation_size()};
}

//	index 番目の順列オブジェクトを取得
Permutation PermutationArray::operator [](Index index) const noexcept {
	return get(index);
}

//	index 番目の要素付き順列オブジェクトを取得
ElementedPermutation PermutationArray::getElemented(Index index) const noexcept {
	return {*elements, getElementPtr(index)};
}

auto PermutationArray::getElementPtr(Index index) const noexcept -> Element* {
	return data + permutation_size() * index;
}

void PermutationArray::set(Index index, const Permutation perm) noexcept {
	std::copy(perm.begin(), perm.begin() + permutation_size(), data + index);
}

void PermutationArray::set_all(std::function<Permutation(Index)> generate_perm) noexcept {
	for(Index i = 0; i < n_data; ++i) set(i, generate_perm(i));
}

void PermutationArray::onchange(Index index) noexcept {}