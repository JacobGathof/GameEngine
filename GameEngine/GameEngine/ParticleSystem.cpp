#include "ParticleSystem.h"



ParticleSystem::ParticleSystem() {
	maxParticles = 3000;
	maxParticlesPerSecond = 1000;
	init();
}


ParticleSystem::~ParticleSystem() {
	delete[] particles;
	delete[] pos;
	delete[] col;
	delete[] lif;
}

void ParticleSystem::init()
{
	particles = new Particle[maxParticles];
	pos = new float[2 * maxParticles];
	col = new float[4 * maxParticles];
	lif = new float[maxParticles];

	model.init();
	model.bind();
	vbo_pos = model.addData(pos, maxParticles*2, 2, 0);
	vbo_col = model.addData(col, maxParticles*4, 4, 1);
	vbo_lif = model.addData(lif, maxParticles*1, 1, 2);

	emit = true;

	/*
	float *data = new float[maxParticles * 4];
	tex.getData(data);


	for (int i = 0; i < maxParticles; i++) {
		float r = (float)rand() / RAND_MAX * 2 * 3.1415f;
		Vector2f pos((i % 36) / 128.0f, -(int)(i / 36.0f) / 128.0f);
		Color col(data[4 * i + 0], data[4 * i + 1], data[4 * i + 2], data[4 * i + 3]);
		particles[i] = Particle(
			pos,
			col,
			.1f*Vector2f(cos(r), sin(r)), 4.0f);

	}

	writeParticleData();
	updateBuffers();

	delete[] data;
	*/

}

void ParticleSystem::setEmit(bool doEmit)
{
	emit = doEmit;
}

bool ParticleSystem::update(float dt)
{
	timer.update(dt);

	ptime += dt;
	int particlesToCreate = 0;

	if (emit) {
		 particlesToCreate = (int)(dt*maxParticlesPerSecond);
	}

	for (int j = 0; j < particlesToCreate; j++) {
		particles[pIndex] = createNewParticle();
		pIndex = ++pIndex % maxParticles;
	}

	for (int i = 0; i < maxParticles; i++) {
		Particle* p = &particles[i];

		if (p->life > 0.0f) {
			updateParticle(p, dt);
		}
	}

	writeParticleData();
	updateBuffers();

	return true;
}

void ParticleSystem::emitParticles(int numParticles)
{
	for (int j = 0; j < numParticles; j++) {
		particles[pIndex] = createNewParticle();
		pIndex = ++pIndex % maxParticles;
	}
}

void ParticleSystem::updateBuffers()
{
	model.bind();
	model.updateData(vbo_pos, pos, maxParticles * 2);
	model.updateData(vbo_col, col, maxParticles * 4);
	model.updateData(vbo_lif, lif, maxParticles * 1);
}

void ParticleSystem::writeParticleData()
{
	for (int i = 0; i < maxParticles; i++) {
		Particle* p = &particles[i];
		Vector2f q1 = Screen::toScreenCoords(p->position);

		pos[2 * i + 0] = q1[0];
		pos[2 * i + 1] = q1[1];

		col[4 * i + 0] = p->color[0];
		col[4 * i + 1] = p->color[1];
		col[4 * i + 2] = p->color[2];
		col[4 * i + 3] = p->color[3];

		lif[i] = p->life;
	}
}


void ParticleSystem::draw()
{
	Res::get(ShaderType::PARTICLE_SHADER)->bind();
	model.bind();
	glDrawArrays(GL_POINTS, 0, maxParticles);
}


