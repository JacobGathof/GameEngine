#include "FireflyParticleSystem.h"
#include "Object.h"


FireflyParticleSystem::FireflyParticleSystem()
{
	startColor = Color::Green;
	endColor = Color::Green;
	maxParticleLife = 10.0f;
}


FireflyParticleSystem::~FireflyParticleSystem()
{
}

void FireflyParticleSystem::updateParticle(Particle * p, float dt)
{
	float r = (float)rand() / RAND_MAX * 2 * 3.1415f;

	p->position += dt * p->velocity;
	p->velocity += 10*Vector2f(cos(r), sin(r));
	p->life -= dt;

	p->color = Color::Gray;
	if (p->life < 9.0f && p->life > 8.5f) {
		p->color = Color::Green;
	}
}

Particle FireflyParticleSystem::createNewParticle()
{
	float r = (float)rand() / RAND_MAX * 2 * 3.1415f;
	float r2 = (float)rand() / RAND_MAX * 2 * 3.1415f;

	Vector2f pPosition = parent->pos + 512 * Vector2f(cos(r), sin(r));
	Vector2f pVelocity = 256*Vector2f(cos(r2), sin(r2));
	Color pColor = startColor;
	float pLife = 10.0f;

	return Particle(pPosition, pColor, pVelocity, pLife);

}

void FireflyParticleSystem::draw()
{
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
	Res::get(ShaderType::PARTICLE_SHADER)->bind();
	model.bind();
	glDrawArrays(GL_POINTS, 0, maxParticles);
}
