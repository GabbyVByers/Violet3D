
#pragma once
#include <cmath>
#include <memory>

#define Math Math
namespace Math {
	constexpr double Pi64 = 3.141592653589793;
	constexpr float  Pi32 = 3.1415927f;

	class Vec3d;
	class Vec3f;
	class Vec3i;
	class Color;
	class Matrix;
	class Matrix_f;
	class Quaternion;
	class Transformation;

	class Vec2i {
	public:
		int x, y;
		Vec2i();
		Vec2i(int x, int y);
	};

	class Vec3i {
	public:
		int x, y, z;
		Vec3i();
		Vec3i(int x, int y, int z);
	};

	class Vec3f {
	public:
		float x, y, z;
		Vec3f();
		Vec3f(float x, float y, float z);
		Vec3f(const Vec3d& vec);
	};

	class Vec3d {
	public:
		double x, y, z;
		Vec3d();
		Vec3d(double x, double y, double z);
		Vec3d(const Quaternion& quat, const Vec3d& basis_dir);
		Vec3d  rotated(const Vec3d& axis, double theta) const;
		Vec3d  normalized() const;
		double lengthSq() const;
		double length() const;
		double dot(const Vec3d& vec) const;
		Vec3d  cross(const Vec3d& vec) const;
		Vec3d  operator +  (const Vec3d& vec) const;
		Vec3d  operator -  (const Vec3d& vec) const;
		Vec3d  operator *  (const double scale) const;
		Vec3d  operator /  (const double scale) const;
		void   operator += (const Vec3d& vec);
		void   operator -= (const Vec3d& vec);
		void   operator *= (const double scale);
		void   operator /= (const double scale);
	};

	class Color {
	public:
		float r, g, b, a;
		Color();
		Color(float r, float g, float b, float a = 1.0f);
		static Color white();
		static Color black();
		static Color red();
		static Color green();
		static Color blue();
		static Color cyan();
		static Color purple();
		static Color yellow();
	};

	class Matrix {
	public:
		double data[4][4];
		Matrix(
			double a, double b, double c, double d,
			double e, double f, double g, double h,
			double i, double j, double k, double l,
			double m, double n, double o, double p
		);
		Matrix();
		Matrix(double scale);
		Matrix(const Vec3d& position);
		Matrix(const Quaternion& rotation);
		Matrix operator * (const Matrix& matrix) const;
	};

	class Matrix_f {
	public:
		float data[4][4];
		Matrix_f();
		Matrix_f(const Matrix& matrix);
	};

	class Quaternion {
	public:
		double w, x, y, z;
		Quaternion();
		Quaternion(double w, double x, double y, double z);
		Quaternion(const Vec3d& axis, double theta);
		Quaternion normalized() const;
		Quaternion complexConjugate() const;
		Quaternion operator * (const Quaternion& q) const;
	};

	class Transformation {
	public:
		double scale;
		Vec3d position;
		Quaternion orientation;
		Matrix modelMatrix() const;
		Matrix viewMatrix() const;
	};
}

