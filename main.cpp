
#include "Violet.h"
#define Vi Violet

static void controlCamera(Vi::Camera& camera) {

	Vi::Mouse& mouse = Vi::Mouse::getMouse();

	if (mouse.pressing(GLFW_MOUSE_BUTTON_LEFT)) {
		Vi::Vec3d up = Vi::Vec3d(0.0, 1.0, 0.0);
		Vi::Quaternion rot = Vi::Quaternion::buildRotationQuaternion(up, mouse.velocity().x);
		camera.orientation = rot * camera.orientation;
	}


	camera.position = camera.forwardDirection() * -1.0;
}

int main() {
	Vi::Window window = Vi::Window("Render3D", 1920, 1080);
	window.vSync(false);
	
	Vi::Mouse& mouse = Vi::Mouse::getMouse();
	Vi::Keyboard& keyboard = Vi::Keyboard::getKeyboard();

	Vi::Camera camera;
	Vi::Mesh mesh;
	mesh.sphere(1.0, 10);
	mesh.position.z -= 3.0;



	while (window.isOpen()) {
		window.pollEvents();

		if (mouse.clicked(GLFW_MOUSE_BUTTON_LEFT, GLFW_PRESS))
			std::cout << "Left Mouse Button Pressed\n";
		if (mouse.clicked(GLFW_MOUSE_BUTTON_LEFT, GLFW_RELEASE))
			std::cout << "Left Mouse Button Released\n";
		if (mouse.clicked(GLFW_MOUSE_BUTTON_RIGHT, GLFW_PRESS))
			std::cout << "Right Mouse Button Pressed\n";
		if (mouse.clicked(GLFW_MOUSE_BUTTON_RIGHT, GLFW_RELEASE))
			std::cout << "Right Mouse Button Released\n";
		if (mouse.clicked(GLFW_MOUSE_BUTTON_MIDDLE, GLFW_PRESS))
			std::cout << "Middle Mouse Button Pressed\n";
		if (mouse.clicked(GLFW_MOUSE_BUTTON_MIDDLE, GLFW_RELEASE))
			std::cout << "Middle Mouse Button Released\n";

		double scroll = mouse.scroll();
		if (scroll > 0.0)
			std::cout << "Scrolled Up: scroll = " << scroll << "\n";
		if (scroll < 0.0)
			std::cout << "Scrolled Down: scroll = " << scroll << "\n";

		if (keyboard.pressing(GLFW_KEY_SPACE)) {
			Vi::Vec2d pos = mouse.position();
			std::cout << "Cursor Position: x = " << pos.x << " y = " << pos.y << "\n";
		}
		if (keyboard.pressing(GLFW_KEY_LEFT_SHIFT)) {
			Vi::Vec2d vel = mouse.velocity();
			if ((vel.x != 0.0) || (vel.y != 0.0))
				std::cout << "Cursor Velocity: x = " << vel.x << " y = " << vel.y << "\n";
		}

		if (keyboard.pressed(GLFW_KEY_W, GLFW_PRESS))
			std::cout << "W key Pressed\n";
		if (keyboard.pressed(GLFW_KEY_W, GLFW_RELEASE))
			std::cout << "W key Released\n";
		if (keyboard.pressing(GLFW_KEY_A))
			std::cout << "A Button Being Held Down\n";

		window.clear(Violet::Color(0.2, 0.2, 0.4));
		window.draw(mesh, camera);
		window.display();
	}

	return 0;
}

