
/*
	Mesh.Camera.cpp
*/

#include "Mesh.h"

namespace Vi {

	Vec3d Camera::forward() const {
		Vec3d forward = Vec3d(0.0, 0.0, -1.0);
		return Vec3d::rotate(forward, orientation);
	}
	Vec3d Camera::up() const {
		Vec3d up = Vec3d(0.0, 1.0, 0.0);
		return Vec3d::rotate(up, orientation);
	}
	Vec3d Camera::right() const {
		Vec3d right = Vec3d(1.0, 0.0, 0.0);
		return Vec3d::rotate(right, orientation);
	}

	Mat4 Camera::view_matrix() const {
		Mat4 translation_matrix_inverse = Mat4::translation_matrix(position * -1.0);
		Mat4 rotation_matrix_inverse = Mat4::rotation_matrix(Quat::complex_conjugate(orientation));
		return rotation_matrix_inverse * translation_matrix_inverse;
	}
	Mat4 Camera::projection_matrix(const Vec2i& window_size) const {
		int width = window_size.x;
		int height = window_size.y;
		if (height == 0)
			height = 1;
		double aspect_ratio = (double)width / (double)height;
		double fov_radians = fov_degrees * std::numbers::pi / 180.0;
		double f = 1.0 / tan(fov_radians / 2.0);
		return {
			f / aspect_ratio, 0.0, 0.0, 0.0,
			0.0, f, 0.0, 0.0,
			0.0, 0.0, (far + near) / (near - far),
			(2.0 * far * near) / (near - far),
			0.0, 0.0, -1.0, 0.0
		};
	}
}

