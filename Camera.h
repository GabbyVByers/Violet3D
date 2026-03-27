
#pragma once
#include "Vertex.h"

namespace Violet {

	class Camera {
	public:
		Camera();
		double fov_degrees;
		double near, far;
		Vec3d  position;
		Quat   orientation;

		static Vec3d forward_dir(const Camera& camera);
		static Vec3d up_dir(const Camera& camera);
		static Vec3d right_dir(const Camera& camera);
	};
}

