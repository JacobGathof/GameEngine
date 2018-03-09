#pragma once
#include "AbstractScriptAction.h"
#include "Timer.h"
#include "Color.h"

#define SCREEN_FADE_OUT 0
#define SCREEN_FADE_IN 1

class ScreenFadeAction : public AbstractScriptAction
{
public:
	ScreenFadeAction(Color c, float f, int di);
	~ScreenFadeAction();
	virtual int run(float dt);
	virtual void reset();
private:
	Color color;
	Timer timer;
	float fl;
	int direction;
};

