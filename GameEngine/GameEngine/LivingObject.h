#pragma once

#include "MovableObject.h"
#include "LivingAi.h"

class LivingObject : public MovableObject
{
public:
	LivingObject(TextureType t, Vector2f position, Vector2f sc, int hp, int luc);
	~LivingObject();

	int health;
	int lucidium;

	virtual void setAI(LivingAi * a);
	virtual bool update(float delta_time);
	virtual bool collide(Object * o);

protected:
	std::vector<LivingAi *> aiQueue;
	LivingAi * defaultAi;
};


