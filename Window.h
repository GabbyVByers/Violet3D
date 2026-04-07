
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

	class Mouse {
	public:
		Vec2d position() const;
		Vec2d velocity() const;
		bool pressing(int button) const;
		bool clicked(int button, int edge) const;
		double scroll() const;
	private:
		friend Window;
		struct GlfwMouseEvent { int button, action, mods; };
		struct GlfwScrollEvent { double xoffset, yoffset; };
		Vec2d pos = Vec2d();
		Vec2d vel = Vec2d();
		std::vector<GlfwMouseEvent> mouse_events;
		std::vector<GlfwScrollEvent> scroll_events;
		void reset();
		void push_mouse_event(const GlfwMouseEvent& mouse_event);
		void push_scroll_event(const GlfwScrollEvent& scroll_event);
		Mouse() = default;
		Mouse(const Mouse& other) = delete;
		Mouse(Mouse&& other) noexcept = delete;
	};

	class Keyboard {
	public:
		bool pressed(int key, int edge) const;
		bool pressing(int key) const;
	private:
		friend Window;
		struct GlfwKeyboardEvent { int key, scancode, action, mods; };
		std::vector<GlfwKeyboardEvent> keyboard_events;
		void reset();
		void push_key_event(const GlfwKeyboardEvent& key_event);
		Keyboard() = default;
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
		static void callback_window_resize(GLFWwindow* ptr, int width, int height);
		static void callback_keyboard(GLFWwindow* ptr, int key, int scancode, int action, int mods);
		static void callback_mouse(GLFWwindow* ptr, int button, int action, int mods);
		static void callback_mousescroll(GLFWwindow* ptr, double xoffset, double yoffset);
		Window(const Window& other) = delete;
		Window(Window&& other) noexcept = delete;
	};
}

