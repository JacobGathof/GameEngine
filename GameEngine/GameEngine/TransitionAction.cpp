#include "TransitionAction.h"
#include "GlobalActionInvoker.h"
#include "ScreenFadeAction.h"
#include "RoomChangeAction.h"

TransitionAction::TransitionAction()
{
}


TransitionAction::~TransitionAction()
{
}

int TransitionAction::run(float dt)
{
	GlobalActionInvoker::addActionSet({
		new ScreenFadeAction(Color::Black, 2.0f, SCREEN_FADE_OUT),
		new RoomChangeAction(World::RoomNames::CLEARING),
		new ScreenFadeAction(Color::Black, 2.0f, SCREEN_FADE_IN),
	});

	return 1;
}
