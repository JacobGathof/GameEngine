#include "Mouse.h"

#define DOUBLE_CLICK_FRAMES 20

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
		clicked.push(button);
	}
	if (state == GLFW_RELEASE) {
		mouseButtons[button] = MouseState::RELEASE;
		released.push(button);
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

void Mouse::setScroll(int i)
{
	scroll = i;
}

void Mouse::update()
{

	scroll = 0;
	dClick = false;

	if (mouseButtons[GLFW_MOUSE_BUTTON_LEFT] == MouseState::CLICK) {
		if (clickDelay > 0) {
			dClick = true;
		}
		clickDelay = DOUBLE_CLICK_FRAMES;
	}
	clickDelay = std::max(0, clickDelay - 1);



	while (!clicked.empty()) {
		mouseButtons[clicked.front()] = MouseState::DOWN;
		clicked.pop();
	}

	while (!released.empty()) {
		mouseButtons[released.front()] = MouseState::UP;
		released.pop();
	}

	

	lastPosition = position;
}

bool Mouse::down(int i)
{
	return (mouseButtons[i] == MouseState::DOWN || mouseButtons[i] == MouseState::CLICK);
}

bool Mouse::up(int i)
{
	return (mouseButtons[i] == MouseState::UP || mouseButtons[i] == MouseState::RELEASE);
}

bool Mouse::click(int i)
{
	return mouseButtons[i] == MouseState::CLICK;
}

bool Mouse::release(int i)
{
	return mouseButtons[i] == MouseState::RELEASE;
}

int Mouse::getScroll()
{
	return scroll;
}

bool Mouse::mouseMoved()
{
	return lastPosition != position;
}

bool Mouse::doubleClick()
{
	return dClick;
}

