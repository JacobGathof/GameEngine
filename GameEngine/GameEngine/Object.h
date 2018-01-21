#pragma once

#include "Vector2f.h"
#include "Effect.h"
#include <vector>

class Object
{
public:
	Object();
	~Object();

	Vector2f pos;
	Vector2f scale;
    //Enum Texture
	bool alive = true;
	std::vector<Effect> effects;

	virtual void draw();
	virtual bool update(float delta_time);
	virtual bool collide(Object * o);
};

