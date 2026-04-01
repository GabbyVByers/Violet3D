
/*
	Window.cpp
*/

#include "Window.h"

namespace Vi {

	Window::Window(std::string title, int width, int height) {
		Log::assert_concern(instances++ == NULL, WINDOW_SINGLETON_VIOLATED);

		GLuint status = glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		Log::assert_concern(status != NULL, GLFW_INIT_FAIL);

		window_ptr = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		Log::assert_concern(window_ptr != nullptr, GLFW_WINDOW_CREATE_FAIL);
		glfwMakeContextCurrent(window_ptr);

		status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		Log::assert_concern(status != NULL, GLAD_LOAD_FAIL);

		glViewport(0, 0, width, height);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_PROGRAM_POINT_SIZE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glfwSetFramebufferSizeCallback(window_ptr, callback_window_resize);
		glfwSetKeyCallback(window_ptr, callback_keyboard);
		glfwSetMouseButtonCallback(window_ptr, callback_mouse);
		glfwSetScrollCallback(window_ptr, callback_mousescroll);

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.FontGlobalScale = 1.7f;
		io.IniFilename = nullptr;
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(window_ptr, true);
		ImGui_ImplOpenGL3_Init("#version 330");
	}

	Window::~Window() {
		instances = NULL;
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
		glfwDestroyWindow(window_ptr);
		glfwTerminate();
	}

	Vec2i Window::size() {
		int x, y; glfwGetFramebufferSize(window_ptr, &x, &y);
		return { x, y };
	}

	void Window::vsync(bool vsync) {
		glfwSwapInterval((int)vsync);
	}

	bool Window::is_open() {
		return !glfwWindowShouldClose(window_ptr);
	}

	void Window::poll_events() {
		Window::mouse().reset();
		Window::keyboard().reset();
		glfwPollEvents();
	}

	void Window::clear(Color color) {
		glClearColor(color.r, color.g, color.b, color.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void Window::draw(const Mesh& mesh, Camera& camera) {
		const GLuint vao = mesh.material.vao;
		const GLuint vbo = mesh.material.vbo;
		const GLuint shader = mesh.material.shader;
		const GLuint primitive = mesh.material.primitive;
		const GLuint texture = mesh.texture.texture;
		const std::vector<Vertex>& vertices = mesh.vertices;

		if (vertices.size() == 0)
			return;

		glUseProgram(shader);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glUniform1i(glGetUniformLocation(shader, "ourTexture"), NULL);

		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		Mat4 model_matrix = mesh.transform.model_matrix();
		Mat4 view_matrix = camera.view_matrix();
		Mat4 projection_matrix = camera.projection_matrix(size());
		Mat4 model_view_project = projection_matrix * view_matrix * model_matrix;
		Mat4f mvp_float = model_view_project;
		glUniformMatrix4fv(glGetUniformLocation(shader, "uModelViewProject"), 1, GL_TRUE, &mvp_float.data[0][0]);

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_DYNAMIC_DRAW);
		glDrawArrays(primitive, NULL, (GLsizei)vertices.size());
	}

	void Window::display() {
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window_ptr);
	}

	Mouse& Window::mouse() {
		internal_mouse.window_ptr = window_ptr;
		return internal_mouse;
	}

	Keyboard& Window::keyboard() {
		internal_keyboard.window_ptr = window_ptr;
		return internal_keyboard;
	}

	void Window::callback_window_resize(GLFWwindow* ptr, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void Window::callback_keyboard(GLFWwindow* ptr, int key, int scancode, int action, int mods) {
		GlfwKeyboardEvent key_event = {
			key,
			scancode,
			action,
			mods
		};
		Keyboard& keyboard = Window::keyboard();
		keyboard.push_key_event(key_event);
	}

	void Window::callback_mouse(GLFWwindow* ptr, int button, int action, int mods) {
		GlfwMouseEvent mouse_event = {
			button,
			action,
			mods
		};
		Mouse& mouse = Window::mouse();
		mouse.push_mouse_event(mouse_event);
	}

	void Window::callback_mousescroll(GLFWwindow* ptr, double xoffset, double yoffset) {
		GlfwScrollEvent scroll_event{
			xoffset,
			yoffset
		};
		Mouse& mouse = Window::mouse();
		mouse.push_scroll_event(scroll_event);
	}
}

