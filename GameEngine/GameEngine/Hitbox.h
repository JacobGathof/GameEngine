#pragma once

#include "Vector2f.h"
#include "CollisionUtil.h"
#include "Shape.h"
class CircleHitbox;
class RectHitbox;
class ComplexHitbox;

class Hitbox
{
public:
	Hitbox();
	~Hitbox();

	Vector2f offset;

	virtual Vector2f getPos();
	virtual void updatePos(Vector2f p);
	virtual bool collide(Hitbox * s);
	virtual bool collide(CircleHitbox * h);
	virtual bool collide(RectHitbox * h);
	virtual bool collide(ComplexHitbox * h);
	virtual void draw();

protected:
	Vector2f pos;
};

