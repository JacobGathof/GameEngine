#include "Enemy.h"



Enemy::Enemy(ObjectData& data) : LivingObject(data)
{
}


Enemy::~Enemy()
{
}

bool Enemy::collide(Object * o, Hitbox * h)
{
	
	GameState::battleManager.startBattle(this);
	
	return false;
}
