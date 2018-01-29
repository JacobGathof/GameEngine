#pragma once

#include "MovableObject.h"
#include "LivingAi.h"
#include "List.h"

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
	virtual bool activateCard(int i);

protected:
	List<LivingAi *> aiQueue;
	LivingAi * defaultAi;
};


