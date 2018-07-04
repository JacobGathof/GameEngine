#pragma once
#include "InteractableObject.h"

class Projectile : public InteractableObject
{
public:
	Projectile(std::string& name, TextureType t, Vector2f& position, Vector2f& sc, Vector2f& dir, Object* owner);
	virtual ~Projectile();

	virtual bool update(float dt);
	virtual void onEnterTrigger();

protected:
	Timer lifeTimer;
	Vector2f direction;
	Object* owner;

};

