
/*
	Types.Color.cpp
*/

#include "Types.h"

namespace Violet {

	Color::Color() {
		r = 1.0f;
		g = 1.0f;
		b = 1.0f;
		a = 1.0f;
	}
	Color::Color(float r, float g, float b, float a) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	Color Color::random() {
		return {
			(float)rand() / (float)RAND_MAX,
			(float)rand() / (float)RAND_MAX,
			(float)rand() / (float)RAND_MAX,
			1.0
		};
	}
	Color Color::white()  { return { 1.0f, 1.0f, 1.0f, 1.0f }; }
	Color Color::black()  { return { 0.0f, 0.0f, 0.0f, 1.0f }; }
	Color Color::red()    { return { 1.0f, 0.0f, 0.0f, 1.0f }; }
	Color Color::green()  { return { 0.0f, 1.0f, 0.0f, 1.0f }; }
	Color Color::blue()   { return { 0.0f, 0.0f, 1.0f, 1.0f }; }
	Color Color::cyan()   { return { 0.0f, 1.0f, 1.0f, 1.0f }; }
	Color Color::purple() { return { 1.0f, 0.0f, 1.0f, 1.0f }; }
	Color Color::yellow() { return { 1.0f, 1.0f, 0.0f, 1.0f }; }

	static float clamp(float value) {
		return std::max(0.0f, std::min(value, 1.0f));
	}

	Color Color::operator *  (const float scale) const { return { clamp(r * scale), clamp(g * scale), clamp(b * scale), 1.0f }; }
	Color Color::operator /  (const float scale) const { return { clamp(r / scale), clamp(g / scale), clamp(b / scale), 1.0f }; }
	void  Color::operator *= (const float scale) { r = clamp(r * scale); g = clamp(g * scale); b = clamp(b * scale); a = 1.0f; }
	void  Color::operator /= (const float scale) { r = clamp(r / scale); g = clamp(g / scale); b = clamp(b / scale); a = 1.0f; }

	Color Color::operator *  (const Color& color) const { return { r * color.r, g * color.g, b * color.b, a * color.a }; }
	Color Color::operator /  (const Color& color) const { return { r / color.r, g / color.g, b / color.b, a / color.a }; }
	void  Color::operator *= (const Color& color) { r *= color.r; g *= color.g; b *= color.b; a *= color.a; }
	void  Color::operator /= (const Color& color) { r /= color.r; g /= color.g; b /= color.b; a /= color.a; }
}

