#pragma once

#include "LivingAi.h"



class FollowAI : public LivingAi
{
public:
	FollowAI(LivingObject * obj);
	~FollowAI();

	LivingObject * follow;
	bool moving = false;

	virtual bool execute(LivingObject * obj, float dt);
};

