#pragma once



class CircleHitbox;
class RectHitbox;
class ComplexHitbox;
class Object;
class Hitbox;


class CollisionUtil
{
public:
	CollisionUtil();
	~CollisionUtil();

	static bool collide(CircleHitbox & c1, CircleHitbox & c2);
	static bool collide(RectHitbox & r1, RectHitbox & r2);
	static bool collide(ComplexHitbox & c1, ComplexHitbox & c2);
	static bool collide(CircleHitbox & c1, RectHitbox & r1);
	static bool collide(CircleHitbox & c1, ComplexHitbox & c2);
	static bool collide(RectHitbox & r1, ComplexHitbox & c1);

	static bool equalResolve(Object * o1, Object * o2, int bounciness);
	static bool unequalResolve(Object * o1, Hitbox * h2, int bounciness);
	static bool unequalResolve(Object * o1, Object * o2, int bounciness);
};

