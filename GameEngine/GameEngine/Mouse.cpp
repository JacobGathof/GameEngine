#include "Mouse.h"



Mouse::Mouse(){}
Mouse::~Mouse(){}


MouseState& Mouse::operator[](int i)
{
	return mouseButtons[i];
}

MouseState Mouse::getButton(int i)
{
	return mouseButtons[i];
}

void Mouse::setButton(int button, int state)
{
	if (state == GLFW_PRESS) {
		mouseButtons[button] = MouseState::CLICK;
	}
	if (state == GLFW_RELEASE) {
		mouseButtons[button] = MouseState::RELEASE;
	}
}

Vector2f & Mouse::pos()
{
	return position;
}

void Mouse::setPosition(Vector2f & p)
{
	position = p;
}

bool Mouse::down()
{
	return (mouseButtons[GLFW_MOUSE_BUTTON_LEFT] == MouseState::DOWN || mouseButtons[GLFW_MOUSE_BUTTON_LEFT] == MouseState::CLICK);
}

bool Mouse::up()
{
	return (mouseButtons[GLFW_MOUSE_BUTTON_LEFT] == MouseState::UP || mouseButtons[GLFW_MOUSE_BUTTON_LEFT] == MouseState::RELEASE);
}

bool Mouse::click()
{
	return mouseButtons[GLFW_MOUSE_BUTTON_LEFT] == MouseState::CLICK;
}

bool Mouse::release()
{
	return mouseButtons[GLFW_MOUSE_BUTTON_LEFT] == MouseState::RELEASE;
}

