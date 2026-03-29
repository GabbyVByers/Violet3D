
/*
	Log.h
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numbers>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>

namespace Violet {
	
	enum Concern {
		// General
		NO_GLFW_CONTEXT,
		// Violet::Window::Window()
		WINDOW_SINGLETON_VIOLATED, // todo: depricate
		GLFW_INIT_FAIL,
		GLFW_WINDOW_CREATE_FAIL,
		GLAD_LOAD_FAIL,
	};
	
	class Log {
	public:
		static void warning(Concern concern, std::string info = "");

	private:
		Log() = delete;
		Log(const Log&) = delete;
		Log(Log&&) noexcept = delete;
		static std::string elaborate(Concern concern);
	};
}

