#include "PermutationFA.h"
using namespace ro::fa;

PermutationFA::PermutationFA(std::shared_ptr<const PermutationElements> elements, const Options& opts) noexcept :
	opts(opts),
	mt(opts.seed),
	perms(elements, opts.n_perms),
	intensity_of_perms(opts.n_perms)
{}

void PermutationFA::iterate() noexcept {
	
	sortPerms();
	
	bool f_attracted = false;
	for(PermIndex i = 0; i < opts.n_perms; ++i){
		for(PermIndex j = 0; j < i; ++j) {
			f_attracted |= attract(i, j);
		}
	}

	if(!f_attracted) alphaPerms;

}

bool PermutationFA::attract(PermIndex i_target, PermIndex i_dest) noexcept {
	
	Permutation target = perms[i_target];
	const Permutation dest = perms[i_dest];

	if(!(opts.calc_intensity(target) > opts.calc_intensity(dest))) return false;

	double beta = 1 / (1 + opts.gamma * hamming_distance(i_target, i_dest));
	betaStep(i_target, i_dest);
	alphaStep(i_target);


}

void PermutationFA::betaStep(PermIndex i_p1, PermIndex i_p2) noexcept {



}