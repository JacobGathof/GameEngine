#include "CollidableObject.h"
#include "CircleHitbox.h"


CollidableObject::CollidableObject(ObjectData& data) : Object(data)
{
	auto c = Circle(Vector2f(0, 0), 32);
	c.color = Color::Red;
	addHitbox(new CircleHitbox(c, Vector2f(0,0)));

}


CollidableObject::~CollidableObject()
{
	for (auto hit : hitboxes) {
		delete hit;
	}
	
}


void CollidableObject::updateHitbox()
{
	for (Hitbox * hit : hitboxes) {
		hit->updatePos(pos);
	}
}


bool CollidableObject::collide(Object * o, Hitbox * h)
{
	return false;
}

bool CollidableObject::collide(CollidableObject * obj)
{
	return false;
}

void CollidableObject::drawHitboxes()
{
	for (Hitbox * h : hitboxes) {
		h->draw();
	}
}

bool CollidableObject::update(float dt)
{
	updateHitbox();
	return Object::update(dt);
}


int CollidableObject::numHitboxes()
{
	return hitboxes.size();
}

void CollidableObject::addHitbox(Hitbox * h)
{
	hitboxes.add(h);
}

Hitbox * CollidableObject::getHitbox(int i)
{
	return hitboxes.get(i);
}


