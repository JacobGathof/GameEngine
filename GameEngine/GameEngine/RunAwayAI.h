#pragma once

#include "AI.h"


class RunAwayAI : public AI
{
public:
	RunAwayAI(Object * object);
	~RunAwayAI();

	virtual bool execute(Object * obj, float dt);

private:
	Object * object;
	bool moving = false;

};

