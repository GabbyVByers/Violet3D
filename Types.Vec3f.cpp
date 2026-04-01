
/*
	Types.Vec3f.cpp
*/

#include "Types.h"

namespace Violet {

	Vec3f::Vec3f() { x = 0.0f; y = 0.0f; z = 0.0f; }
	Vec3f::Vec3f(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
	Vec3f::Vec3f(const Vec3i& vec) { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; };
	Vec3f::Vec3f(const Vec3f& vec) { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; };
	Vec3f::Vec3f(const Vec3d& vec) { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; };
	Vec3f::Vec3f(Vec3i&& vec) noexcept { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; };
	Vec3f::Vec3f(Vec3f&& vec) noexcept { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; };
	Vec3f::Vec3f(Vec3d&& vec) noexcept { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; };

	Vec3f Vec3f::xpos() { return Vec3f( 1.0f, 0.0f, 0.0f); }
	Vec3f Vec3f::xneg() { return Vec3f(-1.0f, 0.0f, 0.0f); }
	Vec3f Vec3f::ypos() { return Vec3f( 0.0f, 1.0f, 0.0f); }
	Vec3f Vec3f::yneg() { return Vec3f( 0.0f,-1.0f, 0.0f); }
	Vec3f Vec3f::zpos() { return Vec3f( 0.0f, 0.0f, 1.0f); }
	Vec3f Vec3f::zneg() { return Vec3f( 0.0f, 0.0f,-1.0f); }
	float Vec3f::hypot(const Vec3f& vec) { return std::hypot(vec.x, vec.y, vec.z); }
	float Vec3f::dot(const Vec3f& a, const Vec3f& b) { return (a.x * b.x) + (a.y * b.y) + (a.z * b.z); }
	Vec3f Vec3f::cross(const Vec3f& a, const Vec3f& b) {
		return {
			(a.y * b.z) - (a.z * b.y),
			(a.z * b.x) - (a.x * b.z),
			(a.x * b.y) - (a.y * b.x)
		};
	}
	Vec3f Vec3f::normalize(const Vec3f& vec) {
		float len = hypot(vec);
		if (len == 0.0f)
			return Vec3f();
		return {
			vec.x / len,
			vec.y / len,
			vec.z / len
		};
	}
	Vec3f Vec3f::rotate(const Vec3f& vec, const Vec3i& axis, float  theta) {
		Quat rotation = Quat::rotation(axis, theta);
		return rotate(vec, rotation);
	}
	Vec3f Vec3f::rotate(const Vec3f& vec, const Vec3f& axis, float  theta) {
		Quat rotation = Quat::rotation(axis, theta);
		return rotate(vec, rotation);
	}
	Vec3f Vec3f::rotate(const Vec3f& vec, const Quat& rotation_quat) {
		Quat q_inv = Quat::complex_conjugate(rotation_quat);
		Quat p = { 0.0, vec.x, vec.y, vec.z };
		Quat result_quat = rotation_quat * p * q_inv;
		return {
			(float)result_quat.x,
			(float)result_quat.y,
			(float)result_quat.z
		};
	}

	Vec3f& Vec3f::operator = (const Vec3i& vec) { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; return *this; }
	Vec3f& Vec3f::operator = (const Vec3f& vec) { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; return *this; }
	Vec3f& Vec3f::operator = (const Vec3d& vec) { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; return *this; }
	Vec3f& Vec3f::operator = (Vec3i&& vec) noexcept { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; return *this; }
	Vec3f& Vec3f::operator = (Vec3f&& vec) noexcept { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; return *this; }
	Vec3f& Vec3f::operator = (Vec3d&& vec) noexcept { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; return *this; }
	Vec3f Vec3f::operator +  (const Vec3f& vec)  const { return { x + vec.x, y + vec.y, z + vec.z }; }
	Vec3f Vec3f::operator -  (const Vec3f& vec)  const { return { x - vec.x, y - vec.y, z - vec.z }; }
	Vec3f Vec3f::operator *  (const float scale) const { return { x * scale, y * scale, z * scale }; }
	Vec3f Vec3f::operator /  (const float scale) const { return { x / scale, y / scale, z / scale }; }
	void  Vec3f::operator += (const Vec3f& vec)  { x += vec.x; y += vec.y; z += vec.z; }
	void  Vec3f::operator -= (const Vec3f& vec)  { x -= vec.x; y -= vec.y; z -= vec.z; }
	void  Vec3f::operator *= (const float scale) { x *= scale; y *= scale; z *= scale; }
	void  Vec3f::operator /= (const float scale) { x /= scale; y /= scale; z /= scale; }
}

