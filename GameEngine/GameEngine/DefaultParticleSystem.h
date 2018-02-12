#pragma once
#include "ParticleSystem.h"

class DefaultParticleSystem : public ParticleSystem
{
public:
	DefaultParticleSystem();
	~DefaultParticleSystem();

	virtual void updateParticle(Particle* p, float dt);
	virtual Particle createNewParticle();
};

