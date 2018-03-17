#include "LivingObject.h"


LivingObject::LivingObject(std::string name, TextureType t, Vector2f position, Vector2f sc, int hp, int luc) : MovableObject(name, t,position, sc)
{
}

LivingObject::~LivingObject()
{
}

bool LivingObject::update(float delta_time)
{
	if (stalled) {
		return false;
	}
	if (aiQueue.size() == 0) {
		if (defaultAI != nullptr) {
			defaultAI->execute(this, delta_time);
		}
	}
	else {
		if (aiQueue.get(0)->execute(this, delta_time)) {
			aiQueue.removeIndex(0);
		}
	}
	return MovableObject::update(delta_time);
}

bool LivingObject::collide(Object * o)
{
	return false;
}

bool LivingObject::activateCard(int i)
{
	return false;
}
