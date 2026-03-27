
#pragma once
#include "Shapes.h"

namespace Violet {
	namespace Math {

		Mat4  model_matrix(const Mesh& mesh);
		Mat4  view_matrix(const Camera& camera);
		Mat4  projection_matrix(const Camera& camera, const Vec2i& window_size);

		Mat4  scalar_matrix(double scale);
		Mat4  translation_matrix(const Vec3d& position);
		Mat4  rotation_matrix(const Quat& rotation);
		Mat4f float_matrix(const Mat4& matrix);
	}
}

