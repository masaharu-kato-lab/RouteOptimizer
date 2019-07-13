#include "PermutationElements.h"
using namespace ro;

//	コンストラクタ
PermutationElements::PermutationElements(const _Base& values) noexcept
	: _Base(values) {}

//	インデックスの集合を取得
auto PermutationElements::getIndexes() const noexcept -> Set<Index> {
	Set<Index> ret;
	for(Index i = 0; i < _Base::size(); ++i) {
		ret.insert(i);
	}
	return ret;
};

//	値の集合を取得
auto PermutationElements::getElements() const noexcept -> const _Base& {
	return *this;
}

////	既定値を取得
//auto PermutationElements::getDefault() const noexcept -> Element {
//	return default_value;
//}
//
////	既定値に設定
//void PermutationElements::setDefault(Element& target) noexcept {
//	target = default_value;
//}
//
////	既定値かどうか返す
//bool PermutationElements::isDefault(Element value) const noexcept {
//	return value == default_value;
//}

////	配列かどうか返す（このクラスでは常にfalse）
//bool PermutationElements::isArray() const noexcept {
//	return false;
//}
