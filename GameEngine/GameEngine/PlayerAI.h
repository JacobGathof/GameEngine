#pragma once

#include "AI.h"
#include "Input.h"

class PlayerAI : public AI
{
public:
	PlayerAI();
	~PlayerAI();

	virtual bool execute(Object * obj);
};

