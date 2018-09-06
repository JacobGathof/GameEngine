#pragma once
#include "Vector2f.h"

class Force
{
public:
	Force(Vector2f& f);
	~Force();

	bool update(float dt);

	float friction = .25f;
	Vector2f value;
};

