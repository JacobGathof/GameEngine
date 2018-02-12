#include "RainParticleSystem.h"



RainParticleSystem::RainParticleSystem()
{
	startColor = Color::LightBlue;
	endColor = Color::White;
	maxParticlesPerSecond = 100;
}


RainParticleSystem::~RainParticleSystem(){}


void RainParticleSystem::updateParticle(Particle * p, float dt)
{
	float r = (float)rand() / RAND_MAX * 2 * 3.1415f;

	p->position += dt * p->velocity;
	p->color += (endColor - startColor) / maxParticleLife * dt;
	p->life -= dt;
}

Particle RainParticleSystem::createNewParticle()
{

	Vector2f pPosition = position + Vector2f(0, 800) + Vector2f(1600*(float)rand() / RAND_MAX - 800, 0);
	if (parentPosition != 0) {
		pPosition += *parentPosition;
	}
	Vector2f pVelocity = -800*2* Vector2f(.1, 1);
	Color pColor = startColor;
	float pLife = maxParticleLife;

	return Particle(pPosition, pColor, pVelocity, pLife);

}