
#include "Math.h"

Math::Matrix Math::Transformation::modelMatrix() const {
	Matrix scalar_matrix = Matrix(scale);
	Matrix translation_matrix = Matrix(position);
	Matrix rotation_matrix = Matrix(orientation);
	return translation_matrix * scalar_matrix * rotation_matrix;
}

Math::Matrix Math::Transformation::viewMatrix() const {
	Matrix translation_matrix_inverse = Matrix(position);
	Matrix rotation_matrix_inverse = Matrix(orientation.complexConjugate());
	return rotation_matrix_inverse * translation_matrix_inverse;
}

