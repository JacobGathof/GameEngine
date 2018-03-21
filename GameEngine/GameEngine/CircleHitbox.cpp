#include "CircleHitbox.h"



CircleHitbox::CircleHitbox(Circle c, Vector2f off)
{
	shape = c;
	offset = off;
}

CircleHitbox::~CircleHitbox()
{
}

bool CircleHitbox::collide(Hitbox * s)
{
	this->shape.center = pos;
	return s->collide(this);
}

bool CircleHitbox::collide(CircleHitbox * h)
{
	this->shape.center = pos;
	return CollisionUtil::collide(*h, *this);
}

bool CircleHitbox::collide(RectHitbox * h)
{
	this->shape.center = pos;
	return CollisionUtil::collide(*this, *h);
}

bool CircleHitbox::collide(ComplexHitbox * h)
{
	this->shape.center = pos;
	return CollisionUtil::collide(*this, *h);
}

void CircleHitbox::draw()
{
	shape.center = pos;
	shape.draw();
}
