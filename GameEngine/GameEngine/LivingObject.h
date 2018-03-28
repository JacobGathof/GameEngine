#pragma once

#include "MovableObject.h"
#include "LivingAi.h"
#include "List.h"

class LivingObject : public MovableObject
{
public:
	LivingObject(std::string name, TextureType t, Vector2f position, Vector2f sc, int hp, int luc);
	~LivingObject();

	int health;
	int lucidium;

	virtual bool update(float delta_time);
	virtual bool collide(Object * o, Hitbox * h);
	virtual bool activateCard(int i);

protected:

};


