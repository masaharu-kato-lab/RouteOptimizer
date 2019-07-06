#pragma once
#include <iostream>
#include <bitset>
#include <vector>
#include <random>
#include <functional>
#include "Bitstring.h"

namespace ga {

	//	Binary Genetic Algorithm class
	class BinaryGeneticAlgorithm {
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

		using IndividualIndex = uint32_t;

		using Crossover = std::function<void(const Individual&, const Individual&, Individual&, Individual&)>;
		using Mutation = std::function<void(Individual&)>;
		using FitnessFunction = std::function<Fitness(const Individual&)>;

	private:
		RandomSeed seed;			//	乱数シード値
		std::mt19937 mt;			//	乱数発生器
		BitIndex n_bits;			//	1個体のビット数
		Population population;		//	集団（個体の配列）
		size_t i_gen = 0;			//	現在の世代

	//	新しい個体(未初期化)を生成
		Individual& createIndividual();

	//	min 以上 max 以下の整数(ビット番号)を取得 
		BitIndex randomBitIndex(BitIndex i_min, BitIndex i_max)
		{
			return std::uniform_int_distribution<BitIndex>(i_min, i_max)(mt);
		}

	//	全個体の全ビットをシャッフルする
		void randomize(double probability_of_1 = 0.5)
		{
			//std::bernoulli_distribution d(probability_of_1);
			//for(auto& idv : population) {
			//	for(BitIndex i_bit = 0; i_bit < n_bits; ++i_bit){
			//		idv[i_bit] = d(mt);
			//	}
			//}
			for(auto& idv : population) idv.randomize();
		}

	//	一点交叉関数
		void single_point_crossover(IndividualIndex p1, IndividualIndex p2)
		{
			BitIndex i_border = randomBitIndex(0, n_bits);
			Individual& c1 = createIndividual();
			Individual& c2 = createIndividual();

			population[p1].copyBits(0, i_border, c1, 0).copyBits(i_border, n_bits, c2, i_border);
			population[p2].copyBits(0, i_border, c2, 0).copyBits(i_border, n_bits, c1, i_border);

		}

	//	二点交叉関数
		void double_point_crossover(IndividualIndex p1, IndividualIndex p2)
		{
			BitIndex i_beg = randomBitIndex(0, n_bits - 1);
			BitIndex i_end = randomBitIndex(i_beg + 1, n_bits);
			Individual& c1 = createIndividual();
			Individual& c2 = createIndividual();

			population[p1].copyBits(0, i_beg, c1, 0).copyBits(i_beg, i_end, c2, i_beg).copyBits(i_end, n_bits, c1, i_end);
			population[p2].copyBits(0, i_beg, c2, 0).copyBits(i_beg, i_end, c1, i_beg).copyBits(i_end, n_bits, c2, i_end);
		}

	//	一様交叉関数
		void uniform_crossover(IndividualIndex i1, IndividualIndex i2)
		{
			const Individual& p1 = population[i1];
			const Individual& p2 = population[i2];
			Individual& c1 = createIndividual();
			Individual& c2 = createIndividual();

			std::bernoulli_distribution d;
			for(BitIndex i_bit = 0; i_bit < n_bits; ++i_bit){
				if(d(mt)) {
					c1[i_bit] = p1[i_bit];
					c2[i_bit] = p2[i_bit];
				}else{
					c2[i_bit] = p1[i_bit];
					c1[i_bit] = p2[i_bit];
				}
			}
		}

	//	突然変異関数
		void random_index_mutation(Individual& idv)
		{
			BitIndex i_target = randomBitIndex(0, n_bits - 1);
			idv[i_target].flip();
		}

	//	ルーレット選択関数
		void proportionate_selection()
		{

		}

	public:
		explicit BinaryGeneticAlgorithm(BitIndex n_bits, RandomSeed seed)
			: seed(seed), mt(seed), n_bits(n_bits) {}

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
