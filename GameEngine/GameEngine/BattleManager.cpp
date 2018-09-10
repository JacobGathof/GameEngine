#include "BattleManager.h"

#include "Player.h"
#include "PlayerCombatAI.h"
#include "Room.h"
#include "World.h"
#include "AIComponent.h"
#include "EnemyCombatAI.h"
#include "BattleTransitionAction.h"
#include "CollidableComponent.h"

BattleManager::BattleManager(Player * play)
{
	player = play;
	battleState = NOBATTLE;
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

	//player->update(dt);
	//enemy->update(dt);

	return true;
}

void BattleManager::transitionBattle(Object * enemyObj)
{
	if (battleState == BATTLESTARTED) {
		return;
	}
	if (!enemyObj->hasTrait<AIComponent>()) {
		return;
	}
	pos = player->pos;
	player->persistent = true;

	enemy = enemyObj;
	enemy->persistent = true;
	battleState = BATTLESTARTED;
	
	enemy->getComponent<CollidableComponent>()->weight = Weight::GHOST;
	player->getComponent<CollidableComponent>()->weight = Weight::GHOST;

	BattleTransitionAction act(player->pos);
	act.run(0);

}

void BattleManager::startBattle()
{
	enemy->getComponent<CollidableComponent>()->weight = Weight::LIGHT;
	player->getComponent<CollidableComponent>()->weight = Weight::PLAYER;


	Vector2f playerDir = player->pos - enemy->pos;
	playerDir = playerDir.normalize() * startingDashBackLength;

	
	EnemyCombatAI * enemyAi = new EnemyCombatAI();
	enemyAi->setPlayer(player);
	enemy->getComponent<AIComponent>()->addAI(enemyAi);
	enemy->getComponent<AIComponent>()->addAI(new GoToPointAI(enemy->pos - playerDir, startingDashBackSpeed));
	player->getComponent<AIComponent>()->addAI(new GoToPointAI(player->pos + playerDir, startingDashBackSpeed));
	if (player->hasTrait<AIComponent>()) {
		playerAI = player->getComponent<AIComponent>()->defaultAI;
		ai = new PlayerCombatAI();
		ai->enemy = enemy;
		player->getComponent<AIComponent>()->defaultAI = ai;
	}
	
	Input::ai = ai;
	//battleState = BATTLESTARTED;

	//enemy->shuffle();
	//enemy->drawCards(5);

	//player->shuffle();
	//player->drawCards(5);
}

void BattleManager::endBattle()
{
	battleState = NOBATTLE;
	if (player->hasTrait<AIComponent>()) {
		player->getComponent<AIComponent>()->defaultAI = playerAI;
		Input::ai = (PlayerAI *)player->getComponent<AIComponent>()->defaultAI;
	}

	World::getInstance()->setCurrentRoom(room);
	player->pos = pos;
	enemy->persistent = false;

	delete ai;
}

void BattleManager::draw()
{
}
