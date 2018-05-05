#include "GameState.h"
#include "Inventory.h"
#include "BattleManager.h"

std::string GameState::globalDebug;
float GameState::sliderValue;
float GameState::ui_blue;
std::string GameState::playerName = "Player";
bool GameState::textboxEmpty = true;

int GameState::choicePointer;
Inventory* GameState::inv;

Graph* GameState::graph;
BattleManager GameState::battleManager;

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
