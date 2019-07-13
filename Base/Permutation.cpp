#include "Permutation.h"
#include "PermutationHelper.h"
#include <stdexcept>
using namespace ro;

//	順列を構成する要素の数を取得する
auto Permutation::size() const noexcept -> Index {
	return origin->size();
}
		
//	コンストラクタ（すべて未設定で初期化）
Permutation::Permutation(const std::shared_ptr<const PermutationElements>& origin) noexcept :
	RawPermutation(new Element[size()]),
	origin(origin)
{
	reset();
}
		
//	コンストラクタ（既存の配列から初期化）
Permutation::Permutation(const std::shared_ptr<const PermutationElements>& origin, Element* target_ptr) noexcept :
	RawPermutation(target_ptr),
	origin(origin)
{}

//	デストラクタ
Permutation::~Permutation() {
//	if(!origin->isArray()) delete element;
}

//	直接（順列としての整合性を確認せずに）値を設定する
void Permutation::set_directly(Index index, Element value) {
	if(index >= size()) throw std::out_of_range("index out of range.");
	RawPermutation::set_directly(index, value);
}

//	すべて未設定にする
void Permutation::reset() noexcept {
	for(Index index = 0; index < size(); ++index) reset(index);
}

//	生の順列データを取得する
RawPermutation Permutation::getRaw() const noexcept {
	return (RawPermutation)*this;
}

//	ヘルパーを取得する
PermutationHelper Permutation::getHelper() const noexcept {
	return {*this};
}