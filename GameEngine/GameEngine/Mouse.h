#pragma once
#include "Vector2f.h"
#include "glfw3.h"

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

	bool down();
	bool up();
	bool click();
	bool release();

private:
	Vector2f position;
	MouseState mouseButtons[32];

};

