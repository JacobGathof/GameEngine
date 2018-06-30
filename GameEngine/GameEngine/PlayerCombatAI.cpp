#include "PlayerCombatAI.h"
#include "Keyboard.h"
#include "Player.h"

PlayerCombatAI::PlayerCombatAI() : PlayerAI()
{
}

PlayerCombatAI::~PlayerCombatAI()
{
}

bool PlayerCombatAI::execute(Player * obj, float dt)
{
	PlayerAI::execute(obj, dt);
	if (meleeAttacking) {
		meleeAttacking = false;
		Vector2f enemyDir = obj->pos - enemy->pos;
		enemyDir = enemyDir.normalize();
		
		//std::cout << enemyDir.dot(obj->forward) << std::endl;
		/*
		if (obj->pos.distanceTo(enemy->pos) < attackRange && enemyDir.dot(obj->forward) < -1 + (3.1415f/8)) {
			GoToPointAI * gtp = new GoToPointAI(enemy->pos - enemyDir * 100, 400);
			enemy->setAI(gtp);
			enemy->takeDamage(10);
		}*/
	}
	return false;
}

void PlayerCombatAI::receiveInput(Keyboard & keyboard, Mouse& mouse)
{
	PlayerAI::receiveInput(keyboard, mouse);

	if (keyboard.press(VirtualKey::DODGE)) {
		Vector2f pos = Vector2f(xVel, yVel).normalize() * rollDistance;
		user->addAI(new GoToPointAI(user->pos + pos, rollSpeed));
	}
	
	if (keyboard.press(VirtualKey::SKILL_1)) {
		if (!skillBuffer) {
			//user->activateCard(0);
			skillBuffer = true;
		}	
	}
	else if (keyboard.press(VirtualKey::SKILL_2)) {
		if (!skillBuffer) {
			//user->activateCard(1);
			skillBuffer = true;
		}
	}
	else if (keyboard.press(VirtualKey::SKILL_3)) {
		if (!skillBuffer) {
			//user->activateCard(2);
			skillBuffer = true;
		}
	}
	else if (keyboard.press(VirtualKey::SKILL_4)) {
		if (!skillBuffer) {
			//user->activateCard(3);
			skillBuffer = true;
		}
	}
	else if (keyboard.press(VirtualKey::SKILL_5)) {
		if (!skillBuffer) {
			//user->activateCard(4);
			skillBuffer = true;
		}
	}
	else {
		skillBuffer = false;
	}
}

void PlayerCombatAI::processInteractKey()
{
	std::cout << "Attack" << std::endl;

	meleeAttacking = true;
}
