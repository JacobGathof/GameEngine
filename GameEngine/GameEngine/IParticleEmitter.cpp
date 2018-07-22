#include "IParticleEmitter.h"

IParticle* IParticleEmitter::createNewParticle(Vector2f& origin)
{
	float r = (float)rand() / RAND_MAX * 3.14159f * 2;
	return new LightParticle(origin, 200*Vector2f(cos(r), sin(r)), Color::White);
}
