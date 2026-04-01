
/*
    Mesh.cpp
*/

#include "Mesh.h"
#include <ranges>
#include <numeric>

namespace Vi {

    void Mesh::paint(const Color& color) {
        for (Vertex& v : vertices) {
            v = Vertex(v.position, color, v.tex_coord);
        }
    }
}

