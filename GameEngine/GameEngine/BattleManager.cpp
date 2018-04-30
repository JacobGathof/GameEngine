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
	room = World::getInstance()->currentRoom;
	pos = player->pos;
	enemy = enemyObj;
	enemy->persistent = true;
	std::cout << "Getting Room" << std::endl;
	Room * room = World::getInstance()->getRoom(std::string("Room 2"));
	if (room == nullptr) {
		std::cout << "Null Pointer" << std::endl;
	}
	World::getInstance()->transition(room);
	std::cout << "Got Room" << std::endl;

	player->pos = playerPos;
	enemyObj ->pos = enemyPos;

	Vector2f playerDir = player->pos - enemy->pos;
	playerDir = playerDir.normalize() * startingDashBackLength;

	enemy->setAI(new GoToPointAI(enemy->pos - playerDir, startingDashBackSpeed));
	player->setAI(new GoToPointAI(player->pos + playerDir, startingDashBackSpeed));
	playerAI = player->defaultAI;
	ai = new PlayerCombatAI();
	player->defaultAI = ai;
	Input::ai = ai;
	battleState = BATTLESTARTED;
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
