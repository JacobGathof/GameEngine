#pragma once

#include "LivingAi.h"

class LivingObject;

class RunAwayAI : public LivingAi
{
public:
	RunAwayAI(LivingObject * object);
	~RunAwayAI();

	LivingObject * object;

	virtual bool execute(LivingObject * obj, float dt);

};

