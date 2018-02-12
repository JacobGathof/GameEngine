#pragma once
#include "Vector2f.h"
#include "Color.h"

class Particle {
public:
	Particle(Vector2f p, Color c, Vector2f v, float l);
	Particle();
	Vector2f position;
	Vector2f velocity;
	Color color;
	float life;
};