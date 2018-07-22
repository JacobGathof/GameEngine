#pragma once
#include "AbstractAction.h"

class Object;

class ToggleEffectAction : public AbstractAction
{
public:
	ToggleEffectAction(Object* target, bool activate);
	~ToggleEffectAction();

	virtual int run(float dt);

private:
	Object * obj;
	bool activate;
};

