
/*
	Types.Vec2i.cpp
*/

#include "Types.h"

namespace Vi {

	Vec2i::Vec2i() { x = 0; y = 0; }
	Vec2i::Vec2i(int x, int y) { this->x = x; this->y = y; }
	Vec2i::Vec2i(const Vec2i& vec) { x = (int)vec.x; y = (int)vec.y; };
	Vec2i::Vec2i(const Vec2f& vec) { x = (int)vec.x; y = (int)vec.y; };
	Vec2i::Vec2i(const Vec2d& vec) { x = (int)vec.x; y = (int)vec.y; };
	Vec2i::Vec2i(Vec2i&& vec) noexcept { x = (int)vec.x; y = (int)vec.y; };
	Vec2i::Vec2i(Vec2f&& vec) noexcept { x = (int)vec.x; y = (int)vec.y; };
	Vec2i::Vec2i(Vec2d&& vec) noexcept { x = (int)vec.x; y = (int)vec.y; };

	int Vec2i::hypot(const Vec2i& vec) { return (int)std::hypot(vec.x, vec.y); }
	int Vec2i::dot(const Vec2i& a, const Vec2i& b) { return (a.x * b.x) + (a.y * b.y); }
	int Vec2i::cross(const Vec2i& a, const Vec2i& b) { return (a.x * b.y) - (a.y * b.x); }

	Vec2i& Vec2i::operator = (const Vec2i& vec) { x = (int)vec.x; y = (int)vec.y; return *this; }
	Vec2i& Vec2i::operator = (const Vec2f& vec) { x = (int)vec.x; y = (int)vec.y; return *this; }
	Vec2i& Vec2i::operator = (const Vec2d& vec) { x = (int)vec.x; y = (int)vec.y; return *this; }
	Vec2i& Vec2i::operator = (Vec2i&& vec) noexcept { x = (int)vec.x; y = (int)vec.y; return *this; }
	Vec2i& Vec2i::operator = (Vec2f&& vec) noexcept { x = (int)vec.x; y = (int)vec.y; return *this; }
	Vec2i& Vec2i::operator = (Vec2d&& vec) noexcept { x = (int)vec.x; y = (int)vec.y; return *this; }
	Vec2i Vec2i::operator +  (const Vec2i& vec) const { return { x + vec.x, y + vec.y }; }
	Vec2i Vec2i::operator -  (const Vec2i& vec) const { return { x - vec.x, y - vec.y }; }
	Vec2i Vec2i::operator *  (const int scale)  const { return { x * scale, y * scale }; }
	Vec2i Vec2i::operator /  (const int scale)  const { return { x / scale, y / scale }; }
	void  Vec2i::operator += (const Vec2i& vec) { x += vec.x; y += vec.y; }
	void  Vec2i::operator -= (const Vec2i& vec) { x -= vec.x; y -= vec.y; }
	void  Vec2i::operator *= (const int scale)  { x *= scale; y *= scale; }
	void  Vec2i::operator /= (const int scale)  { x /= scale; y /= scale; }
}

