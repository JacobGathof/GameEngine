#include "BattleTransitionAction.h"
#include "GlobalActionInvoker.h"
#include "ScreenFadeAction.h"
#include "RoomChangeAction.h"
#include "CombatStartAction.h"


BattleTransitionAction::BattleTransitionAction(Vector2f& pos)
{
	position = pos;
}


BattleTransitionAction::~BattleTransitionAction()
{
}

int BattleTransitionAction::run(float dt)
{
	GlobalActionInvoker::addActionSet({
		new CombatStartAction(position),
	});

	return 1;
}