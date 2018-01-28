#include "ShaderManager.h"
#include "Window.h"
#include "Screen.h"
#include "Callbacks.h"


Callbacks::Callbacks() {}
Callbacks::~Callbacks() {}

void Callbacks::CursorPosCallback(GLFWwindow * window, double xpos, double ypos) {
}

void Callbacks::KeyCallback(GLFWwindow * window, int key, int scancode, int action, int mods) {
	Input::feedKey(key, action);
}

void Callbacks::MouseCallback(GLFWwindow * window, int button, int action, int mods) {
}

void Callbacks::WindowSizeCallback(GLFWwindow * window, int width, int height) {
	if (Window::isInitialized()) {
		glViewport(0, 0, width, height);
		Screen::updateRes(width, height);
	}
}

void Callbacks::ScrollCallback(GLFWwindow * window, double xoffset, double yoffset) {
	Screen::updateScroll(yoffset / 200.0f);
}
