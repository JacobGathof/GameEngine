#include "PlayerCombatAI.h"
#include "Keyboard.h"

PlayerCombatAI::PlayerCombatAI() : PlayerAI()
{
}

PlayerCombatAI::~PlayerCombatAI()
{
}

bool PlayerCombatAI::execute(LivingObject * obj, float dt)
{
	PlayerAI::execute(obj, dt);
	return false;
}

void PlayerCombatAI::receiveInput(Keyboard & keyboard)
{
	PlayerAI::receiveInput(keyboard);

	if (keyboard.press(VirtualKey::DODGE)) {
		Vector2f pos = Vector2f(xVel, yVel).normalize() * rollDistance;
		user->setAI(new GoToPointAI(user->pos + pos, rollSpeed));
	}

	if (keyboard.press(VirtualKey::SKILL_1)) {
		std::cout << "Using Card 1" << std::endl;
	}

	if (keyboard.press(VirtualKey::SKILL_2)) {
		std::cout << "Using Card 2" << std::endl;
	}

	if (keyboard.press(VirtualKey::SKILL_3)) {
		std::cout << "Using Card 3" << std::endl;
	}

	if (keyboard.press(VirtualKey::SKILL_4)) {
		std::cout << "Using Card 4" << std::endl;
	}

	if (keyboard.press(VirtualKey::SKILL_5)) {
		std::cout << "Using Card 5" << std::endl;
	}
}

void PlayerCombatAI::processInteractKey()
{
	std::cout << "In the combat Interact Key handler" << std::endl;
}
