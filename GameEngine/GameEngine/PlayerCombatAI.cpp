#include "PlayerCombatAI.h"
#include "Keyboard.h"
#include "Player.h"
#include "AIComponent.h"

PlayerCombatAI::PlayerCombatAI() : PlayerAI()
{
	staminaGainTimer.setTickLength(1.0f);
}

PlayerCombatAI::~PlayerCombatAI()
{
}

bool PlayerCombatAI::execute(Object * obj, float dt)
{
	PlayerAI::execute(obj, dt);

	staminaGainTimer.update(dt);
	if (staminaGainTimer.tick()) {
		
		obj->stamina += min(5, obj->maxStamina - obj->stamina);
		
		staminaGainTimer.reset();
	}

	if (meleeAttacking) {
		meleeAttacking = false;
		if (obj->stamina < 10) {
			return false;
		}
		Vector2f enemyDir = obj->pos - enemy->pos;
		enemyDir = enemyDir.normalize();
		obj->stamina -= 10;
		//std::cout << enemyDir.dot(obj->forward) << std::endl;
		
		if (obj->pos.distanceTo(enemy->pos) < attackRange && enemyDir.dot(obj->forward) < -1 + (3.1415f/8)) {
			GoToPointAI * gtp = new GoToPointAI(enemy->pos - enemyDir * 100, 400);
			enemy->getComponent<AIComponent>()->addAI(gtp);
			enemy->health -= 10;
			
			std::cout << "Enemy Health: " << enemy->health << std::endl;
			std::cout << "Player Stamina: " << obj->stamina << std::endl;
		}
	}
	return false;
}

void PlayerCombatAI::receiveInput(Keyboard & keyboard, Mouse& mouse)
{
	PlayerAI::receiveInput(keyboard, mouse);

	if (keyboard.press(VirtualKey::DODGE)) {
		Vector2f pos = Vector2f(xVel, yVel).normalize() * rollDistance;
		user->getComponent<AIComponent>()->addAI(new GoToPointAI(user->pos + pos, rollSpeed));
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
