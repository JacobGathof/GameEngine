#pragma once

#include "LivingAi.h"

class LivingObject;

class RunAwayAI : public LivingAi
{
public:
	RunAwayAI(LivingObject * object);
	~RunAwayAI();

	LivingObject * object;
	bool moving = false;

	virtual bool execute(LivingObject * obj, float dt);

};

