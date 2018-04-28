#pragma once
#include "Effect.h"

class FastParticleSystem : public Effect
{
public:
	FastParticleSystem(int numberParticles);
	virtual ~FastParticleSystem();

	int maxSize;

	void init();
	virtual void update(float dt);
	virtual void draw();

	unsigned int vao;
	unsigned int vbo_positions;
	unsigned int vbo_velocities;
};

