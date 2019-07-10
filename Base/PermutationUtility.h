#pragma once
#include "PermutationValues.h"
#include <memory>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>

namespace base {

	template <class Type, class _Base = std::vector<Type>>
	class PermutationUtility : public std::vector<Type> {
	public:
		using Index = size_t;

	private:
		std::shared_ptr<PermutationValues<Type>> origin;
		Set<Type> unused_values;
		Set<Index> empty_indexes;
		
		Type& get(Index index) {
			return _Base::operator [](index);
		}
		
	public:
		PermutationUtility(const std::shared_ptr<PermutationValues<Type>>& origin) noexcept :
			_Base(origin->size(), origin->getDefault()),
			origin(origin),
			unused_values(*origin),
			empty_indexes(origin->getIndexes())
		{}

		Type get(Index index) const {
			return _Base::operator [](index);
		}

		bool set_if_unused(Index index, Type value) {
			if(isset(index) || !unused_values.exist(value)) return false; 
			get(index) = value;
			empty_indexes.erase(index);
			unused_values.erase(value);
		}

		void set_unused(Index index, Type value) {
			if(!set_if_unused(index, value)) throw std::runtime_error("Invalid index or value.");
		}

		bool isset(Index index) const {
			return !origin->isDefault(_Base::operator [](index));
		}

		PermutationUtility operator &(const Permutation& p) const {
			PermutationUtility ret(origin);
			for(Index index = 0; index < _Base::size(); ++index) {
				if(get(index) == p.get(index)) ret.set_unused(index, get(index));
			}
			return ret;
		}

		void fill_empties_if_unused(std::function<Type(Index)> value_by_index) {
			for(Index index : empty_indexes) {
				set_if_unused(index, value_by_index(index));
			}
		}

		void fill_empties_with_unused(std::function<std::vector<Index>(Set<Index>)> arrange_indexes) {
			std::vector<Index> arranged_indexes = arrange_indexes(empty_indexes);
			for(Index index : arranged_indexes) {
				set_unused(index, *unused_values.begin());
			}
			if(unused_values.size() || empty_indexes.size()) throw std::runtime_error("Invalid permutation.");
		}

		void swap(Index index1, Index index2) {
			std::swap(get(index1), get(index2));
		}

	};

}