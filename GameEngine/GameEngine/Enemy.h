#pragma once

#include "LivingObject.h"
#include "GameState.h"
#include "BattleManager.h"

class Enemy : public LivingObject
{
public:
	Enemy(std::string name, TextureType t, Vector2f position, Vector2f sc);
	~Enemy();

	virtual bool collide(Object * o, Hitbox * h);
};

