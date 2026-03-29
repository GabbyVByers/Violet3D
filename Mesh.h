
/*
	Mesh.h
*/

#pragma once
#include "Types.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace Violet {

	class Camera;
	class Material;
	class Transform;
	class Texture;
	class Vertex;
	class Mesh;

	class Camera {
	public:
		Camera();
		double fov_degrees;
		double near, far;
		Vec3d  position;
		Quat   orientation;

		Vec3d forward() const;
		Vec3d up() const;
		Vec3d right() const;

		Mat4 view_matrix() const;
		Mat4 projection_matrix(const Vec2i& window_size) const;
	};

	class Material {
	public:
		GLuint vao = NULL;
		GLuint vbo = NULL;
		GLuint shader = NULL;
		GLenum primitive = NULL;
		Material(const std::string& path, GLenum type);
		~Material();
		Material(Material&& other) noexcept;
		Material(const Material& other) = delete;
		Material& operator = (Material&& other) noexcept;
		Material& operator = (const Material& other) = delete;
	};

	class Transform {
	public:
		double scale = 1.0;
		Vec3d position = Vec3d();
		Quat orientation = Quat();
		Mat4 model_matrix() const;
	};

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

	class Vertex {
	public:
		Vec3f position = Vec3f();
		Color color = Color::white();
		Vec2f tex_coord = Vec2f();
	};

	class Mesh {
	public:
		Material material = Material("default", GL_TRIANGLES);
		Transform transform = Transform();
		Texture texture = Texture();
		std::vector<Vertex> vertices = std::vector<Vertex>();
	};
}

