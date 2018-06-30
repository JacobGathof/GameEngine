#include "BattleManager.h"

#include "LivingObject.h"
#include "Player.h"
#include "PlayerCombatAI.h"
#include "Room.h"
#include "World.h"

BattleManager::BattleManager(Player * play)
{
	player = play;
}

BattleManager::BattleManager()
{
}

BattleManager::~BattleManager()
{
}


bool BattleManager::update(float dt)
{
	if (battleState == NOBATTLE) {
		return false;
	}
	
	player->update(dt);
	enemy->update(dt);

	return true;
}

void BattleManager::startBattle(LivingObject * enemyObj)
{
	if (battleState == BATTLESTARTED) {
		return;
	}
	room = World::getInstance()->getCurrentRoom();
	pos = player->pos;
	enemy = enemyObj;
	enemy->persistent = true;
	Room * room = World::getInstance()->getRoom(World::RoomNames::CLEARING);
	
	World::getInstance()->transition(room);

	player->pos = playerPos;
	enemyObj ->pos = enemyPos;

	Vector2f playerDir = player->pos - enemy->pos;
	playerDir = playerDir.normalize() * startingDashBackLength;

	enemy->addAI(new GoToPointAI(enemy->pos - playerDir, startingDashBackSpeed));
	player->addAI(new GoToPointAI(player->pos + playerDir, startingDashBackSpeed));
	playerAI = player->defaultAI;
	ai = new PlayerCombatAI();
	ai->enemy = enemy;
	player->defaultAI = ai;
	Input::ai = ai;
	battleState = BATTLESTARTED;

	//enemy->shuffle();
	//enemy->drawCards(5);

	//player->shuffle();
	//player->drawCards(5);
}

void BattleManager::endBattle()
{
	battleState = NOBATTLE;
	player->defaultAI = playerAI;
	Input::ai = (PlayerAI *)player->defaultAI;

	World::getInstance()->setCurrentRoom(room);
	player->pos = pos;
	enemy->persistent = false;

	delete ai;
}

void BattleManager::draw()
{
}
