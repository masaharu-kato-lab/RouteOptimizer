#include <iostream>
#include "../ImageUtil/Bitmap.h"

using namespace imgutil;

int main(void) {

	Bitmap bitmap(512, 256);

	for(uint32_t iy = 0; iy < 256; ++iy) {

		for(uint32_t ix = 0; ix < 256; ++ix) {
			
			bitmap.set({ix, iy}, Color(ix, 0, iy));

		}

		for(uint32_t ix = 256; ix < 512; ++ix) {

			bitmap.set({ix, iy}, Color(255, ix - 256, iy));

		}

	}

	bitmap.output("output.bmp");

	return 0;
};