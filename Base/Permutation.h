#pragma once
#include "PermutationTypes.h"
#include <vector>

namespace ro {

//	生の順列データを保持するクラス
	class Permutation {
	public:
		using Element = PermutationElement;
		using Index = PermutationIndex;
	
		Permutation(Index size) noexcept;	//	コンストラクタ（すべて未設定で初期化）
		Permutation(const Element* _data, Index size) noexcept;		//	コンストラクタ（既存の順列データから初期化）
		Permutation(const Permutation&) noexcept;		//	コピーコンストラクタ
		~Permutation() noexcept;		//	デストラクタ
		
		Index size() const noexcept;		//	順列を構成する要素の数を取得する
		Element  get        (Index index) const noexcept;	//	index の要素を取得する
		Element  operator [](Index index) const noexcept;	//	index の要素を取得
		Element& get        (Index index) noexcept;			//	index の変更可能な要素を取得する
		Element& operator [](Index index) noexcept;			//	index の変更可能な要素を取得する
		Element*       begin() noexcept;		//	開始ポインタを取得する
		const Element* begin() const noexcept;	//	開始constポインタを取得する
		Element*       end  () noexcept;		//	終了ポインタを取得する
		const Element* end  () const noexcept;	//	終了constポインタを取得する

		bool isset(Index index) const;		//	index が設定されているか返す
		void reset(Index index) noexcept;		//	index を未設定にする
		void reset() noexcept;		//	すべて未設定にする
		void set_directly(Index index, Element value)  noexcept;	//	直接（順列としての整合性を確認せずに）要素を設定する
		void swap(Index index1, Index index2);		//	index1 と index2 の要素を入れ替える
		
		bool is_valid(const Elements& elements) const noexcept;	//	順列としての整合性を確認する

		operator const Element*() const noexcept;	//	生データを取得する

	protected:
		Index data_size;
		Element* data;
	};

}