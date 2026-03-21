
#pragma once
#include "Core.h"
#include "Mesh.h"
#include <cmath>

namespace Violet {
	class Quaternion {
	public:
		double w, x, y, z;
		Quaternion();
		Quaternion(double w, double x, double y, double z);
		void normalize();
		static Quaternion buildRotationQuaternion(const Vec3d& axis, double theta);
		static Quaternion complexConjugate(const Quaternion& quat);
		Quaternion operator * (const Quaternion& q) const;
	};
}

