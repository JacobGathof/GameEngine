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
	glDeleteBuffers(1, &vbo_lifespan);
	glDeleteVertexArrays(1, &vao);
}

void FastParticleSystem::init()
{
	float * data = new float[maxSize * 2];
	float * data1 = new float[maxSize * 2];
	float * data2 = new float[maxSize];
	for (int i = 0; i < maxSize; i++) {
		Vector2f v((-.5f + ((float)rand()) / RAND_MAX), (-.5f + ((float)rand()) / RAND_MAX));
		Vector2f v1((-.5f + ((float)rand()) / RAND_MAX), (-.5f + ((float)rand()) / RAND_MAX));

		v = 100*v.normalize();
		v1 = 300*v1.normalize();

		data[2 * i + 0] = v[0];
		data[2 * i + 1] = v[1];

		data1[2 * i + 0] = v1[0];
		data1[2 * i + 1] = v1[1];

		data2[i] = 2.0f * (float)i / maxSize;
	}

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo_positions);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_positions);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*2*maxSize, data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(0);
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, vbo_positions);

	glGenBuffers(1, &vbo_velocities);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_velocities);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 2 * maxSize, data1, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(1);
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 1, vbo_velocities);

	glGenBuffers(1, &vbo_lifespan);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_lifespan);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 1 * maxSize, data2, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 1, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(2);
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 2, vbo_lifespan);


	delete[] data;
	delete[] data1;
	delete[] data2;

}

void FastParticleSystem::update(float dt)
{
	Res::get(ShaderType::PARTICLE_FAST_SHADER)->loadFloat("dt", dt);
}

void FastParticleSystem::draw()
{
	Res::get(ShaderType::PARTICLE_FAST_SHADER)->bind();
	Res::get(ShaderType::PARTICLE_FAST_SHADER)->loadVector2f("scale", Screen::toScreenScale(Vector2f(1,1)));
	Res::get(ShaderType::PARTICLE_FAST_SHADER)->loadVector2f("translate", Screen::toScreenCoords(Vector2f(0,0)));

	glBindVertexArray(vao);


	//glEnable(GL_DEPTH_TEST);
	glBeginTransformFeedback(GL_POINTS);
	glDrawArrays(GL_POINTS, 0, maxSize);
	glEndTransformFeedback();



	//glDisable(GL_DEPTH_TEST);

	
}
