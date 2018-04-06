#pragma once

#include "LivingAi.h"

class LivingObject;

class RunAwayAI : public LivingAi
{
public:
	RunAwayAI(LivingObject * object);
	~RunAwayAI();

	virtual bool execute(LivingObject * obj, float dt);

private:
	LivingObject * object;
	bool moving = false;

};

