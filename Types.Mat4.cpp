
/*
	Types.Mat4.cpp
*/

#include "Types.h"

namespace Vi {

	Mat4::Mat4() {
		(*this) = {
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};
	}

	Mat4::Mat4(
		double a, double b, double c, double d,
		double e, double f, double g, double h,
		double i, double j, double k, double l,
		double m, double n, double o, double p
	) {
		data[0][0] = a; data[0][1] = b; data[0][2] = c; data[0][3] = d;
		data[1][0] = e; data[1][1] = f; data[1][2] = g; data[1][3] = h;
		data[2][0] = i; data[2][1] = j; data[2][2] = k; data[2][3] = l;
		data[3][0] = m; data[3][1] = n; data[3][2] = o; data[3][3] = p;
	}

	Mat4 Mat4::scalar_matrix(double scale) {
		double s = scale;
		return {
			s, 0, 0, 0,
			0, s, 0, 0,
			0, 0, s, 0,
			0, 0, 0, 1
		};
	}

	Mat4 Mat4::translation_matrix(const Vec3d& position) {
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

	Mat4 Mat4::rotation_matrix(const Quat& rotation_quat) {
		Quat rot_n = Quat::normalize(rotation_quat);
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

	Mat4 Mat4::operator * (const Mat4& matrix) const {
		Mat4 result;
		for (size_t i = 0; i < 4; i++) {
			for (size_t j = 0; j < 4; j++) {
				double sum = 0.0;
				for (size_t k = 0; k < 4; k++) {
					sum += data[i][k] * matrix.data[k][j];
				}
				result.data[i][j] = sum;
			}
		}
		return result;
	}
}

