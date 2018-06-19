#include "DefaultParticleSystem.h"
#include "Object.h"


DefaultParticleSystem::DefaultParticleSystem() : ParticleSystem()
{
	startColor = Color::White;
	endColor = Color::LightRed;
}


DefaultParticleSystem::~DefaultParticleSystem()
{
}

void DefaultParticleSystem::updateParticle(Particle * p, float dt)
{
	float r = (float)rand() / RAND_MAX * 2 * 3.1415f;

	p->velocity += dt * Vector2f(p->velocity[1], -p->velocity[0]);
	//velocity += dt * 400 * Vector2f(sin(r),cos(r));
	p->position += dt * p->velocity;
	p->color += (endColor - startColor) / maxParticleLife * dt * 2;
	p->life -= dt;
}

Particle DefaultParticleSystem::createNewParticle()
{
	float r = (float)rand() / RAND_MAX * 2 * 3.1415f;
	Vector2f v(cos(r)*cos(2*timer.getTotalTime()), sin(r)*sin(timer.getTotalTime()));
	Vector2f pPosition = position + v * 50;
	pPosition += parent->pos;

	Vector2f pVelocity = 50 * Vector2f(cos(r), sin(r));
	Color pColor = startColor;
	float pLife = maxParticleLife;

	return Particle(pPosition, pColor, pVelocity, pLife);

}
