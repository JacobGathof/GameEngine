#pragma once
#include "ParticleSystem.h"

class RainParticleSystem : public ParticleSystem {

public:
	RainParticleSystem();
	~RainParticleSystem();

	virtual void updateParticle(Particle* p, float dt);
	virtual Particle createNewParticle();
	virtual void draw();
};

