
/*
	Types.Quat.cpp
*/

#include "Types.h"

namespace Vi {

	Quat::Quat() {
		w = 1.0;
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}

	Quat::Quat(double w, double x, double y, double z) {
		this->w = w;
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Quat Quat::normalize(const Quat& quat) {
		double length = std::hypot(quat.w, std::hypot(quat.x, quat.y, quat.z));
		if (length == 0.0)
			return Quat();
		return {
			quat.w / length,
			quat.x / length,
			quat.y / length,
			quat.z / length
		};
	}

	Quat Quat::complex_conjugate(const Quat& quat) {
		return {
			quat.w,
			-quat.x,
			-quat.y,
			-quat.z
		};
	}

	Quat Quat::rotation(const Vec3i& axis, double theta) {
		double half = theta * 0.5;
		double s = sin(half);
		return {
			cos(half),
			s * (double)axis.x,
			s * (double)axis.y,
			s * (double)axis.z
		};
	}

	Quat Quat::rotation(const Vec3f& axis, double theta) {
		Vec3f axis_n = Vec3f::normalize(axis);
		double half = theta * 0.5;
		double s = sin(half);
		return {
			cos(half),
			s * (double)axis_n.x,
			s * (double)axis_n.y,
			s * (double)axis_n.z
		};
	}

	Quat Quat::rotation(const Vec3d& axis, double theta) {
		Vec3d axis_n = Vec3d::normalize(axis);
		double half = theta * 0.5;
		double s = sin(half);
		return {
			cos(half),
			s * axis_n.x,
			s * axis_n.y,
			s * axis_n.z
		};
	}

	Quat Quat::operator * (const Quat& q) const {
		return {
			(w * q.w) - (x * q.x) - (y * q.y) - (z * q.z),
			(w * q.x) + (x * q.w) + (y * q.z) - (z * q.y),
			(w * q.y) - (x * q.z) + (y * q.w) + (z * q.x),
			(w * q.z) + (x * q.y) - (y * q.x) + (z * q.w)
		};
	}
}

