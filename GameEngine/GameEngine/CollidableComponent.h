#pragma once
#include "AbstractObjectComponent.h"
#include "List.h"

class Object;
class AbstractAction;
class Hitbox;

enum class Weight_T {
	VERY_LIGHT,
	LIGHT,
	PLAYER,
	HEAVY,
	VERY_HEAVY,
	UNMOVABLE,
	GHOST
};


class CollidableComponent : public AbstractObjectComponent
{
public:
	CollidableComponent();
	~CollidableComponent();

	static CollidableComponent comp;
	static CollidableComponent* getComponent();


	void drawHitboxes();
	bool update(float dt);


	void addHitbox(Hitbox * h);
	Hitbox * getHitbox(int i = 0);
	int numHitboxes();
	void updateHitbox();

	Weight_T weight = Weight_T::UNMOVABLE;




	void trigger(Object* obj);
	void setEnterTrigger(AbstractAction* a);
	void setExitTrigger(AbstractAction* a);
	void setOnDestroyTrigger(AbstractAction* a);

	void handleTriggers();

	void onEnterTrigger();
	void onExitTrigger();




protected:

	List<Hitbox *> hitboxes;



	bool triggered = false;
	bool triggered_past = false;
	AbstractAction* exitTriggerAction;
	AbstractAction* enterTriggerAction;
	AbstractAction* destroyTriggerAction;
	Object* triggerSubject;

};

