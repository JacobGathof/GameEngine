#pragma once
class FastParticleSystem
{
public:
	FastParticleSystem(int numberParticles);
	~FastParticleSystem();

	int maxSize;

	void init();
	void update(float dt);
	void draw();

	unsigned int vao;
	unsigned int vbo_positions;
	unsigned int vbo_velocities;
	unsigned int vbo_lifespan;
};

