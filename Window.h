
#pragma once
#include "Rendermath.h"
#include "Keyboard.h"

namespace Violet {

	class Window {
	public:
		Window(std::string title, int width, int height);
		~Window();
		static Vec2i size();
		void vsync(bool vsync);
		bool is_open();
		void poll_events();
		void clear(Color color);
		void draw(const Mesh& mesh, Camera& camera);
		void display();

		static Mouse& mouse();
		static Keyboard& keyboard();

	private:
		inline static GLFWwindow* window_ptr = nullptr;
		static void callback_window_resize(GLFWwindow* window_ptr, int width, int height);
		static void callback_keyboard(GLFWwindow* window_ptr, int key, int scancode, int action, int mods);
		static void callback_mouse(GLFWwindow* window_ptr, int button, int action, int mods);
		static void callback_mousescroll(GLFWwindow* window_ptr, double xoffset, double yoffset);

		Window(const Window& other)              = delete;
		Window(Window&& other)                   = delete;
		Window& operator = (const Window& other) = delete;
		Window& operator = (Window&& other)      = delete;
	};
}

