
#include "Rendermath.h"

Violet::Mat4 Violet::Math::model_matrix(const Mesh& mesh) {
	Mat4 scalar_matrix = Math::scalar_matrix(mesh.transform.scale);
	Mat4 translation_matrix = Math::translation_matrix(mesh.transform.position);
	Mat4 rotation_matrix = Math::rotation_matrix(mesh.transform.orientation);
	return translation_matrix * scalar_matrix * rotation_matrix;
}

Violet::Mat4 Violet::Math::view_matrix(const Camera& camera) {
	Mat4 translation_matrix_inverse = Math::translation_matrix(camera.position);
	Mat4 rotation_matrix_inverse = Math::rotation_matrix(Quat::complex_conjugate(camera.orientation));
	return rotation_matrix_inverse * translation_matrix_inverse;
}

Violet::Mat4 Violet::Math::projection_matrix(const Camera& camera, const Vec2i& window_size) {
	int width = window_size.x;
	int height = window_size.y;
	if (height == 0)
		height = 1;
	double aspect_ratio = (double)width / (double)height;
	double fov_radians = camera.fov_degrees * Math::Pi64 / 180.0;
	double f = 1.0 / tan(fov_radians / 2.0);
	return {
		f / aspect_ratio, 0.0, 0.0, 0.0,
		0.0, f, 0.0, 0.0,
		0.0, 0.0, (camera.far + camera.near) / (camera.near - camera.far),
		(2.0 * camera.far * camera.near) / (camera.near - camera.far),
		0.0, 0.0, -1.0, 0.0
	};
}

Violet::Mat4 Violet::Math::scalar_matrix(double scale) {
	double s = scale;
	return {
		s, 0, 0, 0,
		0, s, 0, 0,
		0, 0, s, 0,
		0, 0, 0, 1
	};
}

Violet::Mat4 Violet::Math::translation_matrix(const Violet::Vec3d& position) {
	const double x = position.x;
	const double y = position.y;
	const double z = position.z;
	return {
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1
	};
}

Violet::Mat4 Violet::Math::rotation_matrix(const Violet::Quat& rotation) {
	Quat rot_n = Quat::normalize(rotation);
	double xw = rot_n.x * rot_n.w;
	double xx = rot_n.x * rot_n.x;
	double xy = rot_n.x * rot_n.y;
	double xz = rot_n.x * rot_n.z;
	double yw = rot_n.y * rot_n.w;
	double yy = rot_n.y * rot_n.y;
	double yz = rot_n.y * rot_n.z;
	double zw = rot_n.z * rot_n.w;
	double zz = rot_n.z * rot_n.z;
	return {
		1 - 2 * (yy + zz), 2 * (xy - zw), 2 * (xz + yw), 0,
		2 * (xy + zw), 1 - 2 * (xx + zz), 2 * (yz - xw), 0,
		2 * (xz - yw), 2 * (yz + xw), 1 - 2 * (xx + yy), 0,
		0, 0, 0, 1
	};
}

Violet::Mat4f Violet::Math::float_matrix(const Mat4& matrix) {
	Mat4f matrix_f;
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			matrix_f.data[i][j] = (float)matrix.data[i][j];
		}
	}
	return matrix_f;
}

