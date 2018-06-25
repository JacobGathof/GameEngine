#include "FastParticleSystem.h"
#include "Vector3f.h"
#include "ResourceManager.h"
#include "Screen.h"
#include "GameState.h"
#include "Object.h"

FastParticleSystem::FastParticleSystem(int ms)
{
	maxSize = ms;
	init();
}


FastParticleSystem::~FastParticleSystem()
{
	glDeleteBuffers(1, &vbo_positions);
	glDeleteBuffers(1, &vbo_velocities);
	glDeleteVertexArrays(1, &vao);
}

void FastParticleSystem::init()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo_positions);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_positions);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*4*maxSize, 0, GL_DYNAMIC_COPY);
	float* positions = (float*)glMapBufferRange(GL_ARRAY_BUFFER, 0, maxSize * 4 * sizeof(float), GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
	for (int i = 0; i < maxSize; i++) {
		Vector2f pos((float)rand() / RAND_MAX - .5, (float)rand() / RAND_MAX - .5);
		Vector2f vel((float)rand() / RAND_MAX - .5, (float)rand() / RAND_MAX - .5);
		positions[4 * i + 0] = pos[0]*100;
		positions[4 * i + 1] = pos[1]*100;
		positions[4 * i + 2] = vel[0] * 1000;
		positions[4 * i + 3] = vel[1] * 1000;
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glVertexAttribPointer(0, 4, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(0);


	glGenBuffers(1, &vbo_velocities);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_velocities);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4 * maxSize, 0, GL_DYNAMIC_COPY);
	float* velocities = (float*)glMapBufferRange(GL_ARRAY_BUFFER, 0, maxSize * 4 * sizeof(float), GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
	for (int i = 0; i < maxSize; i++) {
		velocities[4 * i + 0] = 0;
		velocities[4 * i + 1] = 0;
		velocities[4 * i + 2] = 1;
		velocities[4 * i + 3] = 4*(float)rand() / RAND_MAX;
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glVertexAttribPointer(1, 4, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(1);

}

bool FastParticleSystem::update(float dt)
{
	
	Res::get(ShaderType::PARTICLE_COMPUTE_SHADER)->bind();
	Res::get(ShaderType::PARTICLE_COMPUTE_SHADER)->loadFloat("dt", dt);
	Res::get(ShaderType::PARTICLE_COMPUTE_SHADER)->loadVector2f("center", parent->pos);

	glBindVertexArray(vao);

	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, vbo_positions);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, vbo_velocities);
	glDispatchCompute(maxSize / 256, 1, 1);
	//glMemoryBarrier(GL_ALL_BARRIER_BITS);

	return true;
	
}

void FastParticleSystem::draw()
{
	Res::get(ShaderType::PARTICLE_FAST_SHADER)->bind();
	Res::get(ShaderType::PARTICLE_FAST_SHADER)->loadVector2f("scale", Vector2f(1,1));
	Res::get(ShaderType::PARTICLE_FAST_SHADER)->loadVector2f("translate", Vector2f(0,0));

	glBindVertexArray(vao);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDrawArrays(GL_POINTS, 0, maxSize);

}
