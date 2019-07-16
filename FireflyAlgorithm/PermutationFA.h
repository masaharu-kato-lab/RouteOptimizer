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

	//	�������𐶐�����
		void generate() noexcept;

	//	1����X�V����
		void iterate() noexcept;

	//	n_iteration ����X�V����
		void run() noexcept;

	//	�u���\�[�g����
		void sortPerms() noexcept;

	//	���݂̍œK�����擾
		Permutation getOptimal() const noexcept;

	//	�I�v�V���������擾
		Options getOptions() const noexcept;

	private:
		Options opts;
		std::mt19937 mt;
		PermutationArray perms;

	//	�u target �� dest �ɋ߂Â���
		bool attract(PermIndex i_target, PermIndex i_dest) noexcept;

	//	���X�e�b�v�i�䂫������j���s��
		void betaStep(PermIndex i_p1, PermIndex i_p2) noexcept;
		
	//	���X�e�b�v�i�����_���g�݊�������j���s��
		void alphaStep(PermIndex i_target) noexcept;

	//	���ׂĂ̌u�ɂ��� ���X�e�b�v���s��
		void alphaPerms() noexcept;

	//	�n�~���O�������v�Z����
		PermutationIndex hamming_distance(PermIndex i_p1, PermIndex i_p2) const noexcept;


	};

}