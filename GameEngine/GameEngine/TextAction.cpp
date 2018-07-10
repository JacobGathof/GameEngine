#include "TextAction.h"
#include "UIManager.h"

TextAction::TextAction(TextboxContentData& d)
{
	data = d;
}

TextAction::~TextAction(){}


int TextAction::run(float dt)
{
	UIManager::addText(data);
	return true;
}
