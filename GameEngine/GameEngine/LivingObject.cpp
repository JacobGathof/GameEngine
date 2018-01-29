#include "LivingObject.h"


LivingObject::LivingObject(TextureType t, Vector2f position, Vector2f sc, int hp, int luc) : MovableObject(t,position, sc)
{
}

LivingObject::~LivingObject()
{
}

void LivingObject::setAI(LivingAi * a)
{
	if (aiQueue.size() == 0 && defaultAI == nullptr) {
		defaultAi = a;
	}
	else {
		aiQueue.add(defaultAi);
	}
}

bool LivingObject::update(float delta_time)
{
	if (aiQueue.size() == 0) {
		defaultAi->execute(this);
	}
	else {
		if (!aiQueue.get(0)->execute(this)) {
			aiQueue.remove(0);
		}
	}
	return false;
}

bool LivingObject::collide(Object * o)
{
	return false;
}

bool LivingObject::activateCard(int i)
{
	return false;
}
