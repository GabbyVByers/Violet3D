
#include "Math.h"

Math::Color::Color() {
	r = 1.0f;
	g = 1.0f;
	b = 1.0f;
	a = 1.0f;
}

Math::Color::Color(float r, float g, float b, float a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Math::Color Math::Color::white()  { return { 1.0f, 1.0f, 1.0f, 1.0f }; }
Math::Color Math::Color::black()  { return { 0.0f, 0.0f, 0.0f, 1.0f }; }
Math::Color Math::Color::red()    { return { 1.0f, 0.0f, 0.0f, 1.0f }; }
Math::Color Math::Color::green()  { return { 0.0f, 1.0f, 0.0f, 1.0f }; }
Math::Color Math::Color::blue()   { return { 0.0f, 0.0f, 1.0f, 1.0f }; }
Math::Color Math::Color::cyan()   { return { 0.0f, 1.0f, 1.0f, 1.0f }; }
Math::Color Math::Color::purple() { return { 1.0f, 0.0f, 1.0f, 1.0f }; }
Math::Color Math::Color::yellow() { return { 1.0f, 1.0f, 0.0f, 1.0f }; }

