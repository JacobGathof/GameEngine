#pragma once
#include "AnimatedObject.h"

class Projectile : public AnimatedObject
{
public:
	Projectile(std::string& name, TextureType t, Vector2f& position, Vector2f& sc);
	virtual ~Projectile();

	virtual bool update(float dt);

private:
	Timer lifeTimer;

};

