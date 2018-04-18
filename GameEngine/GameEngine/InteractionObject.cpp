#include "InteractionObject.h"


TextInteractionObject::TextInteractionObject(std::string s) {
	text = s;
}

TextInteractionObject::~TextInteractionObject()
{
}

int TextInteractionObject::run(float dt)
{
	UIManager::addText(text);
	return 1;
}

