#include "Player.h"



Player::Player(TextureType t, Vector2f position, Vector2f sc) : MovableObject(t, position, sc)
{
	//I don't like this.  Need to ask Jake

	//texture = t;
	//pos = position;
	//scale = sc;
}

Player::Player()
{
}


Player::~Player()
{
}

bool Player::update(float delta_time)
{
	return false;
}