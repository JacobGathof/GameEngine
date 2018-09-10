#pragma once
#include "AI.h"
#include "Vector2f.h"
class Object;

enum EnemyState {
	ATTACK,
	NEUTRAL,
	DEFENSIVE,
	ALL_OR_NOTHING,
	RUN_AWAY,
	HEAL,
	REGEN,
};

enum EnemyType {
	RANGED,
	CAMP,
	MIXED,
	CONSERVATIVE,
	AGGRESSIVE,
	SUICIDE,
};

class EnemyCombatAI : public AI
{
public:
	EnemyCombatAI();
	~EnemyCombatAI();

	virtual bool execute(Object * obj, float dt);

	void updateValues(Object * obj);
	void determineState();
	void act(Object * obj, float dt);
	void configureParameters();

	void setPlayer(Object * obj);

private:
	Object * player;
	EnemyState enemyState = EnemyState::NEUTRAL;
	Vector2f randomDir;

	float playerHp = 0;
	float playerHpDt = 0;
	float playerLuc = 0;
	float playerStam = 0;

	float enemyHp = 0;
	float enemyHpDt = 0;
	float enemyLuc = 0;
	float enemyStam = 0;

	float dist = 0;
	Vector2f playerPos;
	Vector2f playerDir;

	float timer = 2;
	float nextUpdate = 1;
	

private: //Configuration variables
	EnemyType enemyType = EnemyType::CAMP;

	float minDistanceToRun = 0;
	float minHealthToHeal = 0;
	float staminaToAggressive = 0;
	float staminaToConserve = 0;
	float minHealthDtToRun = 0;
	float minHealthDtToAttack = 0;

};

