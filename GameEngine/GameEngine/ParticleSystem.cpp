#include "ParticleSystem.h"



IParticle ParticleSystem::createNewParticle()
{
	return emitter.createNewParticle();
}

ParticleSystem::ParticleSystem() {
	maxParticles = 10;
	maxParticlesPerSecond = 1;
	init();
}


ParticleSystem::~ParticleSystem() {
	delete[] particles;
}

void ParticleSystem::setEmitter(IParticleEmitter & em)
{
	emitter = em;
}

void ParticleSystem::init()
{
	particles = new IParticle[maxParticles];

	emit = true;

}

void ParticleSystem::setEmit(bool doEmit)
{
	emit = doEmit;
}

bool ParticleSystem::update(float dt)
{
	timer.update(dt);

	ptime += dt;
	float fractParticles = 0;
	int particlesToCreate = 0;

	if (emit) {
		 fractParticles = (dt*maxParticlesPerSecond);
		 if (fractParticles < 1.0f) {
			 particleLeftOver += fractParticles;
		 }
	}

	particlesToCreate += (int)fractParticles;
	if (particleLeftOver >= 1.0) {
		particleLeftOver -= 1.0f;
		particlesToCreate += 1;
	}



	for (int j = 0; j < particlesToCreate; j++) {
		particles[pIndex] = createNewParticle();
		pIndex = ++pIndex % maxParticles;
	}

	for (int i = 0; i < maxParticles; i++) {
		IParticle* p = &particles[i];

		/*
		if (p->life > 0.0f) {
			updateParticle(p, dt);
		}
		*/
	}

	return true;
}




void ParticleSystem::draw()
{
	for (int i = 0; i < maxParticles; i++) {
		particles[i].draw();
	}

}


