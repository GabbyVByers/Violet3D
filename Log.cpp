
/*
	Log.cpp
*/

#include "Log.h"

namespace Vi {

	void Log::assert_concern(
		bool statement,
		Concern concern,
		const char* info
	) {
		if (statement) return;
		std::cerr << "\033[31mWarning\033[0m: " << elaborate(concern) << '\n';
		if (info != nullptr) std::cerr << "Info: " << info << '\n';
		assert(false);
	}

	std::string Log::elaborate(Concern concern) {
		switch (concern) {
		case NO_GLFW_CONTEXT: return "GLFW Context has not been created or is already destroyed"; break;
		default: return "Unknown error: (code: " + std::to_string(concern) + ")";
		}
	}
}

