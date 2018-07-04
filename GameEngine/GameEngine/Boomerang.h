#pragma once
#include "Projectile.h"

class Boomerang : public Projectile
{
public:
	Boomerang(std::string& name, TextureType t, Vector2f& position, Vector2f& sc, Vector2f& dir, Object* owner);
	~Boomerang();

	virtual bool update(float dt);

protected:
	Vector2f velocity;
	Vector2f acceleration;
};

