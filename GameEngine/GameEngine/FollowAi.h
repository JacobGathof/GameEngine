#pragma once

#include "LivingAi.h"



class FollowAI : public LivingAi
{
public:
	FollowAI(LivingObject * obj);
	~FollowAI();


	virtual bool execute(LivingObject * obj, float dt);

private:
	LivingObject * follow;
	bool moving = false;
};

