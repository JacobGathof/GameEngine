#include "RainParticleSystem.h"



RainParticleSystem::RainParticleSystem()
{
	startColor = Color::LightBlue;
	endColor = Color::White;
	maxParticlesPerSecond = 100;
}


RainParticleSystem::~RainParticleSystem(){}


void RainParticleSystem::updateParticle(Particle * p, float dt)
{
	float r = (float)rand() / RAND_MAX * 2 * 3.1415f;

	if (p->life > maxParticleLife / 4.0f) {
		p->position += dt * p->velocity;
	}

	p->color += (endColor - startColor) / maxParticleLife * dt;
	p->life -= dt;
}

Particle RainParticleSystem::createNewParticle()
{

	Vector2f pPosition = position + Vector2f(0, 800) + Vector2f(1600*(float)rand() / RAND_MAX - 800, 0);
	if (parentPosition != 0) {
		pPosition += *parentPosition;
	}
	Vector2f pVelocity = -200*2* Vector2f(.1f, 1);
	Color pColor = startColor;
	float pLife = maxParticleLife* ((float)rand() / RAND_MAX+.5f);

	return Particle(pPosition, pColor, pVelocity, pLife);

}

void RainParticleSystem::draw()
{
	Res::get(ShaderType::PLAIN_SHADER)->bind();
	Res::get(ShaderType::PLAIN_SHADER)->loadColor("color", Color(0,0,0, .125f));
	Res::get(ModelType::MODEL_SQUARE_CENTERED)->bind();
	Res::get(ModelType::MODEL_SQUARE_CENTERED)->draw();


	Res::get(ShaderType::PARTICLE_SHADER)->bind();
	Res::get(ShaderType::PARTICLE_SHADER)->loadFloat("halfLife", maxParticleLife/2.0f);
	model.bind();
	glDrawArrays(GL_POINTS, 0, maxParticles);
}
