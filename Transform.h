
#pragma once
#include "Vec3.h"
#include "Quat.h"

namespace Violet {

	class Transform {
	public:
		double scale = 1.0;
		Vec3d position = Vec3d();
		Quat orientation = Quat();
	};
}

