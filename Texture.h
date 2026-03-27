
#pragma once
#include "Corelib.h"
#include "Image.h"
#include <string>

namespace Violet {

	class Texture {
	public:
		GLuint texture = NULL;
		Texture(const std::string& path = "default_no_texture");
		~Texture();
		Texture(Texture&& other) noexcept;
		Texture(const Texture& other) = delete;
		Texture& operator = (Texture&& other) noexcept;
		Texture& operator = (const Texture& other) = delete;
	};
}

