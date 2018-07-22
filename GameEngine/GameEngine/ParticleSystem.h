#pragma once
#include "ShaderManager.h"
#include "Model.h"
#include "Texture.h"
#include "Screen.h"
#include "Timer.h"

#include "IParticleEmitter.h"
#include "Effect.h"


class ParticleSystem : public Effect
{
public:

	ParticleSystem(IParticleEmitter& emitter, int maxParticles);
	~ParticleSystem();

	void setEmitter(IParticleEmitter& emitter);

	void setEmit(bool doEmit);
	virtual bool update(float dt);

	virtual void draw();

protected:
	Timer timer;

private:
	void init();

	IParticle * createNewParticle();
	IParticle ** particles;

	int maxParticles = 30;
	float maxParticlesPerSecond = 10;
	float maxParticleLife = 3.0f;

	int pIndex = 0;
	bool emit = true;
	float particleLeftOver = 0.0f;


	IParticleEmitter emitter;

};

