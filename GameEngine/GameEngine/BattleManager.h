#pragma once

#define BATTLESTARTED 1
#define NOBATTLE 0

#include "Input.h"
#include "GoToPointAI.h"


class LivingObject;
class Player;
class PlayerCombatAI;
class Room;

class BattleManager
{
public:
	BattleManager(Player * play);
	BattleManager();
	~BattleManager();

	Player * player;
	LivingObject * enemy;
	int battleState = NOBATTLE;

	bool update(float dt);
	void startBattle(LivingObject * enemy);
	void endBattle();
	void draw();

private:
	//Consider Adding a weight factor to this
	float startingDashBackLength = 500;
	float startingDashBackSpeed = 1000;
	
	Vector2f enemyPos = Vector2f(100.0f, 200.0f);
	Vector2f playerPos = Vector2f(100.0f, -200.0f);

	//Storing the position and room variables
	Vector2f pos;
	Room * room;


	PlayerCombatAI * ai;
	AI * playerAI;

};

