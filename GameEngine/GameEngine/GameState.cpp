#include "GameState.h"
#include "Inventory.h"
#include "BattleManager.h"

std::string GameState::globalDebug;
float GameState::sliderValue;
float GameState::ui_blue;

int GameState::choicePointer;
Inventory GameState::inv;
BattleManager GameState::battleManager(nullptr);

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
