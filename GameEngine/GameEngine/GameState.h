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

private:
	static std::string globalDebug;

};

