
/*
	Window.h
*/

#pragma once
#include "Mesh.h"
#include "Shapes.h"

namespace Vi {

	class Mouse;
	class Keyboard;
	class Window;

	class GlfwMouseEvent {
	public:
		int button, action, mods;
	};

	class GlfwScrollEvent {
	public:
		double xoffset, yoffset;
	};

	class GlfwKeyboardEvent {
	public:
		int key, scancode, action, mods;
	};

	class Mouse {
	public:
		Mouse() = default;
		Vec2d position() const;
		Vec2d velocity() const;
		bool pressing(int button) const;
		bool clicked(int button, int edge) const;
		double scroll() const;
	private:
		friend Window;
		Vec2d pos = Vec2d();
		Vec2d vel = Vec2d();
		GLFWwindow* window_ptr = nullptr;
		std::vector<GlfwMouseEvent> mouse_events;
		std::vector<GlfwScrollEvent> scroll_events;
		void reset();
		void push_mouse_event(const GlfwMouseEvent& mouse_event);
		void push_scroll_event(const GlfwScrollEvent& scroll_event);
		Mouse(const Mouse& other) = delete;
		Mouse(Mouse&& other) noexcept = delete;
	};

	class Keyboard {
	public:
		Keyboard() = default;
		bool pressed(int key, int edge) const;
		bool pressing(int key) const;
	private:
		friend Window;
		GLFWwindow* window_ptr = nullptr;
		std::vector<GlfwKeyboardEvent> keyboard_events;
		void reset();
		void push_key_event(const GlfwKeyboardEvent& key_event);
		Keyboard(const Keyboard& other) = delete;
		Keyboard(Keyboard&& other) noexcept = delete;
	};

	class Window {
	public:
		Window(std::string title, int width, int height);
		~Window();
		Vec2i size();
		void vsync(bool vsync);
		bool is_open();
		void poll_events();
		void clear(Color color);
		void draw(const Mesh& mesh, Camera& camera);
		void display();
		static Mouse& mouse();
		static Keyboard& keyboard();
	private:
		inline static size_t instances = NULL;
		inline static GLFWwindow* window_ptr = nullptr;
		inline static Mouse internal_mouse = Mouse();
		inline static Keyboard internal_keyboard = Keyboard();
		static void callback_window_resize(GLFWwindow* ptr, int width, int height);
		static void callback_keyboard(GLFWwindow* ptr, int key, int scancode, int action, int mods);
		static void callback_mouse(GLFWwindow* ptr, int button, int action, int mods);
		static void callback_mousescroll(GLFWwindow* ptr, double xoffset, double yoffset);
		Window(const Window& other) = delete;
		Window(Window&& other) noexcept = delete;
	};
}

