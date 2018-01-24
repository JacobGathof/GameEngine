#pragma once
#include <map>
#include "StatsPage.h"

class Input
{
public:
	Input();
	~Input();

	static bool keys[512];

	static void processInput(float dt);
	static void feedKey(int key, int state);


private:

	static void setupKeybinds();
	static std::map<int, int> keyBinds;

};

