#include "Particle.h"


Particle::Particle(Vector2f p, Color c, Vector2f v, float l)
{
	position = p;
	color = c;
	velocity = v;
	life = l;
}

Particle::Particle()
{
	position = Vector2f(0, 0);
	color = Color(1, 1, 1, 1);
	velocity = Vector2f(0, 0);
	life = -1;
}
