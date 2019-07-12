#pragma once
#include "Permutation.h"
#include <utility>
#include <functional>
#include <stdexcept>

namespace ro {

	template <class Type>
	class PermutationUtility : public Permutation<Type> {
	public:
		using _Base = Permutation<Type>;
		using Index = _Base::Index;

	private:
		Set<Type> unused_values;
		Set<Index> empty_indexes;
		
	public:
	//	コンストラクタ（すべて未設定で初期化）
		PermutationUtility(const std::shared_ptr<PermutationValues<Type>>& origin) noexcept :
			_Base(origin),
			unused_values(origin->getValues()),
			empty_indexes(origin->getIndexes())
		{
			for(Index index = 0; index < _Base::size(); ++index) reset(index);
		}
		
	//	コンストラクタ（既存の配列から初期化）
		PermutationUtility(const std::shared_ptr<PermutationValues<Type>>& origin, Type* target_ptr) noexcept :
			_Base(origin, target_ptr),
			unused_values(origin->getValues()),
			empty_indexes(origin->getIndexes())
		{}

	//	もし index 番目が未設定で value が未使用なら、index 番目に value を設定する
		bool set_if_unused(Index index, Type value) {
			if(isset(index) || !unused_values.exist(value)) return false; 
			get(index) = value;
			empty_indexes.erase(index);
			unused_values.erase(value);
		}

	//	未設定の index 番目に未使用の value を設定する（index が設定されていたり value が使用されていれば例外を投げる） 
		void set_unused(Index index, Type value) {
			if(!set_if_unused(index, value)) throw std::runtime_error("Invalid index or value.");
		}

	//	p と同じ値を持つ場所以外を未設定にする
		void reset_different_indexes(const PermutationUtility& p) const {
			for(Index index = 0; index < _Base::size(); ++index) {
				if(get(index) != p.get(index)) reset(index);
			}
		}

	//	関数 value_by_index の返す値に従って、未設定の場所を埋める
		void fill_empties_if_unused(std::function<Type(Index)> value_by_index) {
			for(Index index : empty_indexes) {
				set_if_unused(index, value_by_index(index));
			}
		}

	//	未設定の場所を未使用の値で埋める（未設定の場所をシャッフルして返す関数 arrange_indexes を与える）
		void fill_empties_with_unused(std::function<std::vector<Index>(Set<Index>)> arrange_indexes) {
			std::vector<Index> arranged_indexes = arrange_indexes(empty_indexes);
			for(Index index : arranged_indexes) {
				set_unused(index, *unused_values.begin());
			}
			if(unused_values.size() || empty_indexes.size()) throw std::runtime_error("Invalid permutation.");
		}

	};

}