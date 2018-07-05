#include "Projectile.h"
#include "CircleHitbox.h"



Projectile::Projectile(std::string & name, TextureType t, Vector2f & position, Vector2f & sc, Vector2f& dir, Object* obj) : 
	InteractableObject(name, t, position, sc)
{
	lifeTimer.setTickLength(2.0f);
	direction = dir;
	rotation = atan2(dir[1], dir[0]) - 3.14159f/4;
	owner = obj;

	//this->addHitbox(new CircleHitbox(Circle(Vector2f(0,0), 32), Vector2f(0, 0)));
}

Projectile::~Projectile()
{
}

bool Projectile::update(float dt)
{
	lifeTimer.update(dt);
	pos += direction*1600*dt;
	if (lifeTimer.tick()) {
		destroy();
	}
	return InteractableObject::update(dt);
}

void Projectile::onEnterTrigger()
{
	if (triggerSubject != owner) {
		//destroy();
	}
}
