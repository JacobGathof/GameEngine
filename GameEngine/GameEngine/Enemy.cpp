#include "Enemy.h"



Enemy::Enemy(std::string name, TextureType t, Vector2f position, Vector2f sc, int hp, int luc) 
	: LivingObject(name, t, position, sc, hp, luc)
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
