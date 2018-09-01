#include "LivingComponent.h"

LivingComponent LivingComponent::comp;

LivingComponent::LivingComponent()
{
}


LivingComponent::~LivingComponent()
{
}

LivingComponent * LivingComponent::getComponent()
{
	return &comp;
}

bool LivingComponent::update(float dt)
{
	return false;
}
