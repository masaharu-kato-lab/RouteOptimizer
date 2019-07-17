#include "Elements.h"
using namespace ro;

//	コンストラクタ
Elements::Elements(const _Base& values) noexcept
	: _Base(values) {}

//	インデックスの集合を取得
auto Elements::getIndexes() const noexcept -> Set<Index> {
	Set<Index> ret;
	for(Index i = 0; i < _Base::size(); ++i) {
		ret.insert(i);
	}
	return ret;
};

//	値の集合を取得
auto Elements::getElements() const noexcept -> const _Base& {
	return *this;
}
