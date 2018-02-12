#pragma once
#include "ShaderManager.h"
#include "Model.h"
#include "Texture.h"
#include "Screen.h"
#include "Timer.h"

#include "Particle.h"


class ParticleSystem
{
public:

	virtual void updateParticle(Particle* p, float dt) = 0;
	virtual Particle createNewParticle() = 0;

	ParticleSystem();
	~ParticleSystem();


	int maxParticles = 3000;
	float maxParticlesPerSecond = 1000;
	int pIndex = 0;
	float ptime = 0.0f;
	bool emit = true;
	float maxParticleLife = 3.0f;


	Color startColor = Color(0xddddff88);
	Color endColor = Color(0x0000ffff);
	Color randColor = Color(0x00000000);

	Vector2f position;
	Vector2f * parentPosition;

	float speed;
	bool active;

	void init();
	void setEmit(bool doEmit);
	void update(float dt);
	void emitParticles(int numParticles);
	void updateBuffers();
	void writeParticleData();
	void draw();

protected:
	Timer timer;

private:
	Model model;
	unsigned int vbo_pos;
	unsigned int vbo_col;
	unsigned int vbo_lif;

	Particle * particles;
	float* pos;
	float* col;
	float* lif;

};

