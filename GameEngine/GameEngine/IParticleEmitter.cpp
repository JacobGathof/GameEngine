#include "IParticleEmitter.h"
#include "SimpleParticle.h"

IParticle IParticleEmitter::createNewParticle()
{
	return SimpleParticle();
}
