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
	virtual bool collide(CollidableObject* obj);

	virtual void drawHitboxes();
	virtual bool update(float dt);


	virtual void trigger();
	virtual void setEnterTrigger(AbstractAction* a);
	virtual void setExitTrigger(AbstractAction* a);
	virtual void handleTriggers();

	virtual void onEnterTrigger();
	virtual void onExitTrigger();


	void addHitbox(Hitbox * h);
	Hitbox * getHitbox(int i);
	int numHitboxes();
	void updateHitbox();

	Weight weight = Weight::UNMOVABLE;

protected:

	List<Hitbox *> hitboxes;

	bool triggered = false;
	bool triggered_past = false;
	AbstractAction* exitTriggerAction;
	AbstractAction* enterTriggerAction;

};

