#include "Player.h"



Player::Player(TextureType t, Vector2f position, Vector2f sc, PlayerAI * ai) : MovableObject(t, position, sc)
{
	defaultAI = ai;
}

Player::Player()
{
}


Player::~Player()
{
}

bool Player::update(float delta_time)
{
	defaultAI->execute(this);
	return true;
}