
#pragma once
#include "Mat4.h"
#include "Color.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Quat.h"

namespace Violet {
	namespace Math {

		constexpr double Pi64 = 3.141592653589793;
		constexpr float  Pi32 = 3.1415927f;

		Vec3f  rotate_around_axis(const Vec3f& vec, const Vec3i& axis, float  theta);
		Vec3f  rotate_around_axis(const Vec3f& vec, const Vec3f& axis, float  theta);
		Vec3d  rotate_around_axis(const Vec3d& vec, const Vec3i& axis, double theta);
		Vec3d  rotate_around_axis(const Vec3d& vec, const Vec3d& axis, double theta);
		Vec3f  apply_quat_rotation(const Vec3f& vec, const Quat& rotation_quat);
		Vec3d  apply_quat_rotation(const Vec3d& vec, const Quat& rotation_quat);
		
		Quat rotation_quat(const Vec3i& axis, double theta);
		Quat rotation_quat(const Vec3f& axis, double theta);
		Quat rotation_quat(const Vec3d& axis, double theta);
	}
}

