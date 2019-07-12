#pragma once
#include "PermutationValues.h"
#include <memory>
#include <vector>

namespace ro {

	template <class Type>
	class Permutation {
	public:
		using Index = PermutationValues<Type>::Index;

	protected:
		std::shared_ptr<PermutationValues<Type>> origin;
		Type* target;
		
	public:
	//	値を取得する
		Type get(Index index) const noexcept {
			return target[index];
		}
		
	//	変更可能な値を取得する
		Type& get(Index index) noexcept {
			return target[index];
		}
		
	//	コンストラクタ（すべて未設定で初期化）
		Permutation(const std::shared_ptr<PermutationValues<Type>>& origin) noexcept :
			origin(origin),
			target(new Type[origin->size()])
		{
			for(Index index = 0; index < _Base::size(); ++index) reset(index);
		}
		
	//	コンストラクタ（既存の配列から初期化）
		Permutation(const std::shared_ptr<PermutationValues<Type>>& origin, Type* target_ptr) noexcept :
			origin(origin),
			target(target_ptr)
		{}

	//	直接（順列としての整合性を確認せずに）値を設定する
		void set_directly(Index index, Type value)  noexcept {
			get(index) = value;
		}

	//	index 番目を未設定にする
		void reset(Index index) noexcept {
			origin->setDefault(get(index));
		}

	//	index 番目が設定されているか返す
		bool isset(Index index) const {
			return !origin->isDefault(get(index));
		}

	//	index1 と index2 を入れ替える
		void swap(Index index1, Index index2) {
			std::swap(get(index1), get(index2));
		}

	};

}