#pragma once

#include "Vector2f.h"
#include "Effect.h"
#include "ResourceManager.h"
#include "List.h"
#include <stdio.h>
#include "Screen.h"
#include "AI.h"
#include "Hitbox.h"
#include "AbstractAction.h"

class Object
{
public:
	Object();
	Object(std::string n, TextureType t, Vector2f position, Vector2f sc);
	virtual ~Object();

	bool persistent = false;
	bool isStatic = false;
	Vector2f pos;
	Vector2f scale;
	TextureType texture;
	bool alive = true;
	List<Effect *> effects;
	bool stalled = false;
	std::string name;
	bool colliding = false;
	AbstractAction * interactObj = new AbstractAction();
	AI * defaultAI;

	virtual void draw();
	virtual bool update(float delta_time);
	virtual void updateHitbox();
	virtual bool collide(Object * o, Hitbox * h);
	virtual void interact();
	virtual void setAI(AI * ai);
	virtual void setInteraction(AbstractAction * i);

	void addEffect(Effect * eff);
	int numHitboxes();
	void addHitbox(Hitbox * h);
	Hitbox * getHitbox(int i);

protected:
	List<AI *> aiQueue;
	
	List<Hitbox *> hitboxes;
};

