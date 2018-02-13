#pragma once

#include "LivingAi.h"



class FollowAi : public LivingAi
{
public:
	FollowAi(LivingObject * obj);
	~FollowAi();

	LivingObject * follow;

	virtual bool execute(LivingObject * obj, float dt);
};

