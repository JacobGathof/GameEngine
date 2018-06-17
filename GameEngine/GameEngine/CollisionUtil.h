#pragma once

#include "Vector2f.h"


class CircleHitbox;
class RectHitbox;
class ComplexHitbox;
class CollidableObject;
class MovableObject;
class Hitbox;


class CollisionUtil
{
public:
	CollisionUtil();
	~CollisionUtil();

	static CollidableObject * one;
	static CollidableObject * two;

	static bool collide(CircleHitbox & c1, CircleHitbox & c2);
	static bool collide(RectHitbox & r1, RectHitbox & r2);
	static bool collide(ComplexHitbox & c1, ComplexHitbox & c2);
	static bool collide(CircleHitbox & c1, RectHitbox & r1);
	static bool collide(CircleHitbox & c1, ComplexHitbox & c2);
	static bool collide(RectHitbox & r1, ComplexHitbox & c1);

	static bool equalResolve(CollidableObject * o1, CollidableObject * o2, float bounciness);
	static bool unequalResolve(CollidableObject * o1, Hitbox * h2, float bounciness);
	static bool unequalResolve(CollidableObject * o1, CollidableObject * o2, float bounciness);

private:

	static Vector2f shortestResolve;
};

