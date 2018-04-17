#include "InteractionObject.h"



InteractionObject::InteractionObject()
{
}


InteractionObject::~InteractionObject()
{
}

void InteractionObject::execute()
{
}


TextInteractionObject::TextInteractionObject(std::string s) {
	text = s;
}

TextInteractionObject::~TextInteractionObject()
{
}

void TextInteractionObject::execute()
{
	std::cout << text << std::endl;
	UIManager::addText(text);
}

