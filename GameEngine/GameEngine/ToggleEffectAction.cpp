#include "ToggleEffectAction.h"
#include "Object.h"



ToggleEffectAction::ToggleEffectAction(Object * target, bool a)
{
	obj = target;
	activate = a;
}

ToggleEffectAction::~ToggleEffectAction()
{
}

int ToggleEffectAction::run(float dt)
{
	obj->activateEffects(activate);
	return 1;
}
