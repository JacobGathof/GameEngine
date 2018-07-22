#include "ParticleSystem.h"
#include "Object.h"


IParticle* ParticleSystem::createNewParticle()
{
	return emitter.createNewParticle(parent->pos);
}


ParticleSystem::ParticleSystem(IParticleEmitter& e, int m)
{
	setEmitter(e);
	maxParticles = m;
	init();
}

ParticleSystem::~ParticleSystem() {
	for (int i = 0; i < maxParticles; i++) {
		if (particles[i] != 0) {
			delete particles[i];
		}
	}
	delete[] particles;
}

void ParticleSystem::setEmitter(IParticleEmitter & em)
{
	emitter = em;
}

void ParticleSystem::init()
{
	particles = new IParticle*[maxParticles] {0};
	emit = true;

}

void ParticleSystem::setEmit(bool doEmit)
{
	emit = doEmit;
}

bool ParticleSystem::update(float dt)
{
	timer.update(dt);

	float fractParticles = 0;
	int particlesToCreate = 0;

	if (emit && active) {
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
		IParticle* p = particles[i];
		if (p != 0) {
			p->update(dt);
		}

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
		IParticle* p = particles[i];
		if (p != 0) {
			p->draw();
		}
	}

}


