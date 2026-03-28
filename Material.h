
#pragma once
#include "Transform.h"

namespace Violet {
	
	class Material {
	public:
		GLuint vao = NULL;
		GLuint vbo = NULL;
		GLuint shader = NULL;
		GLenum primitive = NULL;
		Material(const std::string& path, GLenum type);
		~Material();
		Material(Material&& other) noexcept;                   // Move Constructor
		Material(const Material& other) = delete;              // Copy Constructor
		Material& operator = (Material&& other) noexcept;      // Move Assignment
		Material& operator = (const Material& other) = delete; // Copy Assignment
	};
}

