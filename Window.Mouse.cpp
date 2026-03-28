
/*
	Window.Mouse.cpp
*/

#include "Window.h"

namespace Violet {

	Vec2d Mouse::position() const {
		return pos;
	}

	Vec2d Mouse::velocity() const {
		return vel;
	}

	bool Mouse::pressing(int button) const {
		return glfwGetMouseButton(window_ptr, button) == GLFW_PRESS;
	}

	bool Mouse::clicked(int button, int edge) const {
		for (const GlfwMouseEvent& mouse_event : mouse_events) {
			if (mouse_event.button != button)
				continue;
			if (mouse_event.action != edge)
				continue;
			return true;
		}
		return false;
	}

	double Mouse::scroll() const {
		double scroll_accumulator = 0.0;
		for (const GlfwScrollEvent& scroll_event : scroll_events) {
			scroll_accumulator += scroll_event.yoffset;
		}
		return scroll_accumulator;
	}

	void Mouse::reset() {
		double x, y; glfwGetCursorPos(window_ptr, &x, &y);
		Vec2d new_pos = { x, y };
		vel = new_pos - pos;
		pos = new_pos;
		mouse_events.clear();
		scroll_events.clear();
	}

	void Mouse::push_mouse_event(const GlfwMouseEvent& mouse_event) {
		mouse_events.push_back(mouse_event);
	}

	void Mouse::push_scroll_event(const GlfwScrollEvent& scroll_event) {
		scroll_events.push_back(scroll_event);
	}
}

