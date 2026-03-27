
#pragma once
#include <vector>
#include <string>
#include "Texture.h"
#include "Material.h"
#include "Transform.h"
#include "Vertex.h"
#include "Corelib.h"
#include "Color.h"
#include "QuatMath.h"

namespace Violet {

	class Mesh {
	public:
		Material material = Material("default", GL_TRIANGLES);
		Transform transform = Transform();
		Texture texture = Texture();
		std::vector<Vertex> vertices = std::vector<Vertex>();
		std::vector<unsigned int> indices = std::vector<unsigned int>();
	};
}

