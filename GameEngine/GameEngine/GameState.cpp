#include "GameState.h"
#include "Inventory.h"
#include "BattleManager.h"

std::string GameState::globalDebug;
float GameState::sliderValue = .5f;
float GameState::ui_blue;
std::string GameState::playerName = "Player";
bool GameState::textboxEmpty = true;

int GameState::choicePointer;
Inventory* GameState::inv;

Graph* GameState::graph;
BattleManager GameState::battleManager;

ApplicationControl GameState::applicationState;
std::map<std::string, bool> GameState::flags;


float GameState::red;
float GameState::green;
float GameState::blue;
float GameState::volume;

Color GameState::color;

GameState::GameState()
{
}


GameState::~GameState()
{
}

std::string GameState::getGlobalDebug()
{
	return globalDebug;
}

void GameState::setGlobalDebug(std::string str){
	globalDebug = str;
}

bool GameState::isGamePaused()
{
	return applicationState.gamePaused;
}
