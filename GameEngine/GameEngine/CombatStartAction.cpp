#include "CombatStartAction.h"
#include "GameState.h"
#include "BattleManager.h"
#include "Object.h"
#include "CollidableComponent.h"


CombatStartAction::CombatStartAction(Vector2f& pos)
{
	position = pos;
	obj = new Object(ObjectData{ "Lucidium Ring", Vector2f(128 - 64 * 3, 128 * 4), Vector2f(1,1), TextureType::TEXTURE_SLIME });
	obj->addComponent(new CollidableComponent());
}


CombatStartAction::~CombatStartAction()
{
	delete obj;
}

int CombatStartAction::run(float dt)
{
	
	if (timer == 0.0f) {
		hit = CircleHitbox(.5, Vector2f(0, 0));
		obj->pos = position;
		obj->getComponent<CollidableComponent>()->removeHitbox(0);
		obj->getComponent<CollidableComponent>()->addHitbox(&hit);
		obj->getComponent<CollidableComponent>()->weight = Weight::PLAYER;
		World::getInstance()->addObject(obj);
	}
	hit.shape.radius += circleGrowthRate * dt;

	timer += dt;
	if (timer < timeToWait) {
		return 0;
	}
	World::getInstance()->removeObject(obj);
	GameState::battleManager.startBattle();
	return 1;
}
