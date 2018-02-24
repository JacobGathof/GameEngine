#include "TextAction.h"


TextAction::TextAction(std::string & txt)
{
	text = txt;
}

TextAction::~TextAction(){}


int TextAction::run(float dt)
{
	UIManager::addText(text);
	return 1;
}
