
/*
	Types.Vec2d.cpp
*/

#include "Types.h"

namespace Vi {

	Vec2d::Vec2d() { x = 0.0; y = 0.0; }
	Vec2d::Vec2d(double x, double y) { this->x = x; this->y = y; }
	Vec2d::Vec2d(const Vec2i& vec) { x = (double)vec.x; y = (double)vec.y; };
	Vec2d::Vec2d(const Vec2f& vec) { x = (double)vec.x; y = (double)vec.y; };
	Vec2d::Vec2d(const Vec2d& vec) { x = (double)vec.x; y = (double)vec.y; };
	Vec2d::Vec2d(Vec2i&& vec) noexcept { x = (double)vec.x; y = (double)vec.y; };
	Vec2d::Vec2d(Vec2f&& vec) noexcept { x = (double)vec.x; y = (double)vec.y; };
	Vec2d::Vec2d(Vec2d&& vec) noexcept { x = (double)vec.x; y = (double)vec.y; };

	double Vec2d::hypot(const Vec2d& vec) { return std::hypot(vec.x, vec.y); }
	double Vec2d::dot(const Vec2d& a, const Vec2d& b) { return (a.x * b.x) + (a.y * b.y); }
	double Vec2d::cross(const Vec2d& a, const Vec2d& b) { return (a.x * b.y) - (a.y * b.x); }
	Vec2d Vec2d::normalize(const Vec2d& vec) {
		double len = hypot(vec);
		if (len == 0.0)
			return Vec2d();
		return {
			vec.x / len,
			vec.y / len
		};
	}

	Vec2d& Vec2d::operator = (const Vec2i& vec) { x = (double)vec.x; y = (double)vec.y; return *this; }
	Vec2d& Vec2d::operator = (const Vec2f& vec) { x = (double)vec.x; y = (double)vec.y; return *this; }
	Vec2d& Vec2d::operator = (const Vec2d& vec) { x = (double)vec.x; y = (double)vec.y; return *this; }
	Vec2d& Vec2d::operator = (Vec2i&& vec) noexcept { x = (double)vec.x; y = (double)vec.y; return *this; }
	Vec2d& Vec2d::operator = (Vec2f&& vec) noexcept { x = (double)vec.x; y = (double)vec.y; return *this; }
	Vec2d& Vec2d::operator = (Vec2d&& vec) noexcept { x = (double)vec.x; y = (double)vec.y; return *this; }
	Vec2d Vec2d::operator +  (const Vec2d& vec)   const { return { x + vec.x, y + vec.y }; }
	Vec2d Vec2d::operator -  (const Vec2d& vec)   const { return { x - vec.x, y - vec.y }; }
	Vec2d Vec2d::operator *  (const double scale) const { return { x * scale, y * scale }; }
	Vec2d Vec2d::operator /  (const double scale) const { return { x / scale, y / scale }; }
	void  Vec2d::operator += (const Vec2d& vec)   { x += vec.x; y += vec.y; }
	void  Vec2d::operator -= (const Vec2d& vec)   { x -= vec.x; y -= vec.y; }
	void  Vec2d::operator *= (const double scale) { x *= scale; y *= scale; }
	void  Vec2d::operator /= (const double scale) { x /= scale; y /= scale; }
}

