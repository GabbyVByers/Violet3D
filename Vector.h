
#pragma once

namespace Violet {
	class Vec2i {
	public:
		int x, y;
		Vec2i();
		Vec2i(int x, int y);
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

		Vec3i& operator = (const Vec3i& vec);
		Vec3i& operator = (const Vec3f& vec);
		Vec3i& operator = (const Vec3d& vec);

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

		Vec3f& operator = (const Vec3i& vec);
		Vec3f& operator = (const Vec3f& vec);
		Vec3f& operator = (const Vec3d& vec);

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

		/*
		void normalize();
		void rotate(const Vec3d& axis, double theta);
		void rotate(const Quaternion& quat);
		static double lengthSq(const Vec3d& vec);
		static double length(const Vec3d& vec);
		static double dot(const Vec3d& a, const Vec3d& b);
		static Vec3d cross(const Vec3d& a, const Vec3d& b);
		*/

		Vec3d& operator = (const Vec3i& vec);
		Vec3d& operator = (const Vec3f& vec);
		Vec3d& operator = (const Vec3d& vec);

		Vec3d operator +  (const Vec3d& vec)   const;
		Vec3d operator -  (const Vec3d& vec)   const;
		Vec3d operator *  (const double scale) const;
		Vec3d operator /  (const double scale) const;
		void  operator += (const Vec3d& vec);
		void  operator -= (const Vec3d& vec);
		void  operator *= (const double scale);
		void  operator /= (const double scale);
	};
}

