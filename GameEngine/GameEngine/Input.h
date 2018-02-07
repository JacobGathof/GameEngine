#pragma once
#include <map>
#include <vector>
#include "List.h"
#include "PlayerAI.h"
#include "UIManager.h"

class Input
{
public:

	Input();
	~Input();

	static std::map<int, KeyMaps> physicalMap;
	static PlayerAI * ai;

	static bool keys[512];

	static void processInput(float dt);
	static void feedKey(int key, int state);
	static void init();
	static void feedMousePosition(Vector2f& pos);
	

private:

	static void setupKeybinds();
	static std::map<int, int> keyBinds;

};

