
#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <sstream>
#include "Math.h"

#define Violet Violet
namespace Violet {

	class Vertex;
	class Camera;
	class Mesh;
	class glMouseEvent;
	class glScrollEvent;
	class glKeyboardEvent;
	class Mouse;
	class Keyboard;
	class Window;

	class Vertex {
	public:
		Math::Vec3f position;
		Math::Color color;
	};

	class Camera {
	public:
		double fov;
		double aspect;
		double near;
		double far;
		Math::Transformation trans;
		Camera();
	};

	class Mesh {
	public:
		GLuint vao;
		GLuint vbo;
		GLuint shader;
		Math::Transformation trans;
		GLenum primative_type;
		std::vector<Vertex> vertices;
		void create(const std::string& path = "default", GLenum type = GL_TRIANGLES);
		void destroy();
	};

	class glMouseEvent {
	public:
		int button;
		int action;
		int mods;
	};

	class glScrollEvent {
	public:
		double xoffset;
		double yoffset;
	};

	class glKeyboardEvent {
	public:
		int key;
		int scancode;
		int action;
		int mods;
	};

	class Mouse {
	public:
		Mouse()  = delete;
		~Mouse() = delete;
	private:
		double xpos, ypos, xvel, yvel;
		std::vector<glMouseEvent> mouse_events;
		std::vector<glScrollEvent> scroll_events;
	};

	class Keyboard {
	public:
		Keyboard()  = delete;
		~Keyboard() = delete;
	};

	class Window {
	public:
		Window()  = delete;
		~Window() = delete;
		static void create(std::string title, int width, int height);
		static void destroy();
		static void vSync(bool vsync);
		static Math::Vec2i getWindowSize();
		static GLFWwindow* getWindowPtr();
		static bool isOpen();
		static void pollEvents();
		static void clear(Math::Color color);
		static void draw(const Mesh& mesh, Camera& camera);
		static void display();

	private:
		inline static GLFWwindow* window_ptr = nullptr;
		static void callBackWindowResize(GLFWwindow* window_ptr, int width, int height);
		static void callBackKeyboard(GLFWwindow* window_ptr, int key, int scancode, int action, int mods);
		static void callBackMouse(GLFWwindow* window_ptr, int button, int action, int mods);
		static void callBackMouseScroll(GLFWwindow* window_ptr, double xoffset, double yoffset);
	};
}

