#pragma once
#include "ShaderManager.h"
#include "Model.h"
#include "Texture.h"
#include "Screen.h"
#include "Timer.h"

#include "ParticleEmitter.h"
#include "Effect.h"


template<class T>
class ParticleSystem : public Effect
{
public:

	ParticleSystem(int m, float p, std::initializer_list<IParticleEmitterComponent*> comps) {
		maxParticles = m;
		maxParticlesPerSecond = p;
		maxParticleLife = m / p;

		emitter.setComponents(comps);
		init();
	};

	~ParticleSystem() {
		for (int i = 0; i < maxParticles; i++) {
			if (particles[i] != 0) {
				delete particles[i];
			}
		}
		delete[] particles;
	};

	void setEmit(bool doEmit) {
		emit = doEmit;
	};
	virtual bool update(float dt) {
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

	};

	virtual void draw() {
		for (int i = 0; i < maxParticles; i++) {
			IParticle* p = particles[i];
			if (p != 0) {
				p->draw();
			}
		}
	};

protected:
	Timer timer;

private:
	void init() {
		particles = new IParticle*[maxParticles] {0};
		emit = true;

	};

	IParticle * createNewParticle() {
		ParticleData data;
		data.position = parent->pos;
		data.life = maxParticleLife;

		return emitter.createNewParticle(data);
	};

	IParticle ** particles;

	int maxParticles;
	float maxParticlesPerSecond;
	float maxParticleLife;

	int pIndex = 0;
	bool emit = true;
	float particleLeftOver = 0.0f;

	ParticleEmitter<T> emitter;

};





