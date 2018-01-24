#pragma once

#include "Object.h"

class LivingAi
{
public:
	LivingAi();
	~LivingAi();

	virtual bool execute(void * obj);
};

