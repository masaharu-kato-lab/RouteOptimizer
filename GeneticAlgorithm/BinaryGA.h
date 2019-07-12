#pragma once
#include <iostream>
#include <bitset>
#include <vector>
#include <random>
#include <functional>
#include "Bitstring.h"

namespace ro::ga {

	//	Binary Genetic Algorithm class
	class BinaryGA {
	public:

		using RandomSeed = unsigned int;
		using BitIndex = Bitstring::BitIndex;
		using Fitness = double;

	//	個体クラス（適合度を持つ）
		class Individual : public Bitstring {
		public:
			Fitness fitness();

			bool operator <(const Individual&) const;
		};
		
		using Population = std::vector<Individual>;

		using IndivIndex = uint32_t;

		using Crossover = std::function<void(const Individual&, const Individual&, Individual&, Individual&)>;
		using Mutation = std::function<void(Individual&)>;
		using FitnessFunction = std::function<Fitness(const Individual&)>;

	protected:
		RandomSeed seed;			//	乱数シード値
		std::mt19937 mt;			//	乱数発生器
		BitIndex bit_length;		//	1個体のビット長
		Population population;		//	集団（個体の配列）
		size_t i_gen = 0;			//	現在の世代

	//	新しい個体(未初期化)を生成
		Individual& createIndividual();

	//	min 以上 max 以下の整数(ビット番号)を取得 
		BitIndex randomBitIndex(BitIndex i_min, BitIndex i_max);

	//	全個体の全ビットをシャッフルする
		void randomize(double probability_of_1 = 0.5);

	//	一点交叉関数
		void single_point_crossover(IndivIndex p1, IndivIndex p2);

	//	二点交叉関数
		void double_point_crossover(IndivIndex p1, IndivIndex p2);

	//	一様交叉関数
		void uniform_crossover(IndivIndex i1, IndivIndex i2);

	//	ブロック交叉関数
		void block_crossover(IndivIndex i1, IndivIndex i2);

	//	突然変異関数
		void random_index_mutation(Individual& idv);

	//	ルーレット選択関数
		void proportionate_selection();

	public:
		explicit BinaryGA(BitIndex, RandomSeed);

	//	初期個体の生成
		virtual void initialize() = 0;

	//	交叉
		virtual void crossover() = 0;

	//	突然変異
		virtual void mutation() = 0;

	//	選択
		virtual void selection() = 0;

	};

};
