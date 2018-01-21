#pragma once

#include "Vector2f.h"
#include "Effect.h"
#include "ResourceManager.h"
#include <vector>

class Object
{
public:
	Object();
	Object(TextureType texture);
	~Object();

	Vector2f pos;
	Vector2f scale;
	TextureType texture;
	bool alive = true;
	std::vector<Effect> effects;

	virtual void draw();
	virtual bool update(float delta_time);
	virtual bool collide(Object * o);
};

