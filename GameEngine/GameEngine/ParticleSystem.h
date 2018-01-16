#pragma once
#include "ShaderManager.h"
#include "Model.h"

class ParticleSystem
{
public:

	class Particle {
	public:
		Particle(Vector2f p, Color c, Vector2f v, float l);
		Particle();
		Vector2f position;
		Vector2f velocity;
		Color color;
		float life;
		void update(float dt);
	};


	ParticleSystem();
	~ParticleSystem();

	int maxParticles = 1000;
	int pIndex = 0;
	float ptime = 0.0f;
	float maxParticlesPerSecond = 500;

	Particle * particles;
	float* pos;
	float* col;
	float* lif;

	Model model;
	unsigned int vbo_pos;
	unsigned int vbo_col;
	unsigned int vbo_lif;

	Vector2f sys_pos;
	float speed;
	bool active;

	void init();
	void emit(bool doEmit);
	void update(float dt);
	void updateBuffers();
	void writeParticleData();
	void render();

	Particle createNewParticle();
};
