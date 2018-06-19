#include "Projectile.h"




Projectile::Projectile(std::string & name, TextureType t, Vector2f & position, Vector2f & sc, Vector2f& dir) : 
	AnimatedObject(name, t, position, sc)
{
	lifeTimer.setTickLength(8.0f);
	direction = dir;
	rotation = atan2(dir[1], dir[0]) - 3.14159f/2;
}

Projectile::~Projectile()
{
}

bool Projectile::update(float dt)
{
	lifeTimer.update(dt);
	pos += direction*400*dt;
	if (lifeTimer.tick()) {
		destroy();
	}
	return AnimatedObject::update(dt);
}
