#pragma once

#include "LivingObject.h"
#include "GameState.h"
#include "BattleManager.h"

class Enemy : public LivingObject
{
public:
	Enemy(ObjectData& data);
	~Enemy();

	virtual bool collide(Object * o, Hitbox * h);
};

