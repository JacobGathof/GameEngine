#include "ToggleEffectAction.h"
#include "Object.h"
#include "EffectComponent.h"


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
	if (obj->hasTrait<EffectComponent>()) {
		obj->getComponent<EffectComponent>()->activateEffects(activate);
	}
	return 1;
}
