#pragma once
#include "Object.h"

enum class Weight {
	VERY_LIGHT,
	LIGHT,
	PLAYER,
	HEAVY,
	VERY_HEAVY,
	UNMOVABLE,
	GHOST
};


class CollidableObject : public Object
{
public:
	CollidableObject(std::string& n, TextureType t, Vector2f& position, Vector2f& sc);
	virtual ~CollidableObject();

	virtual bool collide(Object * o, Hitbox * h);
	virtual void drawHitboxes();
	virtual bool update(float dt);

	void addHitbox(Hitbox * h);
	Hitbox * getHitbox(int i);
	int numHitboxes();
	void updateHitbox();

	Weight weight = Weight::UNMOVABLE;

protected:

	List<Hitbox *> hitboxes;

};

