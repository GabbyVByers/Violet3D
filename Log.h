
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
#include <cassert>
#define Vi Vi

namespace Vi {
	
	enum Concern {
		// General
		GENERIC,
		NO_GLFW_CONTEXT,
		// Violet::Window::Window()
		WINDOW_SINGLETON_VIOLATED, // todo: depricate
		GLFW_INIT_FAIL,
		GLFW_WINDOW_CREATE_FAIL,
		GLAD_LOAD_FAIL,
	};
	
	class Log {
	public:
		static void assert_concern(
			bool failure_condition,
			Concern concern,
			const char* info = nullptr
		);
	private:
		Log() = delete;
		Log(const Log&) = delete;
		Log(Log&&) noexcept = delete;
		static std::string elaborate(Concern concern);
	};
}

