
#pragma once

namespace Violet {
	class Matrix {
	public:
		double data[4][4];
		Matrix();
		Matrix(
			double a, double b, double c, double d,
			double e, double f, double g, double h,
			double i, double j, double k, double l,
			double m, double n, double o, double p
		);
		static Matrix buildScalarMatrix(double scale);
		static Matrix buildTranslationMatrix(const Vec3d& position);
		static Matrix buildRotationMatrix(const Quaternion& rotation);
		Matrix operator * (const Matrix& matrix) const;
	};

	class Matrix_f {
	public:
		float data[4][4];
		Matrix_f();
		Matrix_f(const Matrix& matrix);
	};
}

