
#include "Vector.h"

Violet::Vec3f::Vec3f() { x = 0.0f; y = 0.0f; z = 0.0f; }
Violet::Vec3f::Vec3f(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }

Violet::Vec3f& Violet::Vec3f::operator = (const Violet::Vec3i& vec) { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; }
Violet::Vec3f& Violet::Vec3f::operator = (const Violet::Vec3f& vec) { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; }
Violet::Vec3f& Violet::Vec3f::operator = (const Violet::Vec3d& vec) { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; }

Violet::Vec3f Violet::Vec3f::operator +  (const Vec3f& vec)  const { return { x + vec.x, y + vec.y, z + vec.z }; }
Violet::Vec3f Violet::Vec3f::operator -  (const Vec3f& vec)  const { return { x - vec.x, y - vec.y, z - vec.z }; }
Violet::Vec3f Violet::Vec3f::operator *  (const float scale) const { return { x * scale, y * scale, z * scale }; }
Violet::Vec3f Violet::Vec3f::operator /  (const float scale) const { return { x / scale, y / scale, z / scale }; }
void          Violet::Vec3f::operator += (const Vec3f& vec)  { x += vec.x; y += vec.y; z += vec.z; }
void          Violet::Vec3f::operator -= (const Vec3f& vec)  { x -= vec.x; y -= vec.y; z -= vec.z; }
void          Violet::Vec3f::operator *= (const float scale) { x *= scale; y *= scale; z *= scale; }
void          Violet::Vec3f::operator /= (const float scale) { x /= scale; y /= scale; z /= scale; }

