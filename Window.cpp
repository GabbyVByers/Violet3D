
#include "Window.h"

Violet::Window::Window(std::string title, int width, int height) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if (window_ptr != nullptr)
		std::terminate();
	window_ptr = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(window_ptr);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
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

Violet::Window::~Window() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(window_ptr);
	window_ptr = nullptr;
	glfwTerminate();
}

Violet::Vec2i Violet::Window::size() {
	int x, y; glfwGetFramebufferSize(window_ptr, &x, &y);
	return { x, y };
}

void Violet::Window::vsync(bool vsync) {
	glfwSwapInterval((int)vsync);
}

bool Violet::Window::is_open() {
	return !glfwWindowShouldClose(window_ptr);
}

void Violet::Window::poll_events() {
	Window::mouse().reset();
	Window::keyboard().reset();
	glfwPollEvents();
}

void Violet::Window::clear(Violet::Color color) {
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Violet::Window::draw(const Mesh& mesh, Camera& camera) {
	const GLuint vao = mesh.material.vao;
	const GLuint vbo = mesh.material.vbo;
	const GLuint ebo = mesh.material.ebo;
	const GLuint shader = mesh.material.shader;
	const GLuint primitive = mesh.material.primitive;
	const GLuint texture = mesh.texture.texture;
	const std::vector<Vertex>& vertices = mesh.vertices;
	const std::vector<unsigned int>& indices = mesh.indices;

	if (vertices.size() == 0)
		return;

	if (indices.size() == 0)
		return;

	glUseProgram(shader);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(shader, "ourTexture"), NULL);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	Mat4 model_matrix = Math::model_matrix(mesh);
	Mat4 view_matrix = Math::view_matrix(camera);
	Mat4 projection_matrix = Math::projection_matrix(camera, Window::size());
	Mat4 model_view_project = projection_matrix * view_matrix * model_matrix;
	Mat4f mvp_float = Math::float_matrix(model_view_project);
	glUniformMatrix4fv(glGetUniformLocation(shader, "uModelViewProject"), 1, GL_TRUE, &mvp_float.data[0][0]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_DYNAMIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_DYNAMIC_DRAW);
	glDrawElements(primitive, (GLsizei)indices.size(), GL_UNSIGNED_INT, NULL);
}

void Violet::Window::display() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(window_ptr);
}

Violet::Mouse& Violet::Window::mouse() {
	static Mouse mouse(window_ptr);
	return mouse;
}

Violet::Keyboard& Violet::Window::keyboard() {
	static Keyboard keyboard(window_ptr);
	return keyboard;
}

void Violet::Window::callback_window_resize(GLFWwindow* window_ptr, int width, int height) {
	glViewport(0, 0, width, height);
}

void Violet::Window::callback_keyboard(GLFWwindow* window_ptr, int key, int scancode, int action, int mods) {
	GlfwKeyboardEvent key_event = {
		key,
		scancode,
		action,
		mods
	};
	Keyboard& keyboard = Window::keyboard();
	keyboard.push_key_event(key_event);
}

void Violet::Window::callback_mouse(GLFWwindow* window_ptr, int button, int action, int mods) {
	GlfwMouseEvent mouse_event = {
		button,
		action,
		mods
	};
	Mouse& mouse = Window::mouse();
	mouse.push_mouse_event(mouse_event);
}

void Violet::Window::callback_mousescroll(GLFWwindow* window_ptr, double xoffset, double yoffset) {
	GlfwScrollEvent scroll_event{
		xoffset,
		yoffset
	};
	Mouse& mouse = Window::mouse();
	mouse.push_scroll_event(scroll_event);
}

