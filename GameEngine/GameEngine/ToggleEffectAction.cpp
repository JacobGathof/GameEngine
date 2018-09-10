#include "ToggleEffectAction.h"
#include "Object.h"
#include "EffectComponent.h"
#include "LightComponent.h"


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
	if (obj->hasTrait<LightComponent>()) {
		obj->getComponent<LightComponent>()->activateEffects(activate);
	}
	activate = !activate;
	return 1;
}
