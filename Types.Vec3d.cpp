
/*
	Types.Vec3d.cpp
*/

#include "Types.h"

namespace Vi {

	Vec3d::Vec3d() { x = 0.0; y = 0.0; z = 0.0; }
	Vec3d::Vec3d(double x, double y, double z) { this->x = x; this->y = y; this->z = z; }
	Vec3d::Vec3d(const Vec3i& vec) { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; };
	Vec3d::Vec3d(const Vec3f& vec) { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; };
	Vec3d::Vec3d(const Vec3d& vec) { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; };
	Vec3d::Vec3d(Vec3i&& vec) noexcept { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; };
	Vec3d::Vec3d(Vec3f&& vec) noexcept { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; };
	Vec3d::Vec3d(Vec3d&& vec) noexcept { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; };

	Vec3d Vec3d::xpos() { return Vec3d( 1.0, 0.0, 0.0); }
	Vec3d Vec3d::xneg() { return Vec3d(-1.0, 0.0, 0.0); }
	Vec3d Vec3d::ypos() { return Vec3d( 0.0, 1.0, 0.0); }
	Vec3d Vec3d::yneg() { return Vec3d( 0.0,-1.0, 0.0); }
	Vec3d Vec3d::zpos() { return Vec3d( 0.0, 0.0, 1.0); }
	Vec3d Vec3d::zneg() { return Vec3d( 0.0, 0.0,-1.0); }
	double Vec3d::hypot(const Vec3d& vec) { return std::hypot(vec.x, vec.y, vec.z); }
	double Vec3d::dot(const Vec3d& a, const Vec3d& b) { return (a.x * b.x) + (a.y * b.y) + (a.z * b.z); }
	Vec3d Vec3d::cross(const Vec3d& a, const Vec3d& b) {
		return {
			(a.y * b.z) - (a.z * b.y),
			(a.z * b.x) - (a.x * b.z),
			(a.x * b.y) - (a.y * b.x)
		};
	}
	Vec3d Vec3d::normalize(const Vec3d& vec) {
		double len = hypot(vec);
		if (len == 0.0)
			return Vec3d();
		return {
			vec.x / len,
			vec.y / len,
			vec.z / len
		};
	}
	Vec3d Vec3d::rotate(const Vec3d& vec, const Vec3i& axis, double theta) {
		Quat rotation = Quat::rotation(axis, theta);
		return rotate(vec, rotation);
	}
	Vec3d Vec3d::rotate(const Vec3d& vec, const Vec3d& axis, double theta) {
		Quat rotation = Quat::rotation(axis, theta);
		return rotate(vec, rotation);
	}
	Vec3d Vec3d::rotate(const Vec3d& vec, const Quat& rotation_quat) {
		Quat q_inv = Quat::complex_conjugate(rotation_quat);
		Quat p = { 0.0, vec.x, vec.y, vec.z };
		Quat result_quat = rotation_quat * p * q_inv;
		return {
			result_quat.x,
			result_quat.y,
			result_quat.z
		};
	}

	Vec3d& Vec3d::operator = (const Vec3i& vec) { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; return *this; }
	Vec3d& Vec3d::operator = (const Vec3f& vec) { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; return *this; }
	Vec3d& Vec3d::operator = (const Vec3d& vec) { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; return *this; }
	Vec3d& Vec3d::operator = (Vec3i&& vec) noexcept { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; return *this; }
	Vec3d& Vec3d::operator = (Vec3f&& vec) noexcept { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; return *this; }
	Vec3d& Vec3d::operator = (Vec3d&& vec) noexcept { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; return *this; }
	Vec3d Vec3d::operator +  (const Vec3d& vec)   const { return { x + vec.x, y + vec.y, z + vec.z }; }
	Vec3d Vec3d::operator -  (const Vec3d& vec)   const { return { x - vec.x, y - vec.y, z - vec.z }; }
	Vec3d Vec3d::operator *  (const double scale) const { return { x * scale, y * scale, z * scale }; }
	Vec3d Vec3d::operator /  (const double scale) const { return { x / scale, y / scale, z / scale }; }
	void  Vec3d::operator += (const Vec3d& vec)   { x += vec.x; y += vec.y; z += vec.z; }
	void  Vec3d::operator -= (const Vec3d& vec)   { x -= vec.x; y -= vec.y; z -= vec.z; }
	void  Vec3d::operator *= (const double scale) { x *= scale; y *= scale; z *= scale; }
	void  Vec3d::operator /= (const double scale) { x /= scale; y /= scale; z /= scale; }
}

