#include "FastParticleSystem.h"
#include "Vector3f.h"
#include "ResourceManager.h"
#include "Screen.h"
#include "GameState.h"

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
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*4*maxSize, 0, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(0);
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, vbo_positions);

	glGenBuffers(1, &vbo_velocities);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_velocities);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4 * maxSize, 0, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(1);
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 1, vbo_velocities);

}

void FastParticleSystem::update(float dt)
{
	Res::get(ShaderType::PARTICLE_COMPUTE_SHADER)->loadFloat("dt", dt);

	glBindVertexArray(vao);

	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, vbo_positions);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, vbo_velocities);
	glDispatchCompute(maxSize / 256, 1, 1);
	glMemoryBarrier(GL_ALL_BARRIER_BITS);

}

void FastParticleSystem::draw()
{
	Res::get(ShaderType::PARTICLE_SHADER)->bind();
	Res::get(ShaderType::PARTICLE_SHADER)->loadVector2f("scale", Screen::toScreenScale(Vector2f(1,1)));
	Res::get(ShaderType::PARTICLE_SHADER)->loadVector2f("translate", Screen::toScreenCoords(Vector2f(0,0)));

	glBindVertexArray(vao);

	glDrawArrays(GL_POINTS, 0, maxSize);
	
}
