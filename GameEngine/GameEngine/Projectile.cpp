#include "Projectile.h"
#include "CircleHitbox.h"



Projectile::Projectile(ObjectData& data, Vector2f& dir, Object* obj) : InteractableObject(data)
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
	pos += direction*800*dt;
	if (lifeTimer.tick()) {
		destroy();
	}
	return InteractableObject::update(dt);
}

void Projectile::onEnterTrigger()
{
	if (triggerSubject != owner) {
		//destroy();
		//Replace with arrow sprite object, for (fake) visual effect, tied to target's location
	}
}
