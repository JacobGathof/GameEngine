#include "ShaderManager.h"
#include "FramebufferManager.h"
#include "Window.h"
#include "Screen.h"
#include "Callbacks.h"


Callbacks::Callbacks() {}
Callbacks::~Callbacks() {}

void Callbacks::CursorPosCallback(GLFWwindow * window, double xpos, double ypos) {
	Input::feedMousePosition(Screen::fromScreenToUISpace(Vector2f((float)xpos, (float)ypos)));
}

void Callbacks::KeyCallback(GLFWwindow * window, int key, int scancode, int action, int mods) {
	Input::feedKey(key, action);
}

void Callbacks::MouseCallback(GLFWwindow * window, int button, int action, int mods) {
	Input::feedMouseEvent(button, action);
}

void Callbacks::WindowSizeCallback(GLFWwindow * window, int width, int height) {
	if (Window::isInitialized()) {
		glViewport(0, 0, width, height);
		Screen::updateRes((float)width, (float)height);
		Window::setSize(width, height);
	}
}

void Callbacks::ScrollCallback(GLFWwindow * window, double xoffset, double yoffset) {
	Screen::updateScroll((float)yoffset / 200.0f);
}

void Callbacks::WindowPosCallback(GLFWwindow * window, int x, int y)
{
}
