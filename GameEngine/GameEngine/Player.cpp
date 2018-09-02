#include "Player.h"

#include "BattleManager.h"


Player::Player(ObjectData& data) : Object(data)
{

	//defaultAI = ai;
	//moveSpeed = 256;
	//weight = Weight::PLAYER;
	//interactionRadius->radius = 64;
}


Player::~Player()
{
}


bool Player::update(float delta_time)
{
	lastX = pos[0];
	lastY = pos[1];
	Object::update(delta_time);
	return true;
}

bool Player::collide(Object * o, Hitbox * h)
{
	//colliding = CollisionUtil::unequalResolve(this, h, 5);
	

	return true;
}

