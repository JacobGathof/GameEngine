#pragma once


#include "GoToPointAI.h"
#include "PlayerAI.h"
#include "Timer.h"

class Keyboard;

class PlayerCombatAI : public PlayerAI
{
public:
	PlayerCombatAI();
	~PlayerCombatAI();

	Object * enemy;

	virtual bool execute(Object * obj, float dt);
	virtual void receiveInput(Keyboard& keyboard, Mouse& mouse);

protected:

	virtual void processInteractKey();

private:
	float rollDistance = 300;
	float rollSpeed = 1400;
	float attackRange = 300;

	bool skillBuffer = false;
	bool meleeAttacking = false;

	Timer staminaGainTimer;
};

