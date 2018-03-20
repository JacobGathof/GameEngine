#include "GameState.h"

std::string GameState::globalDebug;
float GameState::sliderValue;
float GameState::ui_blue;
std::string GameState::playerName = "Player";

int GameState::choicePointer;

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
