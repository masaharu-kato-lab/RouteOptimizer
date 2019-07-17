#pragma once
#include "types.h"
#include "../Base/PermutationArray.h"
#include <functional>

namespace ro::fa {

	class PermutationIntensityArray : public PermutationArray {
	public:
		PermutationIntensityArray(
			std::shared_ptr<const Elements> elements,
			Index n_data,
			IntensityFunction calc_intensity
		) noexcept;
		~PermutationIntensityArray();

		void onchange(Index index) noexcept override;

		Intensity getIntensity(Index index) noexcept;

	private:
		bool* f_changed;
		Intensity* intensities;
		IntensityFunction calc_intensity;
	};

}