
/*
	Types.Mat4f.cpp
*/

#include "Types.h"

namespace Vi {

	Mat4f::Mat4f(const Mat4& matrix) {
		for (size_t i = 0; i < 4; i++) {
			for (size_t j = 0; j < 4; j++) {
				data[i][j] = (float)matrix.data[i][j];
			}
		}
	}
}

