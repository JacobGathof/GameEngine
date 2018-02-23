#pragma once
#include <string>
class GameState
{
public:
	GameState();
	~GameState();

	static std::string getGlobalDebug();
	static void setGlobalDebug(std::string str);

	static float sliderValue;
	static float ui_blue;

private:
	static std::string globalDebug;

};

