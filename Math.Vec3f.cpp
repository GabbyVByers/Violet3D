
#include "Math.h"

Math::Vec3f::Vec3f() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Math::Vec3f::Vec3f(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Math::Vec3f::Vec3f(const Vec3d& vec) {
	x = (float)vec.x;
	y = (float)vec.y;
	z = (float)vec.z;
}

