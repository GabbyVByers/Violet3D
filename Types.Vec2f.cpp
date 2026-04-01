
/*
	Types.Vec2f.cpp
*/

#include "Types.h"

namespace Violet {

	Violet::Vec2f::Vec2f() { x = 0.0f; y = 0.0f; }
	Violet::Vec2f::Vec2f(float x, float y) { this->x = x; this->y = y; }
	Vec2f::Vec2f(const Vec2i& vec) { x = (float)vec.x; y = (float)vec.y; };
	Vec2f::Vec2f(const Vec2f& vec) { x = (float)vec.x; y = (float)vec.y; };
	Vec2f::Vec2f(const Vec2d& vec) { x = (float)vec.x; y = (float)vec.y; };
	Vec2f::Vec2f(Vec2i&& vec) noexcept { x = (float)vec.x; y = (float)vec.y; };
	Vec2f::Vec2f(Vec2f&& vec) noexcept { x = (float)vec.x; y = (float)vec.y; };
	Vec2f::Vec2f(Vec2d&& vec) noexcept { x = (float)vec.x; y = (float)vec.y; };

	float Violet::Vec2f::hypot(const Vec2f& vec) { return std::hypot(vec.x, vec.y); }
	float Violet::Vec2f::dot(const Vec2f& a, const Vec2f& b) { return (a.x * b.x) + (a.y * b.y); }
	float Violet::Vec2f::cross(const Vec2f& a, const Vec2f& b) { return (a.x * b.y) - (a.y * b.x); }
	Violet::Vec2f Violet::Vec2f::normalize(const Vec2f& vec) {
		float len = hypot(vec);
		if (len == 0.0f)
			return Vec2f();
		return {
			vec.x / len,
			vec.y / len
		};
	}

	Vec2f& Vec2f::operator = (const Vec2i& vec) { x = (float)vec.x; y = (float)vec.y; return *this; }
	Vec2f& Vec2f::operator = (const Vec2f& vec) { x = (float)vec.x; y = (float)vec.y; return *this; }
	Vec2f& Vec2f::operator = (const Vec2d& vec) { x = (float)vec.x; y = (float)vec.y; return *this; }
	Vec2f& Vec2f::operator = (Vec2i&& vec) noexcept { x = (float)vec.x; y = (float)vec.y; return *this; }
	Vec2f& Vec2f::operator = (Vec2f&& vec) noexcept { x = (float)vec.x; y = (float)vec.y; return *this; }
	Vec2f& Vec2f::operator = (Vec2d&& vec) noexcept { x = (float)vec.x; y = (float)vec.y; return *this; }
	Vec2f Vec2f::operator +  (const Vec2f& vec)  const { return { x + vec.x, y + vec.y }; }
	Vec2f Vec2f::operator -  (const Vec2f& vec)  const { return { x - vec.x, y - vec.y }; }
	Vec2f Vec2f::operator *  (const float scale) const { return { x * scale, y * scale }; }
	Vec2f Vec2f::operator /  (const float scale) const { return { x / scale, y / scale }; }
	void  Vec2f::operator += (const Vec2f& vec)  { x += vec.x; y += vec.y; }
	void  Vec2f::operator -= (const Vec2f& vec)  { x -= vec.x; y -= vec.y; }
	void  Vec2f::operator *= (const float scale) { x *= scale; y *= scale; }
	void  Vec2f::operator /= (const float scale) { x /= scale; y /= scale; }
}

