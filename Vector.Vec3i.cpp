
#include "Vector.h"

Violet::Vec3i::Vec3i() { x = 0; y = 0; z = 0; }
Violet::Vec3i::Vec3i(int x, int y, int z) { this->x = x; this->y = y; this->z = z; }

Violet::Vec3i& Violet::Vec3i::operator = (const Violet::Vec3i& vec) { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; }
Violet::Vec3i& Violet::Vec3i::operator = (const Violet::Vec3f& vec) { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; }
Violet::Vec3i& Violet::Vec3i::operator = (const Violet::Vec3d& vec) { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; }

Violet::Vec3i Violet::Vec3i::operator +  (const Vec3i& vec) const { return { x + vec.x, y + vec.y, z + vec.z }; }
Violet::Vec3i Violet::Vec3i::operator -  (const Vec3i& vec) const { return { x - vec.x, y - vec.y, z - vec.z }; }
Violet::Vec3i Violet::Vec3i::operator *  (const int scale)  const { return { x * scale, y * scale, z * scale }; }
Violet::Vec3i Violet::Vec3i::operator /  (const int scale)  const { return { x / scale, y / scale, z / scale }; }
void          Violet::Vec3i::operator += (const Vec3i& vec) { x += vec.x; y += vec.y; z += vec.z; }
void          Violet::Vec3i::operator -= (const Vec3i& vec) { x -= vec.x; y -= vec.y; z -= vec.z; }
void          Violet::Vec3i::operator *= (const int scale)  { x *= scale; y *= scale; z *= scale; }
void          Violet::Vec3i::operator /= (const int scale)  { x /= scale; y /= scale; z /= scale; }

