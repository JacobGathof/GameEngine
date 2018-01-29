#pragma once

#include <GLFW3.h>

class Key
{
public:

	enum class KeyState {
		KEY_UP,
		KEY_RELEASED,
		KEY_PRESSED,
		KEY_DOWN
	};

	Key();
	~Key();

	KeyState state;

	void update(int keyEvent);
	void updateState();
	bool getState(KeyState state);
};

