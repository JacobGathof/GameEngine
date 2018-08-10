#include "Player.h"

#include "BattleManager.h"
#include "PlayerAI.h"


Player::Player(ObjectData& data, PlayerAI * ai) : LivingObject(data)
{
	defaultAI = ai;
	moveSpeed = 256;
	weight = Weight::PLAYER;
	interactionRadius->radius = 64;
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

bool Player::executeAI(float dt, AI * ai)
{
	return ai->execute(this, dt);
}
