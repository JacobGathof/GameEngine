#pragma once
#include "AbstractAction.h"
#include "BattleManager.h"

class Object;

class StartBattleAction : public AbstractAction
{
public:
	StartBattleAction(Object * o);
	~StartBattleAction();

	virtual int run(float dt = 0.0f);
	virtual void reset();

private:
	Object * obj;
};

