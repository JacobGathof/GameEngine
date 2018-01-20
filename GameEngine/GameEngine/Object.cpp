#include "Object.h"



Object::Object()
{
}


Object::~Object()
{
}

void Object::draw()
{
	for (Effect eff : effects) {
		eff.draw();
	}
}

bool Object::update(float delta_time)
{
	for (Effect eff : effects) {
		eff.update(delta_time);
	}
	return alive;
}

bool Object::collide(Object o)
{
	return false;
}
