#pragma once
#include "Timer.h"

class BounceTimer : public Timer
{
public:
	virtual void update(float dt);

	BounceTimer();
	~BounceTimer();
private:
	int direction = 1;
};