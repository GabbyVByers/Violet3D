
/*
	Window.h
*/

#pragma once
#include "Mesh.h"
#include "Shapes.h"

namespace Violet {

	class Mouse;
	class Keyboard;
	class Window;

	struct GlfwMouseEvent {
		int button, action, mods;
	};

	struct GlfwScrollEvent {
		double xoffset, yoffset;
	};

	struct GlfwKeyboardEvent {
		int key, scancode, action, mods;
	};

	class Mouse {
	public:
		Mouse() = default;
		Mouse(const Mouse& other) = delete;
		Mouse(Mouse&& other) noexcept = delete;
		Mouse& operator = (const Mouse& other) = delete;
		Mouse& operator = (Mouse&& other) noexcept = delete;
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
	};

	class Keyboard {
	public:
		Keyboard() = default;
		Keyboard(const Keyboard& other) = delete;
		Keyboard(Keyboard&& other) noexcept = delete;
		Keyboard& operator = (const Keyboard& other) = delete;
		Keyboard& operator = (Keyboard&& other) noexcept = delete;
		bool pressed(int key, int edge) const;
		bool pressing(int key) const;

	private:
		friend Window;
		GLFWwindow* window_ptr = nullptr;
		std::vector<GlfwKeyboardEvent> keyboard_events;
		void reset();
		void push_key_event(const GlfwKeyboardEvent& key_event);
	};

	class Window {
	public:
		Window(std::string title, int width, int height);
		~Window();
		Window(const Window& other) = delete;
		Window(Window&& other) noexcept = delete;
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
	};
}

