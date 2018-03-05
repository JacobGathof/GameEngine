#pragma once

#include "Vector2f.h"
#include "Effect.h"
#include "ResourceManager.h"
#include "List.h"
#include <vector>
#include <stdio.h>
#include "Screen.h"

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

	virtual void draw();
	virtual bool update(float delta_time);
	virtual bool collide(Object * o);
	virtual void interact();
	void addEffect(Effect * eff);
	
};

