#include "PermutationIntensityArray.h"

using namespace ro;
using namespace ro::fa;

PermutationIntensityArray::PermutationIntensityArray(
	std::shared_ptr<const Elements> elements,
	Index n_data,
	IntensityFunction calc_intensity
) noexcept :
	PermutationArray(elements, n_data),
	f_changed(new bool[n_data]),
	intensities(new Intensity[n_data]),
	calc_intensity(calc_intensity)
{
	std::fill(f_changed, f_changed + n_data, true);
}

PermutationIntensityArray::~PermutationIntensityArray() {
	delete[] f_changed;
	delete[] intensities;
}

void PermutationIntensityArray::onchange(Index index) noexcept {
	f_changed[index] = true;
}

Intensity PermutationIntensityArray::getIntensity(Index index) noexcept {
	if(f_changed[index]){
		intensities[index] = calc_intensity(index);
		f_changed[index] = false;
	}
	return intensities[index];
}