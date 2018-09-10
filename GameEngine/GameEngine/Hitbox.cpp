#include "Hitbox.h"

#include "CircleHitbox.h"
#include "RectHitbox.h"
#include "ComplexHitbox.h"

Hitbox::Hitbox()
{
}


Hitbox::~Hitbox()
{
}

Vector2f Hitbox::getPos()
{
	return pos;
}

void Hitbox::updatePos(Vector2f& p)
{
	pos = p + offset;
}

bool Hitbox::collide(Hitbox * s)
{
	return false;
}

bool Hitbox::collide(CircleHitbox * h)
{
	return false;
}

bool Hitbox::collide(RectHitbox * h)
{
	return false;
}

bool Hitbox::collide(ComplexHitbox * h)
{
	return false;
}

void Hitbox::draw()
{
}

Shape * Hitbox::getShape()
{
	return nullptr;
}
