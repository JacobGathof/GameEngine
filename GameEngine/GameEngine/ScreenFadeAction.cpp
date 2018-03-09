#include "ScreenFadeAction.h"
#include "Screen.h"


ScreenFadeAction::ScreenFadeAction(Color c, float f, int di)
{
	timer.reset();
	timer.setTickLength(f);
	color = c;
	fl = f;
	direction = di;
}

ScreenFadeAction::~ScreenFadeAction()
{
}

int ScreenFadeAction::run(float dt)
{
	timer.update(dt);
	Screen::screenColor = color;
	Screen::screenColorPercent = abs(direction - timer.getTotalTime()/fl);
	return timer.tick();
}

void ScreenFadeAction::reset()
{
	timer.reset();
}
