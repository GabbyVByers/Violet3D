
#include "Violet.h"

void Violet::Window::create(std::string title, int width, int height) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window_ptr = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(window_ptr);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glfwSetFramebufferSizeCallback(window_ptr, callBackWindowResize);
	glfwSetKeyCallback(window_ptr, callBackKeyboard);
	glfwSetMouseButtonCallback(window_ptr, callBackMouse);
	glfwSetScrollCallback(window_ptr, callBackMouseScroll);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.FontGlobalScale = 2.0f;
	io.IniFilename = nullptr;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window_ptr, true);
	ImGui_ImplOpenGL3_Init("#version 330");
}

void Violet::Window::destroy() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(window_ptr);
	glfwTerminate();
}

void Violet::Window::vSync(bool vsync) {
	glfwSwapInterval((int)vsync);
}

Math::Vec2i Violet::Window::getWindowSize() {
	int x, y;
	glfwGetFramebufferSize(window_ptr, &x, &y);
	return { x, y };
}

GLFWwindow* Violet::Window::getWindowPtr() {
	return window_ptr;
}

bool Violet::Window::isOpen() {
	return !glfwWindowShouldClose(window_ptr);
}

void Violet::Window::pollEvents() {
	glfwPollEvents();
}

void Violet::Window::clear(Math::Color color) {
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Violet::Window::draw(const Mesh& mesh, Camera& camera) {
	const GLuint vao = mesh.vao;
	const GLuint vbo = mesh.vbo;
	const GLuint shader = mesh.shader;

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glUseProgram(shader);
}

void Violet::Window::display() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(window_ptr);
}

void Violet::Window::callBackWindowResize(GLFWwindow* window_ptr, int width, int height) {
	std::cout << "hi\n";
}

void Violet::Window::callBackKeyboard(GLFWwindow* window_ptr, int key, int scancode, int action, int mods) {

}

void Violet::Window::callBackMouse(GLFWwindow* window_ptr, int button, int action, int mods) {

}

void Violet::Window::callBackMouseScroll(GLFWwindow* window_ptr, double xoffset, double yoffset) {

}

