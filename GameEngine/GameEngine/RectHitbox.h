#pragma once

#include "Hitbox.h"
#include "Rectangle.h"

class RectHitbox : public Hitbox
{
public:
	RectHitbox(Rect rect, Vector2f offset);
	~RectHitbox();

	Rect shape;
	

	virtual bool collide(Hitbox * s);
	virtual bool collide(CircleHitbox * h);
	virtual bool collide(RectHitbox * h);
	virtual bool collide(ComplexHitbox * h);
	virtual void draw();
};

