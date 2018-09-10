#include "CircleHitbox.h"



CircleHitbox::CircleHitbox(float f, Vector2f& off)
{
	shape = Circle(Vector2f(0,0), f);
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

void CircleHitbox::updatePos(Vector2f& p)
{
	Hitbox::updatePos(p);
	shape.center = pos;
}

void CircleHitbox::draw()
{
	shape.draw();
}

Shape * CircleHitbox::getShape()
{
	return &shape;
}
