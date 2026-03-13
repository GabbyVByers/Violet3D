
#include "Math.h"

Math::Matrix_f::Matrix_f() {
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; i++) {
			data[i][j] = 0.0f;
		}
		data[i][i] = 1.0f;
	}
}

Math::Matrix_f::Matrix_f(const Matrix& matrix) {
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; i++) {
			data[i][j] = (float)matrix.data[i][j];
		}
	}
}

