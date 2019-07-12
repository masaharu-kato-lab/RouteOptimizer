#pragma once
#include "../Base/Point.h"
#include "../ImageUtil/Bitmap.h"

namespace ro::pg {

	class PointGenerator {
	public:
		PointGenerator(const ro::iu::Bitmap& bitmap);

	private:
		ro::iu::Bitmap bitmap;
	};

}