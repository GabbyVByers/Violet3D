
#pragma once
#include "Mouse.h"

namespace Violet {

	class Keyboard;
	class Window;

	class Keyboard {
	public:
		bool pressed(int key, int edge);
		bool pressing(int key);

	private:
		friend Window;
		GLFWwindow* window_ptr;
		std::vector<GlfwKeyboardEvent> keyboard_events;

		Keyboard(GLFWwindow* window_ptr);
		~Keyboard(); 
		void reset();
		void push_key_event(GlfwKeyboardEvent& key_event);

		Keyboard(const Keyboard& other) = delete;
		Keyboard(Keyboard&& other) = delete;
		Keyboard& operator = (const Keyboard& other) = delete;
		Keyboard& operator = (Keyboard&& other) = delete;
	};
}

