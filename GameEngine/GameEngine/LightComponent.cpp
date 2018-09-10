#include "LightComponent.h"


LightComponent LightComponent::comp;

LightComponent::LightComponent()
{
}


LightComponent::~LightComponent()
{
	for (auto a : lights) {
		delete a;
	}
}

LightComponent * LightComponent::getComponent()
{
	return &comp;
}

void LightComponent::setParent(Object * obj)
{
	AbstractObjectComponent::setParent(obj);
	for (auto a : lights) {
		a->setParent(obj);
	}
}

bool LightComponent::update(float dt)
{
	for (auto a : lights) {
		a->update(dt);
	}
	return false;
}

void LightComponent::addLight(Light * l)
{
	if (parent != 0) {
		l->setParent(parent);
	}
	lights.add(l);
}

void LightComponent::removeLight(Light * l)
{
	lights.remove(l);
}

void LightComponent::drawLights()
{
	for (Light * l : lights) {
		l->draw();
	}
}

void LightComponent::activateEffects(bool b)
{
	for (Light * l : lights) {
		l->setActive(b);
	}
}
