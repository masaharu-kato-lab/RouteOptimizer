#pragma once
#include <vector>
#include <random> 
#include <functional>
#include "../Base/Point.h"
#include "../Base/PermutationHelper.h"
#include "../Base/PermutationArray.h"

namespace ro::fa {

	class PermutationFA {
	public:
		using Element = PermutationElement;
		using PermIndex = PermutationArray::Index;
		using Intensity = double;
		using IntensityFunction = std::function<Intensity(Permutation)>;

		struct Options {
			PermIndex n_perms;
			double gamma;
			double alpha;
			double blocked_alpha;
			IntensityFunction calc_intensity;
			size_t n_iteration;
			unsigned int seed;
		};


		PermutationFA(std::shared_ptr<const PermutationElements> elements, const Options& opts) noexcept;

	//	初期解を生成する
		void generate() noexcept;

	//	1世代更新する
		void iterate() noexcept;

	//	n_iteration 世代更新する
		void run() noexcept;

	//	蛍をソートする
		void sortPerms() noexcept;

	//	現在の最適解を取得
		Permutation getOptimal() const noexcept;

	//	オプション情報を取得
		Options getOptions() const noexcept;

	private:
		Options opts;
		std::mt19937 mt;
		PermutationArray perms;

	//	蛍 target を dest に近づける
		bool attract(PermIndex i_target, PermIndex i_dest) noexcept;

	//	βステップ（惹きつけ操作）を行う
		void betaStep(PermIndex i_p1, PermIndex i_p2) noexcept;
		
	//	αステップ（ランダム組み換え操作）を行う
		void alphaStep(PermIndex i_target) noexcept;

	//	すべての蛍について αステップを行う
		void alphaPerms() noexcept;

	//	ハミング距離を計算する
		PermutationIndex hamming_distance(PermIndex i_p1, PermIndex i_p2) const noexcept;


	};

}