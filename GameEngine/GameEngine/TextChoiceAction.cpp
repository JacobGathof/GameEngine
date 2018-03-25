#include "TextChoiceAction.h"
#include "UIManager.h"

TextChoiceAction::TextChoiceAction(List<std::string> ch)
{
	choices = ch;
}

TextChoiceAction::~TextChoiceAction()
{
}

int TextChoiceAction::run(float dt)
{
	if (!sentChoice) {
		UIManager::addChoice(choices);
		sentChoice = true;
	}
	return UIManager::isTextboxEmpty();
}

void TextChoiceAction::reset()
{
	sentChoice = false;
}
