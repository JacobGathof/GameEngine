#include "ScreenFollowAction.h"



ScreenFollowAction::ScreenFollowAction(Object * obj)
{
	follow = obj;
}

ScreenFollowAction::~ScreenFollowAction()
{
}

int ScreenFollowAction::run(float dt)
{
	Screen::setMovementBehavior(Screen::followBehavior);
	Screen::setTargetPosition(&follow->pos);
	return 1;
}
