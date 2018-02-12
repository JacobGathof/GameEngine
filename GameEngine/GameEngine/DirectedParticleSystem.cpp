#include "DirectedParticleSystem.h"



DirectedParticleSystem::DirectedParticleSystem()
{
	startColor = Color::DarkBlue;
	endColor = Color::LightBlue;
	direction = Vector2f(0,1);
	spread = 3.1415f*2 / 8;
}


DirectedParticleSystem::~DirectedParticleSystem()
{
}

void DirectedParticleSystem::updateParticle(Particle * p, float dt)
{
	float r = (float)rand() / RAND_MAX * 2 * 3.1415f;

	p->position += dt * p->velocity;
	p->color += (endColor - startColor) / maxParticleLife * dt;
	p->life -= dt;
}

Particle DirectedParticleSystem::createNewParticle()
{
	float r = (2*(float)rand() / RAND_MAX - 1) * spread/2;
	float r2 = 50* (float)rand() / RAND_MAX +150;
	float r3 = .2f * ((float)rand() / RAND_MAX);

	Vector2f pPosition = position;
	if (parentPosition != 0) {
		pPosition += *parentPosition;
	}
	Vector2f pVelocity = r2 * (direction.rotate(r));
	Color pColor = startColor + Color(1,1,1,1)*r3;
	float pLife = maxParticleLife;

	return Particle(pPosition, pColor, pVelocity, pLife);

}