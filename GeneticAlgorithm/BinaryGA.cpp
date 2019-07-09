#include "BinaryGA.h"
using namespace ga;

auto BinaryGA::createIndividual() -> Individual&
{
	population.emplace_back(bit_length);
	return population[population.size() - 1];
}

auto BinaryGA::randomBitIndex(BitIndex i_min, BitIndex i_max) -> BitIndex
{
	return std::uniform_int_distribution<BitIndex>(i_min, i_max)(mt);
}

void BinaryGA::randomize(double probability_of_1 = 0.5)
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
void BinaryGA::single_point_crossover(IndividualIndex p1, IndividualIndex p2)
{
	BitIndex i_border = randomBitIndex(0, bit_length);
	Individual& c1 = createIndividual();
	Individual& c2 = createIndividual();

	population[p1].copyBits(0, i_border, c1, 0).copyBits(i_border, bit_length, c2, i_border);
	population[p2].copyBits(0, i_border, c2, 0).copyBits(i_border, bit_length, c1, i_border);

}

//	二点交叉関数
void BinaryGA::double_point_crossover(IndividualIndex p1, IndividualIndex p2)
{
	BitIndex i_beg = randomBitIndex(0, bit_length - 1);
	BitIndex i_end = randomBitIndex(i_beg + 1, bit_length);
	Individual& c1 = createIndividual();
	Individual& c2 = createIndividual();

	population[p1].copyBits(0, i_beg, c1, 0).copyBits(i_beg, i_end, c2, i_beg).copyBits(i_end, bit_length, c1, i_end);
	population[p2].copyBits(0, i_beg, c2, 0).copyBits(i_beg, i_end, c1, i_beg).copyBits(i_end, bit_length, c2, i_end);
}

//	一様交叉関数
void BinaryGA::uniform_crossover(IndividualIndex i1, IndividualIndex i2)
{
	const Individual& p1 = population[i1];
	const Individual& p2 = population[i2];
	Individual& c1 = createIndividual();
	Individual& c2 = createIndividual();

	std::bernoulli_distribution d;
	for(BitIndex i_bit = 0; i_bit < bit_length; ++i_bit){
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
void BinaryGA::random_index_mutation(Individual& idv)
{
	BitIndex i_target = randomBitIndex(0, bit_length - 1);
	idv[i_target].flip();
}

//	ルーレット選択関数
void BinaryGA::proportionate_selection()
{
	Fitness sum_fitness = 0;

}

BinaryGA::BinaryGA(BitIndex bit_length, RandomSeed seed)
	: seed(seed), mt(seed), bit_length(bit_length) {}