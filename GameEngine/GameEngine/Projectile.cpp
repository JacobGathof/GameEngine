#include "Projectile.h"




Projectile::Projectile(std::string & name, TextureType t, Vector2f & position, Vector2f & sc) : 
	AnimatedObject(name, t, position, sc)
{
	lifeTimer.setTickLength(2.0f);
}

Projectile::~Projectile()
{
}

bool Projectile::update(float dt)
{
	lifeTimer.update(dt);
	pos += Vector2f(0, -300)*dt;
	if (lifeTimer.tick()) {
		destroy();
	}
	return AnimatedObject::update(dt);
}
