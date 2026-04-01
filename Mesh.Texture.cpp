
/*
	Mesh.Texture.cpp
*/

#include "Mesh.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Vi {

	Texture::Texture(const std::string& path) {
		if (path == "default_no_texture") {
			unsigned char white[] = { 255, 255, 255, 255 };

			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, NULL, GL_RGBA, 1, 1, NULL, GL_RGBA, GL_UNSIGNED_BYTE, white);
			return;
		}

		int width, height;
		int num_color_channels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(path.c_str(), &width, &height, &num_color_channels, NULL);
		if (data == NULL)
			std::terminate(); // todo: replace with Vi::Log

		GLenum format = NULL;
		if (num_color_channels == 1) format = GL_RED;
		if (num_color_channels == 3) format = GL_RGB;
		if (num_color_channels == 4) format = GL_RGBA;
		if (format == NULL)
			std::terminate(); // todo: replace with Vi::Log

		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexImage2D(GL_TEXTURE_2D, NULL, format, width, height, NULL, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
	}

	Texture::~Texture() {
		if (texture != NULL)
			glDeleteTextures(1, &texture);
		texture = NULL;
	}

	Texture::Texture(Texture&& other) noexcept {
		texture = other.texture;
		other.texture = NULL;
	}

	Texture& Texture::operator = (Texture&& other) noexcept {
		if (texture != NULL)
			glDeleteTextures(1, &texture);
		texture = other.texture;
		other.texture = NULL;
		return *this;
	}
}

