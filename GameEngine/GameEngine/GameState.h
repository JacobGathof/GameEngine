#pragma once
#include <string>
#include "Graph.h"
#include "Inventory.h"


class Inventory;
class BattleManager;

struct ApplicationControl {
	bool gamePaused = false;
	int fps = 60;
};



class GameState
{
public:
	GameState();
	~GameState();

	static ApplicationControl applicationState;


	static std::string getGlobalDebug();
	static void setGlobalDebug(std::string str);


	static bool isGamePaused();

	static float sliderValue;
	static float ui_blue;
	static int choicePointer;
	static std::string playerName;
	static bool textboxEmpty;

	static Graph* graph;
	static BattleManager battleManager;

	static Inventory* inv;

	static std::map<std::string, bool> flags;


	static float blue;
	static float green;
	static float red;
	static float volume;

private:
	static std::string globalDebug;


};

