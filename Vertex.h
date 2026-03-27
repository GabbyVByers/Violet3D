
#pragma once
#include "Vec3.h"
#include "Vec2.h"
#include "Color.h"


namespace Violet {

	class Vertex {
	public:
		Vec3f position = Vec3f();
		Color color = Color::white();
		Vec2f tex_coord = Vec2f();
	};
}

