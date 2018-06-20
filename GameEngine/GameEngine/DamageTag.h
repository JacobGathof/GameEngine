#pragma once
#include "Tag.h"
#include "Timer.h"

class DamageTag : public Tag
{
public:
	DamageTag();
	virtual ~DamageTag();
	virtual bool update(float dt);

private:
	Timer timer;
};

