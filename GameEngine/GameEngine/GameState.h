#pragma once
#include <string>
#include "Graph.h"
#include "Inventory.h"


class Inventory;
class BattleManager;

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
	static BattleManager battleManager;

	static Inventory* inv;

private:
	static std::string globalDebug;


};

