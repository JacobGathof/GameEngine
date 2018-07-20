#pragma once
#include "AbstractAction.h"

class SetVolumeAction : public AbstractAction
{
public:
	SetVolumeAction(float* ref);
	~SetVolumeAction();

	virtual int run(float dt);
private:
	float * f;
};

