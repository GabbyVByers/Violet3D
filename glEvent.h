
#pragma once
#include "Corelib.h"

namespace Violet {

	class GlfwMouseEvent;
	class GlfwScrollEvent;
	class GlfwKeyboardEvent;

	class GlfwMouseEvent {
	public:
		int button;
		int action;
		int mods;
	};

	class GlfwScrollEvent {
	public:
		double xoffset;
		double yoffset;
	};

	class GlfwKeyboardEvent {
	public:
		int key;
		int scancode;
		int action;
		int mods;
	};
}

