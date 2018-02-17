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

	static std::map<int, KeyMap> physicalMap;
	static PlayerAI * ai;

	static bool keys[512];
	static int mouseButtons[32];

	static Vector2f mousePtr;

	static void processInput(float dt);
	static void feedKey(int key, int state);
	static void init();
	static void feedMousePosition(Vector2f& pos);
	static void feedMouseEvent(int button, int action);
	

private:

	static void setupKeybinds();
	static std::map<int, int> keyBinds;

};

