#include "Window.h"
#include "Input.h"

GLFWwindow* Window::window;
int Window::WINDOW_HEIGHT = 0;
int Window::WINDOW_WIDTH = 0;
int Window::WINDOW_X = 0;
int Window::WINDOW_Y = 0;
bool Window::initialized = false;
bool Window::fullscreen = false;
char* Window::WINDOW_TITLE = "";
Color Window::clearColor = Color(0x00000000);


void Window::init(char* title, int width, int height) {
	if (!glfwInit()) {
		std::cerr << "Cannot initialize GLFW" << std::endl;
	}

	setWindowHints();

	WINDOW_HEIGHT = height;
	WINDOW_WIDTH = width;
	WINDOW_TITLE = title;

	
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);

	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, 0, 0);

	setCallbacks();

	glfwSetWindowPos(window, (mode->width - WINDOW_WIDTH)/2, (mode->height - WINDOW_HEIGHT) / 2);

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);


	initOpenGL();

	centerCursor();
	initialized = true;

}

void Window::destroy() {

	glfwDestroyWindow(window);
	glfwTerminate();
}

bool Window::shouldClose(){
	return glfwWindowShouldClose(window);
}

void Window::close(){
	glfwSetWindowShouldClose(window, 1);
}

void Window::centerCursor(){
	glfwSetCursorPos(window, WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);
}

bool Window::isInitialized(){
	return initialized;
}

void Window::swapBuffers(){
	glfwSwapBuffers(window);
}

void Window::pollEvents(){
	glfwPollEvents();
}

void Window::show(){
	glfwShowWindow(window);
}


void Window::setCallbacks(){

	glfwSetKeyCallback(window, Callbacks::KeyCallback);
	glfwSetCursorPosCallback(window, Callbacks::CursorPosCallback);
	glfwSetMouseButtonCallback(window, Callbacks::MouseCallback);
	glfwSetWindowSizeCallback(window, Callbacks::WindowSizeCallback);
	glfwSetScrollCallback(window, Callbacks::ScrollCallback);
	glfwSetWindowPosCallback(window, Callbacks::WindowPosCallback);
	glfwSetWindowFocusCallback(window, Callbacks::WindowFocusCallback);
}

void Window::setWindowHints(){

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Window::initOpenGL(){

	gl3w_init();
	//glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glPointSize(1.0f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0,0,0,0);

}

//GLFW_CURSOR_HIDDEN, GLFW_CURSOR_DISABLED, GLFW_CURSOR_NORMAL
void Window::setCursorMode(int mode){
	glfwSetInputMode(window, GLFW_CURSOR, mode);
}

float Window::getAspectRatio()
{
	return (float)WINDOW_HEIGHT / WINDOW_WIDTH;
}

void Window::setMaximize(bool m)
{
	if (m) {
		glfwMaximizeWindow(window);
	}
	else {
		glfwRestoreWindow(window);
	}
}

void Window::toggleFullscreen()
{
	if (!fullscreen) {
		fullscreen = true;
		glfwGetWindowPos(window, &Window::WINDOW_X, &Window::WINDOW_Y);
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(monitor);
		std::cout << mode->refreshRate << std::endl;
		glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
	}
	else {
		fullscreen = false;
		if (Window::WINDOW_X == 0 || Window::WINDOW_Y == 0) {
			glfwGetWindowPos(window, &Window::WINDOW_X, &Window::WINDOW_Y);
		}
		glfwSetWindowMonitor(window, NULL, WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	}

}

void Window::setSize(int width, int height)
{

	if (!fullscreen) {
		WINDOW_WIDTH = width;
		WINDOW_HEIGHT = height;
	}
}










void Window::Callbacks::CursorPosCallback(GLFWwindow * window, double xpos, double ypos) {
	Input::feedMousePosition(Screen::fromScreenToUISpace(Vector2f((float)xpos, (float)ypos)));
}

void Window::Callbacks::KeyCallback(GLFWwindow * window, int key, int scancode, int action, int mods) {
	Input::feedKey(key, action, mods);
}

void Window::Callbacks::MouseCallback(GLFWwindow * window, int button, int action, int mods) {
	Input::feedMouseEvent(button, action);
}

void Window::Callbacks::WindowSizeCallback(GLFWwindow * window, int width, int height) {
	if (Window::isInitialized()) {
		glViewport(0, 0, width, height);
		Screen::updateRes((float)width, (float)height);
		Window::setSize(width, height);
	}
}

void Window::Callbacks::ScrollCallback(GLFWwindow * window, double xoffset, double yoffset) {
	Input::feedMouseScroll((int)yoffset);
}

void Window::Callbacks::WindowPosCallback(GLFWwindow * window, int x, int y)
{
}

void Window::Callbacks::WindowFocusCallback(GLFWwindow * window, int focused)
{
	if (focused) {

	} else {
		//Input::pause();
	}
}



