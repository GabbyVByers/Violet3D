
#include "Violet3D.h"
#include <iostream>

static void inputTest();
static void debugGui(Vi::Window& window, Vi::Camera& camera);
static void controlCamera(Vi::Camera& camera);

int main() {
	Vi::Window window("Render3D Demo", 1920, 1080);
	Vi::Camera camera;

	Vi::Mesh mesh;
	mesh.texture = Vi::Texture("test_image.png");
	mesh.vertices.push_back({ Vi::Vec3f(-0.5f, 0.5f, 0.0f), Vi::Color::cyan(), Vi::Vec2f( 0.0f, 1.0f) });
	mesh.vertices.push_back({ Vi::Vec3f(-0.5f,-0.5f, 0.0f), Vi::Color::purple(), Vi::Vec2f( 0.0f, 0.0f) });
	mesh.vertices.push_back({ Vi::Vec3f( 0.5f, 0.5f, 0.0f), Vi::Color::yellow(), Vi::Vec2f( 1.0f, 1.0f) });
	mesh.vertices.push_back({ Vi::Vec3f( 0.5f,-0.5f, 0.0f), Vi::Color::red(), Vi::Vec2f( 1.0f, 0.0f) });
	mesh.indices.push_back(0);
	mesh.indices.push_back(1);
	mesh.indices.push_back(2);
	mesh.indices.push_back(2);
	mesh.indices.push_back(1);
	mesh.indices.push_back(3);
	
	Vi::Mesh sphere_mesh = Vi::Shapes::sphere(10);
	
	while (window.is_open()) {
		window.poll_events();
		window.clear(Violet::Color::blue() * 0.25);

		inputTest();
		controlCamera(camera);
		debugGui(window, camera);

		//window.draw(sphere_mesh, camera);
		window.draw(mesh, camera);
		window.display();
	}

	return 0;
}

static void inputTest() {
	Vi::Mouse& mouse = Vi::Window::mouse();
	Vi::Keyboard& keyboard = Vi::Window::keyboard();

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
}

static void debugGui(Vi::Window& window, Vi::Camera& camera) {
	Vi::Vec2i screen_size = window.size();
	ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Always);
	ImGui::SetNextWindowSize(ImVec2(200.0f, (float)screen_size.y), ImGuiCond_Always);
	ImGui::Begin(
		"stats for nerds",
		nullptr,
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoTitleBar
	);
	ImGui::Text("Camera Position");
	ImGui::Text("x: %f", camera.position.x);
	ImGui::Text("y: %f", camera.position.y);
	ImGui::Text("z: %f", camera.position.z);
	ImGui::End();
}

static void controlCamera(Vi::Camera& camera) {
	constexpr double speed = 0.001;
	static double distance = 2.0;
	Vi::Mouse& mouse = Vi::Window::mouse();

	if (mouse.pressing(GLFW_MOUSE_BUTTON_LEFT)) {
		Vi::Vec3d up = Vi::Vec3d(0.0, 1.0, 0.0);
		Vi::Quat rot_up = Vi::Math::rotation_quat(up, (double)mouse.velocity().x * -speed);
		camera.orientation = rot_up * camera.orientation;
		Vi::Vec3d right = Vi::Camera::right_dir(camera);
		Vi::Quat rot_right = Vi::Math::rotation_quat(right, (double)mouse.velocity().y * -speed);
		camera.orientation = rot_right * camera.orientation;
	}
	int scroll = mouse.scroll();
	if (scroll != 0) {
		distance *= ((45.0 - (double)scroll) / 45.0);
	}

	camera.position = Vi::Camera::forward_dir(camera) * distance;
}

