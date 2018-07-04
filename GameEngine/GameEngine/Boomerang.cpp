#include "Boomerang.h"



Boomerang::Boomerang(std::string & name, TextureType t, Vector2f & position, Vector2f & sc, Vector2f & dir, Object * owner) :
	Projectile(name, t, position, sc, dir, owner)
{
	velocity = direction * 800;
	acceleration = Vector2f(0, 0);
}

Boomerang::~Boomerang()
{
}

bool Boomerang::update(float dt)
{
	lifeTimer.update(dt);
	float time = lifeTimer.getTotalTime();

	Vector2f d = owner->pos - pos;

	acceleration = d.normalize() * d.length() * time * 1 - velocity;

	velocity += dt * acceleration;
	pos += dt * velocity;

	if (lifeTimer.tick()) {
		//destroy();
	}
	return InteractableObject::update(dt);
}
