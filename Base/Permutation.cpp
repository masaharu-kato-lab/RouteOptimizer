#include "Permutation.h"
#include <xutility>
using namespace ro;

//	順列を構成する要素の数を取得する
auto Permutation::size() const noexcept -> Index {
	return data_size;
}
		
//	コンストラクタ（すべて未設定で初期化）
Permutation::Permutation(Index size) noexcept :
	data_size(size),
	data(new Element[size])
{
	reset();
}

//	コンストラクタ（すべて未設定で初期化）
Permutation::Permutation(const Element* _data, Index size) noexcept :
	data_size(size),
	data(new Element[size])
{
	std::copy(_data, _data + size, data);
}

//	コピーコンストラクタ
Permutation::Permutation(const Permutation& p) noexcept :
	data_size(p.data_size),
	data(new Element[p.data_size])
{
	std::copy(p.begin(), p.end(), data);
}

//	デストラクタ
Permutation::~Permutation() {
	delete[] data;
}

//	値を取得する
auto Permutation::get(Index index) const noexcept -> Element {
	return data[index];
}

//	値を取得する
auto Permutation::operator [](Index index) const noexcept -> Element {
	return data[index];
}

//	index 番目が設定されているか返す
bool Permutation::isset(Index index) const {
	return get(index) == PERMUTATION_ELEMENT_DEFAULT;
}

//	変更可能な値を取得する
auto Permutation::get(Index index) noexcept -> Element& {
	return data[index];
}

//	変更可能な値を取得する
auto Permutation::operator [](Index index) noexcept -> Element& {
	return data[index];
}

//	開始ポインタを取得する
auto Permutation::begin() noexcept -> Element* {
	return data;
}

//	開始constポインタを取得する
auto Permutation::begin() const noexcept -> const Element* {
	return data;
}

//	終了ポインタを取得する
auto Permutation::end() noexcept -> Element* {
	return data + data_size;
}

//	終了constポインタを取得する
auto Permutation::end() const noexcept -> const Element* {
	return data + data_size;
}

//	直接（順列としての整合性を確認せずに）値を設定する
void Permutation::set_directly(Index index, Element value)  noexcept {
	get(index) = value;
}

//	index 番目を未設定にする
void Permutation::reset(Index index) noexcept {
	get(index) = PERMUTATION_ELEMENT_DEFAULT;
}

//	index1 と index2 を入れ替える
void Permutation::swap(Index index1, Index index2) {
	std::swap(get(index1), get(index2));
}

//	すべて未設定にする
void Permutation::reset() noexcept {
	for(Index index = 0; index < size(); ++index) reset(index);
}

//	生データを取得する
Permutation::operator const Element*() const noexcept {
	return data;
}

