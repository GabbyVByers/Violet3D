
#include "Violet.h"

int main() {
	Violet::Window::create("Render3D", 1920, 1080);
	
	Violet::Mesh mesh;
	mesh.create();

	while (Violet::Window::isOpen()) {
		Violet::Window::pollEvents();
		Violet::Window::clear(Math::Color(0.2, 0.2, 0.4));
		Violet::Window::display();
	}

	Violet::Window::destroy();
	return 0;
}

