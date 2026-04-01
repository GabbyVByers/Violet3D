
/*
	Shapes.h
*/

#pragma once
#include "Mesh.h"

namespace Vi {

	class Shapes {
	public:
		static Mesh arrow();
		static Mesh cube(unsigned int divisions);
		static Mesh sphere(unsigned int divisions);
	private:
		Shapes() = delete;
		Shapes(const Shapes& other) = delete;
		Shapes(Shapes&& other) noexcept = delete;
	};
}

