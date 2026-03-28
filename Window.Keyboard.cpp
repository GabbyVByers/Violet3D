
/*
	Window.Keyboard.cpp
*/

#include "Window.h"

namespace Violet {

	bool Keyboard::pressed(int key, int edge) const {
		for (const GlfwKeyboardEvent& key_event : keyboard_events) {
			if (key_event.key != key)
				continue;
			if (key_event.action != edge)
				continue;
			return true;
		}
		return false;
	}

	bool Keyboard::pressing(int key) const {
		return glfwGetKey(window_ptr, key) == GLFW_PRESS;
	}

	void Keyboard::reset() {
		keyboard_events.clear();
	}

	void Keyboard::push_key_event(const GlfwKeyboardEvent& key_event) {
		keyboard_events.push_back(key_event);
	}
}

