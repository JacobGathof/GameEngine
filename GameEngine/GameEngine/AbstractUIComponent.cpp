#include "AbstractUIComponent.h"



AbstractUIComponent::AbstractUIComponent(){}

AbstractUIComponent::~AbstractUIComponent(){}

void AbstractUIComponent::update(float dt){}

void AbstractUIComponent::setParentPosition(Vector2f * pos)
{
	parentOffset = pos;
}
