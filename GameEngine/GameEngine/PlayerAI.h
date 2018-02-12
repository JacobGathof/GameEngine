#pragma once

#include "LivingAi.h"
#include "LivingObject.h"
#include "World.h"


enum class KeyMap {
	KEY_UP,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_LEFT,
	KEY_INTERACT,
	KEY_SKILL_1,
	KEY_SKILL_2,
	KEY_SKILL_3,
	KEY_SKILL_4,
	KEY_SKILL_5
};

class PlayerAI : public LivingAi
{
public:
	PlayerAI();
	~PlayerAI();

	LivingObject * user;

	virtual bool execute(LivingObject * obj, float dt);
	void receiveInput(KeyMap key, int state);

private:
	float xVel;
	float yVel;
};

