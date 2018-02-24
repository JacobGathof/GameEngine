#include "TextChoiceAction.h"



TextChoiceAction::TextChoiceAction(std::string * ch, int len)
{
	choices = ch;
	length = len;
}

TextChoiceAction::~TextChoiceAction()
{
}

int TextChoiceAction::run(float dt)
{
	if (!sentChoice) {
		UIManager::addChoice(choices, length);
		sentChoice = true;
	}
	return UIManager::isTextboxEmpty();
}
