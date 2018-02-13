#include "Player.h"



Player::Player(TextureType t, Vector2f position, Vector2f sc, PlayerAI * ai) : LivingObject(t, position, sc, 100, 100)
{
	defaultAi = ai;
	moveSpeed = 600;
}


Player::~Player()
{
}

bool Player::update(float delta_time)
{
	lastX = pos[0];
	lastY = pos[1];
	LivingObject::update(delta_time);
	return true;
}

bool Player::collide(Object * o)
{
	pos[0] = lastX;
	pos[1] = lastY;
	return true;
}
