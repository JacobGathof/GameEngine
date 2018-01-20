#include "ShaderManager.h"
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
	glViewport(0, 0, width, height);
	ShaderManager::get(ShaderType::TEXT_SHADER)->bind();
	ShaderManager::get(ShaderType::TEXT_SHADER)->loadFloat("aspect_ratio", (float)width/height);
}

void Callbacks::ScrollCallback(GLFWwindow * window, double xoffset, double yoffset) {
}
