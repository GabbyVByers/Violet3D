
#include "Vector.h"

Violet::Vec3d::Vec3d() { x = 0.0; y = 0.0; z = 0.0; }
Violet::Vec3d::Vec3d(double x, double y, double z) { this->x = x; this->y = y; this->z = z; }

/*
double Violet::Vec3d::lengthSq(const Vec3d& vec) {
	return (vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z);
}

double Violet::Vec3d::length(const Vec3d& vec) {
	return sqrt(lengthSq(vec));
}

void Violet::Vec3d::normalize() {
	double len = Vec3d::length(*this);
	x /= len;
	y /= len;
	z /= len;
}

void Violet::Vec3d::rotate(const Vec3d& axis, double theta) {
	Quaternion rotation = Quaternion::buildRotationQuaternion(axis, theta);
	rotate(rotation);
}

void Violet::Vec3d::rotate(const Quaternion& quat) {
	Quaternion q_inv = Quaternion::complexConjugate(quat);
	Quaternion p = { 0.0, x, y, z };
	Quaternion qpq_inv = quat * p * q_inv;
	x = qpq_inv.x;
	y = qpq_inv.y;
	z = qpq_inv.z;
}

double Violet::Vec3d::dot(const Vec3d& a, const Vec3d& b) {
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Violet::Vec3d Violet::Vec3d::cross(const Vec3d& a, const Vec3d& b) {
	return {
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x)
	};
}
*/

Violet::Vec3d& Violet::Vec3d::operator = (const Violet::Vec3i& vec) { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; }
Violet::Vec3d& Violet::Vec3d::operator = (const Violet::Vec3f& vec) { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; }
Violet::Vec3d& Violet::Vec3d::operator = (const Violet::Vec3d& vec) { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; }

Violet::Vec3d Violet::Vec3d::operator +  (const Vec3d& vec)   const { return { x + vec.x, y + vec.y, z + vec.z }; }
Violet::Vec3d Violet::Vec3d::operator -  (const Vec3d& vec)   const { return { x - vec.x, y - vec.y, z - vec.z }; }
Violet::Vec3d Violet::Vec3d::operator *  (const double scale) const { return { x * scale, y * scale, z * scale }; }
Violet::Vec3d Violet::Vec3d::operator /  (const double scale) const { return { x / scale, y / scale, z / scale }; }
void          Violet::Vec3d::operator += (const Vec3d& vec)   { x += vec.x; y += vec.y; z += vec.z; }
void          Violet::Vec3d::operator -= (const Vec3d& vec)   { x -= vec.x; y -= vec.y; z -= vec.z; }
void          Violet::Vec3d::operator *= (const double scale) { x *= scale; y *= scale; z *= scale; }
void          Violet::Vec3d::operator /= (const double scale) { x /= scale; y /= scale; z /= scale; }

