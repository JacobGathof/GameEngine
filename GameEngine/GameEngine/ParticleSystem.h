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

	virtual IParticle createNewParticle();

	ParticleSystem();
	virtual ~ParticleSystem();

	void setEmitter(IParticleEmitter& emitter);


	Color startColor = Color(0xddddff88);
	Color endColor = Color(0x0000ffff);
	Color randColor = Color(0x00000000);


	void init();
	void setEmit(bool doEmit);
	virtual bool update(float dt);

	virtual void draw();

protected:
	Timer timer;

private:
	IParticle * particles;

	Vector2f position;
	float speed;
	bool active;

	int maxParticles = 30;
	float maxParticlesPerSecond = 10;
	int pIndex = 0;
	float ptime = 0.0f;
	bool emit = true;
	float maxParticleLife = 3.0f;
	float particleLeftOver = 0.0f;


	IParticleEmitter emitter;

};

