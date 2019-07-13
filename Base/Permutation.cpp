#include "Permutation.h"
using namespace ro;

//	変更可能な値を取得する
auto Permutation::get(Index index) noexcept -> Element& {
	return element[index];
}

//	変更可能な値を取得する
auto Permutation::operator [](Index index) noexcept -> Element& {
	return element[index];
}

//	順列を構成する要素の数を取得する
auto Permutation::size() const noexcept -> Index {
	return origin->size();
}
		
//	コンストラクタ（すべて未設定で初期化）
Permutation::Permutation(const std::shared_ptr<PermutationElements>& origin) noexcept :
	ConstPermutation(new Element[size()]),
	origin(origin)
{
	reset();
}
		
//	コンストラクタ（既存の配列から初期化）
Permutation::Permutation(const std::shared_ptr<PermutationElements>& origin, Element* target_ptr) noexcept :
	ConstPermutation(target_ptr),
	origin(origin)
{}

//	デストラクタ
Permutation::~Permutation() {
//	if(!origin->isArray()) delete element;
}

//	直接（順列としての整合性を確認せずに）値を設定する
void Permutation::set_directly(Index index, Element value)  noexcept {
	get(index) = value;
}

//	index 番目を未設定にする
void Permutation::reset(Index index) noexcept {
	get(index) = PermutationElements::DEFAULT_ELEMENT;
}

//	すべて未設定にする
void Permutation::reset() noexcept {
	for(Index index = 0; index < size(); ++index) reset(index);
}

//	index1 と index2 を入れ替える
void Permutation::swap(Index index1, Index index2) {
	std::swap(get(index1), get(index2));
}
