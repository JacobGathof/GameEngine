#include "AbstractUIComponent.h"



AbstractUIComponent::AbstractUIComponent(){}

AbstractUIComponent::~AbstractUIComponent(){}


void AbstractUIComponent::hover(Vector2f & pos){}

void AbstractUIComponent::click(Vector2f & pos){}

void AbstractUIComponent::release(Vector2f & pos){}

void AbstractUIComponent::move(Vector2f & pos){}

void AbstractUIComponent::update(float dt){}

void AbstractUIComponent::draw(){}

void AbstractUIComponent::setParentPosition(Vector2f * pos)
{
	parentOffset = pos;
}
