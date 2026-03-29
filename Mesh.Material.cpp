
/*
	Mesh.Material.cpp
*/

#include "Mesh.h"

namespace Violet {

	Material::Material(const std::string& path, GLenum type) {
		GLFWwindow* window = glfwGetCurrentContext();
		if (window == nullptr)
			Log::warning(NO_GLFW_CONTEXT);

		primitive = type;
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(7 * sizeof(float)));
		glEnableVertexAttribArray(2);

		auto load = [](std::string path) -> std::string {
			std::ifstream file(path);
			std::stringstream buffer;
			buffer << file.rdbuf();
			return buffer.str();
			};

		std::string vert_source = load(path + ".vert");
		std::string frag_source = load(path + ".frag");
		const char* vert_c_str = vert_source.c_str();
		const char* frag_c_str = frag_source.c_str();

		GLuint vert_program = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vert_program, 1, &vert_c_str, nullptr);
		glCompileShader(vert_program);
		GLint success;
		glGetShaderiv(vert_program, GL_COMPILE_STATUS, &success);
		if (!success)
			std::terminate();

		GLuint frag_program = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(frag_program, 1, &frag_c_str, nullptr);
		glCompileShader(frag_program);
		glGetShaderiv(frag_program, GL_COMPILE_STATUS, &success);
		if (!success)
			std::terminate();

		shader = glCreateProgram();
		glAttachShader(shader, vert_program);
		glAttachShader(shader, frag_program);
		glLinkProgram(shader);
		glDeleteShader(vert_program);
		glDeleteShader(frag_program);
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
			std::terminate();
	}

	Material::~Material() {
		if (vao)    glDeleteVertexArrays(1, &vao);
		if (vbo)    glDeleteBuffers(1, &vbo);
		if (shader) glDeleteProgram(shader);
	}

	Material::Material(Material&& other) noexcept {
		vao = other.vao;
		vbo = other.vbo;
		shader = other.shader;
		primitive = other.primitive;
		other.vao = NULL;
		other.vbo = NULL;
		other.shader = NULL;
		other.primitive = NULL;
	};

	Material& Material::operator = (Material&& other) noexcept {
		if (vao)    glDeleteVertexArrays(1, &vao);
		if (vbo)    glDeleteBuffers(1, &vbo);
		if (shader) glDeleteProgram(shader);
		vao = other.vao;
		vbo = other.vbo;
		shader = other.shader;
		primitive = other.primitive;
		other.vao = NULL;
		other.vbo = NULL;
		other.shader = NULL;
		other.primitive = NULL;
		return *this;
	}
}

