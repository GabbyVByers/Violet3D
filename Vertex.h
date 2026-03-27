
#pragma once
#include "Material.h"

namespace Violet {

	class Vertex {
	public:
		Vec3f position = Vec3f();
		Color color = Color::white();
		Vec2f tex_coord = Vec2f();
	};
}

