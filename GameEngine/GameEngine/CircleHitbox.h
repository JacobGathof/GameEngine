#pragma once

#include "Hitbox.h"
#include "ComplexHitbox.h"
#include "RectHitbox.h"
#include "Circle.h"

class CircleHitbox : public Hitbox
{
public:
	CircleHitbox(float radius, Vector2f& off);
	~CircleHitbox();

	Circle shape;

	virtual bool collide(Hitbox * s);
	virtual bool collide(CircleHitbox * h);
	virtual bool collide(RectHitbox * h);
	virtual bool collide(ComplexHitbox * h);

	virtual void updatePos(Vector2f p);
	virtual void draw();

	virtual Shape* getShape();
};

