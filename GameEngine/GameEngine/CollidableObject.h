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
	CollidableObject(ObjectData& data);
	virtual ~CollidableObject();

	virtual bool collide(Object * o, Hitbox * h);
	virtual bool collide(CollidableObject* obj);

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

