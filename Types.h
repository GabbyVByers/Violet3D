
/*
	Types.h
*/

#pragma once
#include "Log.h"

namespace Vi {

	class Vec2i;
	class Vec2f;
	class Vec2d;
	class Vec3i;
	class Vec3f;
	class Vec3d;
	class Mat4;
	class Mat4f;
	class Quat;
	class Color;

	class Vec2i {
	public:
		int x, y;
		Vec2i();
		Vec2i(int x, int y);
		Vec2i(const Vec2i& vec);
		Vec2i(const Vec2f& vec);
		Vec2i(const Vec2d& vec);
		Vec2i(Vec2f&& vec) noexcept;
		Vec2i(Vec2i&& vec) noexcept;
		Vec2i(Vec2d&& vec) noexcept;
		static int hypot(const Vec2i& vec);
		static int dot(const Vec2i& a, const Vec2i& b);
		static int cross(const Vec2i& a, const Vec2i& b);
		Vec2i& operator = (const Vec2i& vec);
		Vec2i& operator = (const Vec2f& vec);
		Vec2i& operator = (const Vec2d& vec);
		Vec2i& operator = (Vec2i&& vec) noexcept;
		Vec2i& operator = (Vec2f&& vec) noexcept;
		Vec2i& operator = (Vec2d&& vec) noexcept;
		Vec2i operator +  (const Vec2i& vec) const;
		Vec2i operator -  (const Vec2i& vec) const;
		Vec2i operator *  (const int scale)  const;
		Vec2i operator /  (const int scale)  const;
		void  operator += (const Vec2i& vec);
		void  operator -= (const Vec2i& vec);
		void  operator *= (const int scale);
		void  operator /= (const int scale);
	};

	class Vec2f {
	public:
		float x, y;
		Vec2f();
		Vec2f(float x, float y);
		Vec2f(const Vec2i& vec);
		Vec2f(const Vec2f& vec);
		Vec2f(const Vec2d& vec);
		Vec2f(Vec2i&& vec) noexcept;
		Vec2f(Vec2f&& vec) noexcept;
		Vec2f(Vec2d&& vec) noexcept;
		static float hypot(const Vec2f& vec);
		static float dot(const Vec2f& a, const Vec2f& b);
		static float cross(const Vec2f& a, const Vec2f& b);
		static Vec2f normalize(const Vec2f& vec);
		Vec2f& operator = (const Vec2i& vec);
		Vec2f& operator = (const Vec2f& vec);
		Vec2f& operator = (const Vec2d& vec);
		Vec2f& operator = (Vec2i&& vec) noexcept;
		Vec2f& operator = (Vec2f&& vec) noexcept;
		Vec2f& operator = (Vec2d&& vec) noexcept;
		Vec2f operator +  (const Vec2f& vec)  const;
		Vec2f operator -  (const Vec2f& vec)  const;
		Vec2f operator *  (const float scale) const;
		Vec2f operator /  (const float scale) const;
		void  operator += (const Vec2f& vec);
		void  operator -= (const Vec2f& vec);
		void  operator *= (const float scale);
		void  operator /= (const float scale);
	};

	class Vec2d {
	public:
		double x, y;
		Vec2d();
		Vec2d(double x, double y);
		Vec2d(const Vec2i& vec);
		Vec2d(const Vec2f& vec);
		Vec2d(const Vec2d& vec);
		Vec2d(Vec2i&& vec) noexcept;
		Vec2d(Vec2f&& vec) noexcept;
		Vec2d(Vec2d&& vec) noexcept;
		static double hypot(const Vec2d& vec);
		static double dot(const Vec2d& a, const Vec2d& b);
		static double cross(const Vec2d& a, const Vec2d& b);
		static Vec2d normalize(const Vec2d& vec);
		Vec2d& operator = (const Vec2i& vec);
		Vec2d& operator = (const Vec2f& vec);
		Vec2d& operator = (const Vec2d& vec);
		Vec2d& operator = (Vec2i&& vec) noexcept;
		Vec2d& operator = (Vec2f&& vec) noexcept;
		Vec2d& operator = (Vec2d&& vec) noexcept;
		Vec2d operator +  (const Vec2d& vec)   const;
		Vec2d operator -  (const Vec2d& vec)   const;
		Vec2d operator *  (const double scale) const;
		Vec2d operator /  (const double scale) const;
		void  operator += (const Vec2d& vec);
		void  operator -= (const Vec2d& vec);
		void  operator *= (const double scale);
		void  operator /= (const double scale);
	};

	class Vec3i {
	public:
		int x, y, z;
		Vec3i();
		Vec3i(int x, int y, int z);
		Vec3i(const Vec3i& vec);
		Vec3i(const Vec3f& vec);
		Vec3i(const Vec3d& vec);
		Vec3i(Vec3i&& vec) noexcept;
		Vec3i(Vec3f&& vec) noexcept;
		Vec3i(Vec3d&& vec) noexcept;
		static Vec3i xpos();
		static Vec3i xneg();
		static Vec3i ypos();
		static Vec3i yneg();
		static Vec3i zpos();
		static Vec3i zneg();
		static int hypot(const Vec3i& vec);
		static int dot(const Vec3i& a, const Vec3i& b);
		static Vec3i cross(const Vec3i& a, const Vec3i& b);
		Vec3i& operator = (const Vec3i& vec);
		Vec3i& operator = (const Vec3f& vec);
		Vec3i& operator = (const Vec3d& vec);
		Vec3i& operator = (Vec3i&& vec) noexcept;
		Vec3i& operator = (Vec3f&& vec) noexcept;
		Vec3i& operator = (Vec3d&& vec) noexcept;
		Vec3i operator +  (const Vec3i& vec) const;
		Vec3i operator -  (const Vec3i& vec) const;
		Vec3i operator *  (const int scale)  const;
		Vec3i operator /  (const int scale)  const;
		void  operator += (const Vec3i& vec);
		void  operator -= (const Vec3i& vec);
		void  operator *= (const int scale);
		void  operator /= (const int scale);
	};

	class Vec3f {
	public:
		float x, y, z;
		Vec3f();
		Vec3f(float x, float y, float z);
		Vec3f(const Vec3i& vec);
		Vec3f(const Vec3f& vec);
		Vec3f(const Vec3d& vec);
		Vec3f(Vec3i&& vec) noexcept;
		Vec3f(Vec3f&& vec) noexcept;
		Vec3f(Vec3d&& vec) noexcept;
		static Vec3f xpos();
		static Vec3f xneg();
		static Vec3f ypos();
		static Vec3f yneg();
		static Vec3f zpos();
		static Vec3f zneg();
		static float hypot(const Vec3f& vec);
		static float dot(const Vec3f& a, const Vec3f& b);
		static Vec3f cross(const Vec3f& a, const Vec3f& b);
		static Vec3f normalize(const Vec3f& vec);
		static Vec3f rotate(const Vec3f& vec, const Vec3i& axis, float theta);
		static Vec3f rotate(const Vec3f& vec, const Vec3f& axis, float theta);
		static Vec3f rotate(const Vec3f& vec, const Quat& rotation_quat);
		Vec3f& operator = (const Vec3i& vec);
		Vec3f& operator = (const Vec3f& vec);
		Vec3f& operator = (const Vec3d& vec);
		Vec3f& operator = (Vec3i&& vec) noexcept;
		Vec3f& operator = (Vec3f&& vec) noexcept;
		Vec3f& operator = (Vec3d&& vec) noexcept;
		Vec3f operator +  (const Vec3f& vec)  const;
		Vec3f operator -  (const Vec3f& vec)  const;
		Vec3f operator *  (const float scale) const;
		Vec3f operator /  (const float scale) const;
		void  operator += (const Vec3f& vec);
		void  operator -= (const Vec3f& vec);
		void  operator *= (const float scale);
		void  operator /= (const float scale);
	};

	class Vec3d {
	public:
		double x, y, z;
		Vec3d();
		Vec3d(double x, double y, double z);
		Vec3d(const Vec3i& vec);
		Vec3d(const Vec3f& vec);
		Vec3d(const Vec3d& vec);
		Vec3d(Vec3i&& vec) noexcept;
		Vec3d(Vec3f&& vec) noexcept;
		Vec3d(Vec3d&& vec) noexcept;
		static Vec3d xpos();
		static Vec3d xneg();
		static Vec3d ypos();
		static Vec3d yneg();
		static Vec3d zpos();
		static Vec3d zneg();
		static double hypot(const Vec3d& vec);
		static double dot(const Vec3d& a, const Vec3d& b);
		static Vec3d cross(const Vec3d& a, const Vec3d& b);
		static Vec3d normalize(const Vec3d& vec);
		static Vec3d rotate(const Vec3d& vec, const Vec3i& axis, double theta);
		static Vec3d rotate(const Vec3d& vec, const Vec3d& axis, double theta);
		static Vec3d rotate(const Vec3d& vec, const Quat& rotation_quat);
		Vec3d& operator = (const Vec3i& vec);
		Vec3d& operator = (const Vec3f& vec);
		Vec3d& operator = (const Vec3d& vec);
		Vec3d& operator = (Vec3i&& vec) noexcept;
		Vec3d& operator = (Vec3f&& vec) noexcept;
		Vec3d& operator = (Vec3d&& vec) noexcept;
		Vec3d operator +  (const Vec3d& vec)   const;
		Vec3d operator -  (const Vec3d& vec)   const;
		Vec3d operator *  (const double scale) const;
		Vec3d operator /  (const double scale) const;
		void  operator += (const Vec3d& vec);
		void  operator -= (const Vec3d& vec);
		void  operator *= (const double scale);
		void  operator /= (const double scale);
	};

	class Mat4 {
	public:
		double data[4][4];
		Mat4();
		Mat4(
			double a, double b, double c, double d,
			double e, double f, double g, double h,
			double i, double j, double k, double l,
			double m, double n, double o, double p
		);
		static Mat4 scalar_matrix(double scale);
		static Mat4 translation_matrix(const Vec3d& position);
		static Mat4 rotation_matrix(const Quat& rotation_quat);
		Mat4 operator * (const Mat4& matrix) const;
	};

	class Mat4f {
	public:
		float data[4][4];
		Mat4f(const Mat4& matrix);
		~Mat4f() = default;
	private:
		Mat4f() = delete;
		Mat4f(const Mat4f& other) = delete;
		Mat4f(Mat4f&& other) noexcept = delete;
	};

	class Quat {
	public:
		double w, x, y, z;
		Quat();
		Quat(double w, double x, double y, double z);
		~Quat() = default;
		static Quat normalize(const Quat& quat);
		static Quat complex_conjugate(const Quat& quat);
		static Quat rotation(const Vec3i& axis, double theta);
		static Quat rotation(const Vec3f& axis, double theta);
		static Quat rotation(const Vec3d& axis, double theta);
		Quat operator * (const Quat& q) const;
	};

	class Color {
	public:
		float r, g, b, a;
		Color();
		Color(float r, float g, float b, float a = 1.0f);
		~Color() = default;
		static Color random();
		static Color white();
		static Color black();
		static Color red();
		static Color green();
		static Color blue();
		static Color cyan();
		static Color purple();
		static Color yellow();
		Color operator *  (const float scale) const;
		Color operator /  (const float scale) const;
		void  operator *= (const float scale);
		void  operator /= (const float scale);
		Color operator *  (const Color& color) const;
		Color operator /  (const Color& color) const;
		void  operator *= (const Color& color);
		void  operator /= (const Color& color);
	};
}

