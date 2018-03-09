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
	ARROW_UP,
	ARROW_DOWN,
	ARROW_LEFT,
	ARROW_RIGHT,
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

	void setKeyBind(VirtualKey vk, int k);
	int getKeyBind(VirtualKey vk);

	int getCurrentPressed();
	char* getKeyName(VirtualKey vk);
	const char* getRealKeyName(int key);
	const char* getRealKeyName(VirtualKey key);

private:
	KeyState keys[512];
	std::queue<int> pressed;
	std::queue<int> released;

	std::map<VirtualKey, int> virtualMap;
	std::map<VirtualKey, char*> nameMap;


};

