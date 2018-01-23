#pragma once
#include <map>
#include <vector>

class Input
{
public:
	Input();
	~Input();

	static bool keys[512];

	//Get rid of this
	static std::vector<char> keysDown;

	static void processInput(float dt);
	static void feedKey(int key, int state);
	

private:

	static void setupKeybinds();
	static std::map<int, int> keyBinds;

};

