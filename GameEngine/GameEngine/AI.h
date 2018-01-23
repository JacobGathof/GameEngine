#pragma once

#include "Object.h"

class AI
{
public:
	AI();
	~AI();

	virtual bool execute(Object * obj);
};

