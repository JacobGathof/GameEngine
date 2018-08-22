#pragma once
#include "Effect.h"

class Pulse : public Effect
{
public:
	Pulse();
	~Pulse();

	virtual bool update(float dt);
	virtual void draw();

private:
	float size = 0;


};

