#include "TextAction.h"


TextAction::TextAction(std::string & txt, bool block)
{
	text = txt;
	blocking = block;
}

TextAction::~TextAction(){}


int TextAction::run(float dt)
{
	if (!sent) {
		sent = true;
		UIManager::addText(text);
	}
	return !blocking | UIManager::isTextboxEmpty();
}
