#include "DamageTag.h"



DamageTag::DamageTag() : Tag(std::string("DMG"), Vector2f(0, 100))
{
	timer.setTickLength(1.0f);
}


DamageTag::~DamageTag()
{
}

bool DamageTag::update(float dt)
{
	timer.update(dt);
	Tag::update(dt);
	offset += Vector2f(0, 200*dt);
	return !timer.tick();
}
