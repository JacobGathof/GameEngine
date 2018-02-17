#include "Window.h"

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

	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, 0, 0);

	setCallbacks();

	glfwSetWindowPos(window, 10, 40);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	initOpenGL();

	glfwShowWindow(window);

	centerCursor();
	initialized = true;

}

void Window::destroy() {

	glfwDestroyWindow(window);
	glfwTerminate();
}

bool Window::shouldClose(){
	return glfwWindowShouldClose(window) ? 1 : 0;
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
	glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
}

void Window::setCursorMode(int mode){
	//GLFW_CURSOR_HIDDEN, GLFW_CURSOR_DISABLED, GLFW_CURSOR_NORMAL
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

