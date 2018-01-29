#pragma once
#include <map>
#include <vector>
#include "Key.h"
#include "List.h"

class Input
{
public:

	enum class KeyMaps {
		KEY_UP,
		KEY_DOWN,
		KEY_RIGHT,
		KEY_LEFT,
		KEY_INTERACT,
		KEY_SKILL_1,
		KEY_SKILL_2,
		KEY_SKILL_3,
		KEY_SKILL_4,
		KEY_SKILL_5
	};

	Input();
	~Input();

	static List<Key> keyQueue;
	static std::map<int, KeyMaps> physicalMap;
	static std::map<KeyMaps, Key> keyMap;

	static bool keys[512];

	static void processInput(float dt);
	static void feedKey(int key, int state);
	

private:

	static void setupKeybinds();
	static std::map<int, int> keyBinds;

};

