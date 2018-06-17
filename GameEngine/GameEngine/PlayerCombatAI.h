#pragma once


#include "GoToPointAI.h"
#include "PlayerAI.h"

class Keyboard;

class PlayerCombatAI : public PlayerAI
{
public:
	PlayerCombatAI();
	~PlayerCombatAI();

	LivingObject * enemy;

	virtual bool execute(Player * obj, float dt);
	virtual void receiveInput(Keyboard& keyboard);

protected:

	virtual void processInteractKey();

private:
	float rollDistance = 300;
	float rollSpeed = 1400;
	float attackRange = 300;

	bool skillBuffer = false;
	bool meleeAttacking = false;
};

