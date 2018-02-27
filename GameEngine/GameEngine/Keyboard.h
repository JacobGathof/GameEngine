#pragma once
#include "glfw3.h"
#include <queue>
#include <map>

enum class KeyState {
	UP,
	DOWN,
	PRESS,
	RELEASE,
};

enum class VirtualKey {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	SKILL_1,
	SKILL_2,
	INTERACT,
};

class Keyboard
{
public:
	Keyboard();
	~Keyboard();

	KeyState getKeyState(int i);
	KeyState getKeyState(VirtualKey k);
	void setKeyState(int key, int state);
	void setKeyState(VirtualKey k, int state);

	void update();

	bool down(int key);
	bool up(int key);
	bool press(int key);
	bool release(int key);

	bool down(VirtualKey key);
	bool up(VirtualKey key);
	bool press(VirtualKey key);
	bool release(VirtualKey key);

private:
	KeyState keys[512];
	std::queue<int> pressed;
	std::queue<int> released;

	std::map<VirtualKey, int> virtualMap;

};

