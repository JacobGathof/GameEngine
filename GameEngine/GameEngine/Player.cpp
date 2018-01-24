#include "Player.h"



Player::Player(TextureType t, Vector2f position, Vector2f sc, PlayerAI * ai) : LivingObject(t, position, sc, 100, 100)
{
	defaultAi = ai;
}


Player::~Player()
{
}

bool Player::update(float delta_time)
{
	defaultAi->execute(this);
	return true;
}

bool Player::collide(Object * o)
{
	return false;
}
