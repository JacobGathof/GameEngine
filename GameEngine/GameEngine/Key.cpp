#include "Key.h"

Key::Key()
{
}

Key::~Key()
{
}

void Key::update(int keyEvent)
{
	if (keyEvent == GLFW_PRESS) {
		state = KeyState::KEY_PRESSED;
	}
	else if (keyEvent == GLFW_RELEASE) {
		state = KeyState::KEY_RELEASED;
	}
}

void Key::updateState()
{
	if (state == KeyState::KEY_PRESSED) {
		state = KeyState::KEY_DOWN;
	}
	else if (state == KeyState::KEY_RELEASED) {
		state = KeyState::KEY_UP;
	}
}

bool Key::getState(KeyState st)
{
	if (st == KeyState::KEY_UP) {
		return (state == KeyState::KEY_UP || state == KeyState::KEY_RELEASED);
	}
	else if (st == KeyState::KEY_RELEASED) {
		return (state == KeyState::KEY_RELEASED);
	}
	else if (st == KeyState::KEY_PRESSED) {
		return state == KeyState::KEY_PRESSED;
	}
	else {
		return state == KeyState::KEY_PRESSED || state == KeyState::KEY_DOWN;
	}
}
