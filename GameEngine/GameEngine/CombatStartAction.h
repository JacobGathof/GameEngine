#pragma once

#include "AbstractAction.h"
#include "CircleHitbox.h"
class Object;


class CombatStartAction : public AbstractAction
{
public:
	CombatStartAction(Vector2f& pos);
	~CombatStartAction();

	virtual int run(float dt = 0.0f);

private:
	float timer = 0.0f;
	float timeToWait = 4.0f;
	float circleGrowthRate = 256.0f;
	Vector2f position;
	CircleHitbox hit = CircleHitbox(.5f, Vector2f(0, 0));
	Object * obj;
};

