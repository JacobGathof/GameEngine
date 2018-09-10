#include "StartBattleAction.h"
#include "Object.h"
#include "GameState.h"


StartBattleAction::StartBattleAction(Object * o)
{
	obj = o;
}


StartBattleAction::~StartBattleAction()
{
}

int StartBattleAction::run(float dt)
{
	if (GameState::battleManager.battleState != NOBATTLE) {
		return 0;
	}
	
	GameState::battleManager.transitionBattle(obj);
	//GameState::battleManager.startBattle(obj);
	return 0;
}

void StartBattleAction::reset()
{
}
