#pragma once

#include "Vector2f.h"
#include "Effect.h"
#include "ResourceManager.h"
#include "List.h"
#include <stdio.h>
#include "Screen.h"
#include "AI.h"
#include "Hitbox.h"

class Object
{
public:
	Object();
	Object(std::string n, TextureType t, Vector2f position, Vector2f sc);
	~Object();

	Vector2f pos;
	Vector2f scale;
	TextureType texture;
	bool alive = true;
	List<Effect *> effects;
	bool stalled = false;
	std::string name;
	List<AI *> aiQueue;
	AI * defaultAI;
	List<Hitbox *> hitboxes;

	virtual void draw();
	virtual void drawEffects();

	virtual bool update(float delta_time);
	virtual bool collide(Object * o);
	virtual void interact();
	virtual void setAI(AI * ai);

	void addEffect(Effect * eff);
	int numHitboxes();
	void addHitbox(Hitbox * h);
	Hitbox * getHitbox(int i);
	
};

