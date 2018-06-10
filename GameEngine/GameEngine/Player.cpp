#include "Player.h"



Player::Player(std::string& name, TextureType t, Vector2f& position, Vector2f& sc, PlayerAI * ai) : LivingObject(name, t, position, sc, 100, 100)
{
	defaultAI = ai;
	moveSpeed = 256;
	weight = Weight::PLAYER;
}


Player::~Player()
{
}

bool Player::update(float delta_time)
{
	if (colliding) {
		return true;
	}
	lastX = pos[0];
	lastY = pos[1];
	LivingObject::update(delta_time);
	return true;
}

bool Player::collide(Object * o, Hitbox * h)
{
	//colliding = CollisionUtil::unequalResolve(this, h, 5);
	

	return true;
}
