#pragma once
#include "IParticle.h"

class SimpleParticle : public IParticle
{
public:
	SimpleParticle();
	~SimpleParticle();

	virtual void draw();
};

