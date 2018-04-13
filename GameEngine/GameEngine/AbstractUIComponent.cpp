#include "AbstractUIComponent.h"



AbstractUIComponent::AbstractUIComponent(){}

AbstractUIComponent::~AbstractUIComponent(){}

void AbstractUIComponent::handleMouseEvents(Mouse & mouse)
{
}

void AbstractUIComponent::handleKeyEvents(Keyboard & keyboard)
{
}

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

void AbstractUIComponent::setVisible(bool b)
{
	visible = b;
}
