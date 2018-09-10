#pragma once
#include "AbstractAction.h"
#include "Vector2f.h"


class BattleTransitionAction : public AbstractAction
{
public:
	BattleTransitionAction(Vector2f& pos);
	~BattleTransitionAction();

	virtual int run(float dt = 0.0f);
	Vector2f position;
};

