#pragma once
#include "AbstractScriptAction.h"
#include "Timer.h"
#include "Color.h"

class ScreenFadeAction : public AbstractScriptAction
{
public:
	ScreenFadeAction(Color c, float f, int di);
	~ScreenFadeAction();
	virtual int run(float dt);
private:
	Color color;
	Timer timer;
	float fl;
	int direction;
};

