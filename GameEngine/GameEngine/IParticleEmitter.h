#pragma once
#include "IParticle.h"

class IParticleEmitter
{
public:
	virtual IParticle* createNewParticle(Vector2f& origin);

protected:



};

