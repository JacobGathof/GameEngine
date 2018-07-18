#pragma once
#include "ParticleSystem.h"

class FireflyParticleSystem : public ParticleSystem {

public:
	FireflyParticleSystem();
	~FireflyParticleSystem();

	virtual void updateParticle(Particle* p, float dt);
	virtual Particle createNewParticle();
	virtual void draw();
};