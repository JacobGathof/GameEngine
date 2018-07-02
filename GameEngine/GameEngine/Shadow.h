#pragma once
#include "Light.h"

class Shadow : public Light
{
public:
	Shadow();
	virtual ~Shadow();

	virtual bool update(float dt);

};

