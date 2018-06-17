#include "Enemy.h"



Enemy::Enemy(std::string name, TextureType t, Vector2f position, Vector2f sc) 
	: LivingObject(name, t, position, sc)
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
