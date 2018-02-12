#pragma once
#include "ParticleSystem.h"

class DirectedParticleSystem : public ParticleSystem
{
public:
	DirectedParticleSystem();
	~DirectedParticleSystem();

	virtual void updateParticle(Particle* p, float dt);
	virtual Particle createNewParticle();

	Vector2f direction;
	float spread;
};

