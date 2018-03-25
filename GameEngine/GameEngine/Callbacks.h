#pragma once
#include "glfw3.h"
#include "Input.h"

class Callbacks
{
public:
	Callbacks();
	~Callbacks();

	static void CursorPosCallback(GLFWwindow* window, double xpos, double ypos);
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void MouseCallback(GLFWwindow* window, int button, int action, int mods);
	static void WindowSizeCallback(GLFWwindow* window, int width, int height);
	static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	static void WindowPosCallback(GLFWwindow* window, int x, int y);
};

