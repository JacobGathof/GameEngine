#pragma once
#include <string>
#include "Graph.h"


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
	static std::string playerName;
	static bool textboxEmpty;

	static Graph* graph;

	static Inventory inv;

private:
	static std::string globalDebug;


};

