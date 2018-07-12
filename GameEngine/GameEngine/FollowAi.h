#pragma once

#include "AI.h"



class FollowAI : public AI
{
public:
	FollowAI(Object * obj);
	~FollowAI();


	virtual bool execute(Object * obj, float dt);

private:
	Object * follow;
	bool moving = false;
};

