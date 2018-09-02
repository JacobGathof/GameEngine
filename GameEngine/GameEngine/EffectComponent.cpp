#include "EffectComponent.h"



EffectComponent::EffectComponent()
{
}


EffectComponent::~EffectComponent()
{
	for (auto eff : effects) {
		delete eff;
	}
}

EffectComponent * EffectComponent::getComponent()
{
	return nullptr;
}

void EffectComponent::setParent(Object * obj)
{
	AbstractObjectComponent::setParent(obj);
	for (auto a : effects) {
		a->setParent(obj);
	}
}

bool EffectComponent::update(float dt)
{
	for (auto a : effects) {
		a->update(dt);
	}
	return false;
}


void EffectComponent::drawEffects()
{
	for (Effect * eff : effects) {
		eff->draw();
	}
}



void EffectComponent::addEffect(Effect * eff)
{
	if (parent != 0) {
		eff->setParent(parent);
	}
	effects.add(eff);
}

void EffectComponent::removeEffect(Effect * eff)
{
	effects.remove(eff);
}

void EffectComponent::activateEffects(bool b)
{
	for (Effect * eff : effects) {
		eff->setActive(b);
	}
}
