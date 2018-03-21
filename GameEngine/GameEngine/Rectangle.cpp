#include "Rectangle.h"



Rect::Rect()
{
}


Rect::Rect(Vector2f pos, Vector2f size)
{
	center = pos;
	scale = size;
}

Rect::~Rect()
{
}

bool Rect::contains(Vector2f & pt)
{
	return false;
}

void Rect::draw(float gt)
{
}
