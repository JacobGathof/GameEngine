#pragma once

#include "Vector2f.h"


class CircleHitbox;
class RectHitbox;
class ComplexHitbox;
class Object;
class MovableObject;
class Hitbox;


class CollisionUtil
{
public:
	CollisionUtil();
	~CollisionUtil();

	static Object * one;
	static Object * two;

	static bool collide(CircleHitbox & c1, CircleHitbox & c2);
	static bool collide(RectHitbox & r1, RectHitbox & r2);
	static bool collide(ComplexHitbox & c1, ComplexHitbox & c2);
	static bool collide(CircleHitbox & c1, RectHitbox & r1);
	static bool collide(CircleHitbox & c1, ComplexHitbox & c2);
	static bool collide(RectHitbox & r1, ComplexHitbox & c1);

	static bool equalResolve(MovableObject * o1, Object * o2, float bounciness);
	static bool unequalResolve(MovableObject * o1, Hitbox * h2, float bounciness);
	static bool unequalResolve(MovableObject * o1, Object * o2, float bounciness);

private:

	static Vector2f shortestResolve;
};

