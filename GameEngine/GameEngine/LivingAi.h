#pragma once
#include "Object.h"

class LivingObject;

class LivingAi
{
public:
	LivingAi();
	~LivingAi();

	virtual bool execute(LivingObject * obj, float dt);
};

