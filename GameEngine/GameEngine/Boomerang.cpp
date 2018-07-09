#include "Boomerang.h"



Boomerang::Boomerang(std::string & name, TextureType t, Vector2f & position, Vector2f & sc, Vector2f & dir, Object * owner) :
	Projectile(name, t, position, sc, dir, owner)
{
	lifeTimer.setTickLength(2.0f);
}

Boomerang::~Boomerang()
{
}

void Boomerang::setPoints(Vector2f v1, Vector2f v2, Vector2f v3, Vector2f v4)
{
	path = BezierSpline(v1, v2, v3, v4);
}

bool Boomerang::update(float dt)
{

	path.p4 = owner->pos;

	lifeTimer.update(dt);
	float time = lifeTimer.getTotalTime() / 2.0f;

	pos = path.positionAt(time);

	if (lifeTimer.tick()) {
		destroy();
	}
	return InteractableObject::update(dt);
}

void Boomerang::onEnterTrigger()
{
	if (triggerSubject == owner && thrown) {
		destroy();
	}
}

void Boomerang::onExitTrigger()
{
	if (triggerSubject == owner) {
		thrown = true;
	}
}
