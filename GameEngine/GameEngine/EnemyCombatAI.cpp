#include "EnemyCombatAI.h"
#include "Object.h"


EnemyCombatAI::EnemyCombatAI()
{
	configureParameters();
}


EnemyCombatAI::~EnemyCombatAI()
{
}

bool EnemyCombatAI::execute(Object * obj, float dt)
{
	playerPos = player->pos;
	float dx = player->pos[0] - obj->pos[0];
	float dy = player->pos[1] - obj->pos[1];
	playerDir = Vector2f(dx, dy).normalize();
	dist = player->pos.distanceTo(obj->pos);
	if (timer > nextUpdate) {
		updateValues(obj);
		determineState();
		timer = 0;
		float randX = (float)rand() / RAND_MAX;
		float randY = (float)rand() / RAND_MAX;
		randomDir = Vector2f(2*randX - 1, 2 * randY - 1);
	}
	timer += dt;
	
	act(obj, dt);
	/*
	float dx = player->pos[0] - obj->pos[0];
	float dy = player->pos[1] - obj->pos[1];
	Vector2f dir = Vector2f(dx, dy).normalize();
	Vector2f odir = Vector2f(((int)(dir[0] * 2.0f) / 2.0f), ((int)(dir[1] * 2.0f) / 2.0f));

	obj->pos += odir.normalize() * dt * 10;
	*/
	return false;
}

void EnemyCombatAI::updateValues(Object * obj)
{
	if (playerHp != 0) {
		playerHpDt = player->health - playerHp;
	}
	playerHp = player->health;
	playerLuc = player->lucidium;
	playerStam = player->stamina;

	if (enemyHp != 0) {
		enemyHpDt = obj->health - enemyHp;
	}
	enemyHp = obj->health;
	enemyLuc = obj->lucidium;
	enemyStam = obj->stamina;

	
}

void EnemyCombatAI::determineState()
{

	if (dist >= minDistanceToRun) {
		if (playerStam < staminaToAggressive && !(enemyState == EnemyState::HEAL || enemyState == EnemyState::REGEN)) {
			if (enemyType == EnemyType::AGGRESSIVE || enemyType == EnemyType::SUICIDE) {
				enemyState = EnemyState::ALL_OR_NOTHING;
			}
			else {
				enemyState = EnemyState::ATTACK;
			}
		}
		else if (enemyHp < minHealthToHeal) {
			enemyState = EnemyState::HEAL;
		}
		else if (enemyHpDt < minHealthDtToRun) {
			enemyState = EnemyState::RUN_AWAY;
			if (minHealthDtToAttack > playerHpDt && (enemyType == EnemyType::AGGRESSIVE || enemyType == EnemyType::SUICIDE || enemyState == EnemyType::MIXED)) {
				enemyState = EnemyState::ATTACK;
			}
		}
		else if (enemyStam < staminaToConserve) {
			enemyState = EnemyState::REGEN;
		}
		else if (enemyType == EnemyType::SUICIDE) {
			enemyState = EnemyState::ALL_OR_NOTHING;
		}
		else {
			enemyState = EnemyState::NEUTRAL;
		}
	}
	else {
		enemyState = EnemyState::RUN_AWAY;
	}
	
}

void EnemyCombatAI::act(Object * obj, float dt)
{
	switch (enemyState) {
	case EnemyState::RUN_AWAY:
		//Change to enemy Speed
		obj->pos -= playerDir * 100 * dt;
		break;
	case EnemyState::ATTACK:
		obj->pos += playerDir * 100 * dt;
		break;
	case EnemyState::ALL_OR_NOTHING:
		obj->pos += playerDir * 100 * dt;
		break;
	case EnemyState::HEAL:
		obj->pos -= playerDir * 100 * dt;
		obj->health += 1;
		std::cout << "Healing " << obj->health;
		break;
	case EnemyState::DEFENSIVE:
		break;
	case EnemyState::NEUTRAL:
		obj->pos += randomDir * 100 * dt;
		break;
	}
}

void EnemyCombatAI::configureParameters()
{
	if (enemyType == EnemyType::CAMP) {
		minDistanceToRun = 600;
		minHealthToHeal = 40;
		staminaToAggressive = 10;
		staminaToConserve = 30;
		minHealthDtToRun = -5;
		minHealthDtToAttack = -15;
	}
}

void EnemyCombatAI::setPlayer(Object * obj)
{
	player = obj;
}
