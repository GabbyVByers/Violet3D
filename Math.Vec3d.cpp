
#include "Math.h"

Math::Vec3d::Vec3d() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Math::Vec3d::Vec3d(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Math::Vec3d::Vec3d(const Quaternion& quat, const Vec3d& basis_dir) {
	Quaternion quat_inv = quat.complexConjugate();
	Quaternion p = Quaternion(0.0, basis_dir.x, basis_dir.y, basis_dir.z);
	Quaternion result = quat * p * quat_inv;
	x = result.x;
	y = result.y;
	z = result.z;
}

Math::Vec3d Math::Vec3d::operator +  (const Vec3d& vec)   const { return { x + vec.x, y + vec.y, z + vec.z, }; }
Math::Vec3d Math::Vec3d::operator -  (const Vec3d& vec)   const { return { x - vec.x, y - vec.y, z - vec.z, }; }
Math::Vec3d Math::Vec3d::operator *  (const double scale) const { return { x * scale, y * scale, z * scale, }; }
Math::Vec3d Math::Vec3d::operator /  (const double scale) const { return { x / scale, y / scale, z / scale, }; }
void        Math::Vec3d::operator += (const Vec3d& vec)   { x += vec.x; y += vec.y; z += vec.z; }
void        Math::Vec3d::operator -= (const Vec3d& vec)   { x -= vec.x; y -= vec.y; z -= vec.z; }
void        Math::Vec3d::operator *= (const double scale) { x *= scale; y *= scale; z *= scale; }
void        Math::Vec3d::operator /= (const double scale) { x /= scale; y /= scale; z /= scale; }

Math::Vec3d Math::Vec3d::rotated(const Vec3d& axis, double theta) const {
	Quaternion rotation = Quaternion(axis, theta);
	return Vec3d(rotation, (*this));
}

Math::Vec3d Math::Vec3d::normalized() const {
	double len = length();
	return {
		x / len,
		y / len,
		z / len
	};
}

double Math::Vec3d::lengthSq() const {
	return (x * x) + (y * y) + (z * z);
}

double Math::Vec3d::length() const {
	return sqrt(lengthSq());
}

double Math::Vec3d::dot(const Vec3d& vec) const {
	return (x * vec.x) + (y * vec.y) + (z * vec.z);
}

Math::Vec3d Math::Vec3d::cross(const Vec3d& vec) const {
	return {
		(y * vec.z) - (z * vec.y),
		(z * vec.x) - (x * vec.z),
		(x * vec.y) - (y * vec.x)
	};
}

