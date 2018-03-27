#include "AbstractUIComponent.h"



AbstractUIComponent::AbstractUIComponent(){}

AbstractUIComponent::~AbstractUIComponent(){}

void AbstractUIComponent::update(float dt){}

void AbstractUIComponent::setParentPosition(Vector2f * pos)
{
	parentOffset = pos;
}

bool AbstractUIComponent::mouseIn(Mouse & mouse)
{
	return mouse.pos().between(position, position + scale);
}

void AbstractUIComponent::resize(int newX, int newY)
{
}
