#pragma once
#include "Vector2f.h"
#include "glfw3.h"
#include <queue>

enum class MouseState {
	UP,
	DOWN,
	CLICK,
	RELEASE,
};

class Mouse
{
public:
	Mouse();
	~Mouse();

	MouseState& operator[](int i);
	MouseState getButton(int i);
	void setButton(int button, int state);
	
	Vector2f& pos();
	void setPosition(Vector2f& p);
	void setScroll(int i);
	void update();

	bool down(int i = GLFW_MOUSE_BUTTON_LEFT);
	bool up(int i = GLFW_MOUSE_BUTTON_LEFT);
	bool click(int i = GLFW_MOUSE_BUTTON_LEFT);
	bool release(int i = GLFW_MOUSE_BUTTON_LEFT);

	int getScroll();
	bool mouseMoved();

	bool doubleClick();

private:
	Vector2f position;
	Vector2f lastPosition;
	MouseState mouseButtons[32];
	std::queue<int> clicked;
	std::queue<int> released;
	int scroll;
	int clickDelay;
	bool dClick;

};

