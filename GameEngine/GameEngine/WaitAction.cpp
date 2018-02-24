#include "WaitAction.h"



WaitAction::WaitAction(float time)
{
	timer.reset();
	timer.setTickLength(time);
}

WaitAction::~WaitAction()
{
}

int WaitAction::run(float dt)
{
	timer.update(dt);
	return timer.tick();
}
