
/*
	Mesh.Transform.cpp
*/

#include "Mesh.h"

namespace Vi {

	Mat4 Transform::model_matrix() const {
		Mat4 scalar_matrix = Mat4::scalar_matrix(scale);
		Mat4 translation_matrix = Mat4::translation_matrix(position);
		Mat4 rotation_matrix = Mat4::rotation_matrix(orientation);
		return translation_matrix * scalar_matrix * rotation_matrix;
	}
}

