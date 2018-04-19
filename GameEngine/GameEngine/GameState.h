#pragma once
#include <string>

class Inventory;

class GameState
{
public:
	GameState();
	~GameState();

	static std::string getGlobalDebug();
	static void setGlobalDebug(std::string str);


	static float sliderValue;
	static float ui_blue;
	static int choicePointer;

	static Inventory inv;

private:
	static std::string globalDebug;


};

