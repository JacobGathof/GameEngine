#include "TextboxWaitAction.h"
#include "UIManager.h"


TextboxWaitAction::TextboxWaitAction()
{
}


TextboxWaitAction::~TextboxWaitAction()
{
}

int TextboxWaitAction::run(float dt)
{
	return UIManager::isTextboxEmpty();
}
