#pragma once
#include "Vector2f.h"
#include "Color.h"
class IParticle
{
public:
	IParticle();
	~IParticle();

	virtual void draw() {};

protected:

};

