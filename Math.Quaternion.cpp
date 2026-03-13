
#include "Math.h"

Math::Quaternion::Quaternion() {
	w = 1.0;
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Math::Quaternion::Quaternion(double w, double x, double y, double z) {
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}

Math::Quaternion::Quaternion(const Vec3d& axis, double theta) {
	Vec3d axis_n = axis.normalized();
	double half = theta * 0.5;
	double s = sin(half);
	w = cos(half);
	x = s * axis_n.x;
	y = s * axis_n.y;
	z = s * axis_n.z;
}

Math::Quaternion Math::Quaternion::normalized() const {
	double len = sqrt((w * w) + (x * x) + (y * y) + (z * z));
	return {
		w / len,
		x / len,
		y / len,
		z / len
	};
}

Math::Quaternion Math::Quaternion::complexConjugate() const {
	return {
		w,
	   -x,
	   -y,
	   -z
	};
}

Math::Quaternion Math::Quaternion::operator * (const Quaternion& q) const {
	return {
		(w * q.w) - (x * q.x) - (y * q.y) - (z * q.z),
		(w * q.x) + (x * q.w) + (y * q.z) - (z * q.y),
		(w * q.y) - (x * q.z) + (y * q.w) + (z * q.x),
		(w * q.z) + (x * q.y) - (y * q.x) + (z * q.w)
	};
}

