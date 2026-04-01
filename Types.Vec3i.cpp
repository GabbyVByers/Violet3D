
/*
	Types.Vec3i.cpp
*/

#include "Types.h"

namespace Vi {

	Vec3i::Vec3i() { x = 0; y = 0; z = 0; }
	Vec3i::Vec3i(int x, int y, int z) { this->x = x; this->y = y; this->z = z; }
	Vec3i::Vec3i(const Vec3i& vec) { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; };
	Vec3i::Vec3i(const Vec3f& vec) { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; };
	Vec3i::Vec3i(const Vec3d& vec) { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; };
	Vec3i::Vec3i(Vec3i&& vec) noexcept { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; };
	Vec3i::Vec3i(Vec3f&& vec) noexcept { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; };
	Vec3i::Vec3i(Vec3d&& vec) noexcept { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; };

	Vec3i Vec3i::xpos() { return Vec3i( 1, 0, 0); }
	Vec3i Vec3i::xneg() { return Vec3i(-1, 0, 0); }
	Vec3i Vec3i::ypos() { return Vec3i( 0, 1, 0); }
	Vec3i Vec3i::yneg() { return Vec3i( 0,-1, 0); }
	Vec3i Vec3i::zpos() { return Vec3i( 0, 0, 1); }
	Vec3i Vec3i::zneg() { return Vec3i( 0, 0,-1); }
	int Vec3i::hypot(const Vec3i& vec) { return (int)std::hypot(vec.x, vec.y, vec.z); }
	int Vec3i::dot(const Vec3i& a, const Vec3i& b) { return (a.x * b.x) + (a.y * b.y) + (a.z * b.z); }
	Vec3i Vec3i::cross(const Vec3i& a, const Vec3i& b) {
		return {
			(a.y * b.z) - (a.z * b.y),
			(a.z * b.x) - (a.x * b.z),
			(a.x * b.y) - (a.y * b.x)
		};
	}

	Vec3i& Vec3i::operator = (const Vec3i& vec) { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; return *this; }
	Vec3i& Vec3i::operator = (const Vec3f& vec) { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; return *this; }
	Vec3i& Vec3i::operator = (const Vec3d& vec) { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; return *this; }
	Vec3i& Vec3i::operator = (Vec3i&& vec) noexcept { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; return *this; }
	Vec3i& Vec3i::operator = (Vec3f&& vec) noexcept { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; return *this; }
	Vec3i& Vec3i::operator = (Vec3d&& vec) noexcept { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; return *this; }
	Vec3i Vec3i::operator +  (const Vec3i& vec) const { return { x + vec.x, y + vec.y, z + vec.z }; }
	Vec3i Vec3i::operator -  (const Vec3i& vec) const { return { x - vec.x, y - vec.y, z - vec.z }; }
	Vec3i Vec3i::operator *  (const int scale)  const { return { x * scale, y * scale, z * scale }; }
	Vec3i Vec3i::operator /  (const int scale)  const { return { x / scale, y / scale, z / scale }; }
	void  Vec3i::operator += (const Vec3i& vec) { x += vec.x; y += vec.y; z += vec.z; }
	void  Vec3i::operator -= (const Vec3i& vec) { x -= vec.x; y -= vec.y; z -= vec.z; }
	void  Vec3i::operator *= (const int scale)  { x *= scale; y *= scale; z *= scale; }
	void  Vec3i::operator /= (const int scale)  { x /= scale; y /= scale; z /= scale; }
}

