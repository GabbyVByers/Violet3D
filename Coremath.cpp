
#include "Coremath.h"
#include <cmath>

Violet::Vec3f Violet::Math::rotate_around_axis(const Vec3f& vec, const Vec3i& axis, float  theta) {
	Vec3i axis_n = Vec3i::normalize(axis);
	Quat rotation = rotation_quat(axis, theta);
	return apply_quat_rotation(vec, rotation);
}

Violet::Vec3f Violet::Math::rotate_around_axis(const Vec3f& vec, const Vec3f& axis, float  theta) {
	Quat rotation = rotation_quat(axis, theta);
	return apply_quat_rotation(vec, rotation);
}

Violet::Vec3d Violet::Math::rotate_around_axis(const Vec3d& vec, const Vec3i& axis, double theta) {
	Vec3i axis_n = Vec3i::normalize(axis);
	Quat rotation = rotation_quat(axis, theta);
	return apply_quat_rotation(vec, rotation);
}

Violet::Vec3d Violet::Math::rotate_around_axis(const Vec3d& vec, const Vec3d& axis, double theta) {
	Quat rotation = rotation_quat(axis, theta);
	return apply_quat_rotation(vec, rotation);
}

Violet::Vec3f Violet::Math::apply_quat_rotation(const Vec3f& vec, const Quat& rotation_quat) {
	Quat q_inv = Quat::complex_conjugate(rotation_quat);
	Quat p = { 0.0, vec.x, vec.y, vec.z };
	Quat result_quat = rotation_quat * p * q_inv;
	return {
		(float)result_quat.x,
		(float)result_quat.y,
		(float)result_quat.z
	};
}

Violet::Vec3d Violet::Math::apply_quat_rotation(const Vec3d& vec, const Quat& rotation_quat) {
	Quat q_inv = Quat::complex_conjugate(rotation_quat);
	Quat p = { 0.0, vec.x, vec.y, vec.z };
	Quat result_quat = rotation_quat * p * q_inv;
	return {
		result_quat.x,
		result_quat.y,
		result_quat.z
	};
}

Violet::Quat Violet::Math::rotation_quat(const Vec3i& axis, double theta) {
	Vec3i axis_n = Vec3i::normalize(axis);
	double half = theta * 0.5;
	double s = sin(half);
	return {
		cos(half),
		s * (double)axis_n.x,
		s * (double)axis_n.y,
		s * (double)axis_n.z
	};
}

Violet::Quat Violet::Math::rotation_quat(const Vec3f& axis, double theta) {
	Vec3f axis_n = Vec3f::normalize(axis);
	double half = theta * 0.5;
	double s = sin(half);
	return {
		cos(half),
		s * (double)axis_n.x,
		s * (double)axis_n.y,
		s * (double)axis_n.z
	};
}

Violet::Quat Violet::Math::rotation_quat(const Vec3d& axis, double theta) {
	Vec3d axis_n = Vec3d::normalize(axis);
	double half = theta * 0.5;
	double s = sin(half);
	return {
		cos(half),
		s * axis_n.x,
		s * axis_n.y,
		s * axis_n.z
	};
}

