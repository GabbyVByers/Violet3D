
#include "Mesh.h"

namespace Vi {

    Vertex::Vertex(const Vec3f& position, const Color& color, const Vec2f& tex_coord) {
        this->position = position;
        this->color = color;
        this->tex_coord = tex_coord;
    }
}

