#pragma once

#include "AbstractAction.h"
#include "Screen.h"
#include "Object.h"

class ScreenFollowAction : public AbstractAction
{
public:
	ScreenFollowAction(Object * obj);
	~ScreenFollowAction();

	Object * follow;

	virtual int run(float dt = 0);
};

